#include "psdfileex.h"

#define BMPEXT L".bmp"

/**
 * C文字列処理用
 */
class NarrowString {
private:
	tjs_nchar *_data;
public:
	NarrowString(const ttstr &str) : _data(NULL) {
		tjs_int len = str.GetNarrowStrLen();
		if (len > 0) {
			_data = new tjs_nchar[len+1];
			str.ToNarrowStr(_data, len+1);
		}
	}
	~NarrowString() {
		delete[] _data;
	}

	const tjs_nchar *data() {
		return _data;
	}

	operator const char *() const
	{
		return (const char *)_data;
	}
};

// ncb.typeconv: cast: enum->int
NCB_TYPECONV_CAST_INTEGER(psd::LayerType);
NCB_TYPECONV_CAST_INTEGER(psd::BlendMode);

static int convBlendMode(psd::BlendMode mode)
{
	switch (mode) {
	case psd::BLEND_MODE_NORMAL:			// 'norm' = normal
		return ltPsNormal;
	case psd::BLEND_MODE_DARKEN:			// 'dark' = darken
		return ltPsDarken;
	case psd::BLEND_MODE_MULTIPLY:		// 'mul ' = multiply
		return ltPsMultiplicative;
	case psd::BLEND_MODE_COLOR_BURN:		// 'idiv' = color burn
		return ltPsColorBurn;
	case psd::BLEND_MODE_LINEAR_BURN:		// 'lbrn' = linear burn
		return ltPsSubtractive;
	case psd::BLEND_MODE_LIGHTEN:			// 'lite' = lighten
		return ltPsLighten;
	case psd::BLEND_MODE_SCREEN:			// 'scrn' = screen
		return ltPsScreen;
	case psd::BLEND_MODE_COLOR_DODGE:		// 'div ' = color dodge
		return ltPsColorDodge;
	case psd::BLEND_MODE_LINEAR_DODGE:	// 'lddg' = linear dodge
		return ltPsAdditive;
	case psd::BLEND_MODE_OVERLAY:			// 'over' = overlay
		return ltPsOverlay;
	case psd::BLEND_MODE_SOFT_LIGHT:		// 'sLit' = soft light
		return ltPsSoftLight;
	case psd::BLEND_MODE_HARD_LIGHT:		// 'hLit' = hard light
		return ltPsHardLight;
	case psd::BLEND_MODE_DIFFERENCE:		// 'diff' = difference
		return ltPsDifference;
	case psd::BLEND_MODE_EXCLUSION:		// 'smud' = exclusion
		return ltPsExclusion;
	case psd::BLEND_MODE_DISSOLVE:		// 'diss' = dissolve
	case psd::BLEND_MODE_VIVID_LIGHT:		// 'vLit' = vivid light
	case psd::BLEND_MODE_LINEAR_LIGHT:	// 'lLit' = linear light
	case psd::BLEND_MODE_PIN_LIGHT:		// 'pLit' = pin light
	case psd::BLEND_MODE_HARD_MIX:		// 'hMix' = hard mix
  case psd::BLEND_MODE_DARKER_COLOR:
  case psd::BLEND_MODE_LIGHTER_COLOR:
  case psd::BLEND_MODE_SUBTRACT:
  case psd::BLEND_MODE_DIVIDE:
		// not supported;
		break;
	}
	return ltPsNormal;
}

class PSDStorage;

class PSD {

friend class PSDStorage;
	
protected:
	iTJSDispatch2 *objthis; ///< 自己オブジェクト情報の参照
	ttstr dname; ///< 登録用ベース名

	PSDFileEx psdFile;	// PSD データ
	HGLOBAL hBuffer; // オンメモリ保持用ハンドル

public:
	/**
	 * コンストラクタ
	 */
	PSD(iTJSDispatch2 *objthis) : objthis(objthis), hBuffer(0), storageStarted(false) {
	};

	/**
	 * デストラクタ
	 */
	~PSD() {
		clearData();
	};

	/**
	 * インスタンス生成ファクトリ
	 */
	static tjs_error factory(PSD **result, tjs_int numparams, tTJSVariant **params, iTJSDispatch2 *objthis) {
		*result = new PSD(objthis);
		return S_OK;
	}

	/**
	 * 生成時の自己オブジェクトを取得
	 */
	tTJSVariant getSelf() {
		return tTJSVariant(objthis, objthis);
	}
	
	/**
	 * PSD画像のロード
	 * @param filename ファイル名
	 * @return ロードに成功したら true
	 */
	bool load(ttstr filename) {
		clearData();
		
		ttstr file = TVPGetPlacedPath(filename);
		if (!file.length()) {
			psdFile.load(NarrowString(filename));
		} else {
			if (!wcschr(file.c_str(), '>')) {
				// ローカルファイルなので直接読み込む
				TVPGetLocalName(file);
				psdFile.load(NarrowString(file));
			} else {
				// アーカイブ内部
				IStream *stream = TVPCreateIStream(file, TJS_BS_READ);
				if (stream) {
					try {
						// 全部メモリに読み込む
						STATSTG stat;
						stream->Stat(&stat, STATFLAG_NONAME);
						tjs_uint64 qsize = (tjs_uint64)stat.cbSize.QuadPart;
						if (qsize < 0xFFFFFFFF) {
							DWORD size = (DWORD)qsize;
							hBuffer = ::GlobalAlloc(GMEM_MOVEABLE, size);
							unsigned char* pBuffer = (unsigned char*)::GlobalLock(hBuffer);
							if (pBuffer) {
								ULONG retsize;
								stream->Read(pBuffer, size, &retsize);
								if (!psdFile.loadMemory(pBuffer, pBuffer + size)) {
									::GlobalUnlock(hBuffer);
									::GlobalFree(hBuffer);
									hBuffer = 0;
								}
							}
						}
					} catch(...) {
						if (hBuffer) {
							::GlobalUnlock(hBuffer);
							::GlobalFree(hBuffer);
							hBuffer = 0;
						}
						stream->Release();
						throw;
					}
					stream->Release();
				} else {
					TVPThrowExceptionMessage(L"psd:failed to open file");
					return false;
				}
      }
		}
		if (psdFile.isLoaded) {
			addToStorage(filename);
		}
		return psdFile.isLoaded;
	}

	static void clearStorageCache();
	
#define INTGETTER(tag) int get_ ## tag(){ return psdFile.isLoaded ? psdFile.header.tag : -1; }

	INTGETTER(width);
	INTGETTER(height);
	INTGETTER(channels);
	INTGETTER(depth);
  int get_color_mode()  { return psdFile.isLoaded ? psdFile.header.mode : -1; }
  int get_layer_count() { return psdFile.isLoaded ? (int)psdFile.layerList.size() : -1; }

protected:

	void clearData() {
		removeFromStorage();
		if (hBuffer) {
			::GlobalUnlock(hBuffer);
			::GlobalFree(hBuffer);
			hBuffer = 0;
		}
		layerIdIdxMap.clear();
		pathMap.clear();
		storageStarted = false;
	}
	
	/**
	 * レイヤ番号が適切かどうか判定
	 * @param no レイヤ番号
	 */
	void checkLayerNo(int no) {
		if (!psdFile.isLoaded) {
			TVPThrowExceptionMessage(L"no data");
		}
		if (no < 0 || no >= get_layer_count()) {
			TVPThrowExceptionMessage(L"not such layer");
		}
	}

	/**
	 * 名前の取得
	 * @param name 名前文字列（ユニコード)
	 * @len 長さ
	 */
  ttstr layname(psd::LayerInfo &lay) {
		ttstr ret;
		if (!lay.layerNameUnicode.empty()) {
			ret = ttstr(lay.layerNameUnicode.c_str()); 
		} else {
			ret = ttstr(lay.layerName.c_str());
		}
		return ret;
	}

public:
	/**
	 * レイヤ種別の取得
	 * @param no レイヤ番号
	 * @return レイヤ種別
	 */
	int getLayerType(int no) {
		checkLayerNo(no);
    return (int)psdFile.layerList[no].layerType;
	}

	/**
	 * レイヤ名称の取得
	 * @param no レイヤ番号
	 * @return レイヤ種別
	 */
	ttstr getLayerName(int no) {
		checkLayerNo(no);
    return layname(psdFile.layerList[no]);
	}

	/**
	 * レイヤ情報の取得
	 * @param no レイヤ番号
	 * @return レイヤ情報が格納された辞書
	 */
	tTJSVariant getLayerInfo(int no) {
		checkLayerNo(no);
    psd::LayerInfo &lay = psdFile.layerList[no];
		tTJSVariant result;	
		ncbDictionaryAccessor dict;
		if (dict.IsValid()) {
#define SETPROP(dict, obj, prop) dict.SetValue(L ## #prop, obj.prop)
			SETPROP(dict, lay, top);
			SETPROP(dict, lay, left);
			SETPROP(dict, lay, bottom);
			SETPROP(dict, lay, right);
			SETPROP(dict, lay, width);
			SETPROP(dict, lay, height);
			SETPROP(dict, lay, opacity);
            bool mask = false;
            for (std::vector<psd::ChannelInfo>::iterator i = lay.channels.begin();
                 i != lay.channels.end();
                 i++) {
              if (i->isMaskChannel()) {
                mask = true;
                break;
              }
            }
            dict.SetValue(L"mask", mask);
      dict.SetValue(L"type",       convBlendMode(lay.blendMode));
      dict.SetValue(L"layer_type", lay.layerType);
      dict.SetValue(L"blend_mode", lay.blendMode);
      dict.SetValue(L"visible",    lay.isVisible());
			dict.SetValue(L"name",       layname(lay));

			// additional information
			SETPROP(dict, lay, clipping);
      dict.SetValue(L"layer_id", lay.layerId);
      dict.SetValue(L"obsolete", lay.isObsolete());
      dict.SetValue(L"transparency_protected", lay.isTransparencyProtected());
      dict.SetValue(L"pixel_data_irrelevant",  lay.isPixelDataIrrelevant());

      // レイヤーカンプ
      if (lay.layerComps.size() > 0) {
        ncbDictionaryAccessor compDict;
        if (compDict.IsValid()) {
          for (std::map<int, psd::LayerCompInfo>::iterator it = lay.layerComps.begin();
               it != lay.layerComps.end(); it++)	{
            ncbDictionaryAccessor tmp;
            if (tmp.IsValid()) {
              psd::LayerCompInfo &comp = it->second;
              tmp.SetValue(L"id",         comp.id);
              tmp.SetValue(L"offset_x",   comp.offsetX);
              tmp.SetValue(L"offset_y",   comp.offsetY);
              tmp.SetValue(L"enable",     comp.isEnabled);
              compDict.SetValue((tjs_int32)comp.id, tmp.GetDispatch());
            }
          }
          dict.SetValue(L"layer_comp", compDict.GetDispatch());
        }
      }
      
      // SETPROP(dict, lay, adjustment_valid); // 調整レイヤーかどうか？レイヤタイプで判別可能
      // SETPROP(dict, lay, fill_opacity);
      // SETPROP(dict, lay, layer_name_id);
      // SETPROP(dict, lay, layer_version);
      // SETPROP(dict, lay, blend_clipped);
      // SETPROP(dict, lay, blend_interior);
      // SETPROP(dict, lay, knockout);
      // SETPROP(dict, lay, transparency); // lspf(protection)のもの
      // SETPROP(dict, lay, composite);
      // SETPROP(dict, lay, position_respectively);
      // SETPROP(dict, lay, sheet_color);
      // SETPROP(dict, lay, reference_point_x); // 塗りつぶしレイヤ（パターン）のオフセット
      // SETPROP(dict, lay, reference_point_y); // 塗りつぶしレイヤ（パターン）のオフセット
      // SETPROP(dict, lay, transparency_shapes_layer);
      // SETPROP(dict, lay, layer_mask_hides_effects);
      // SETPROP(dict, lay, vector_mask_hides_effects);
      // SETPROP(dict, lay, divider_type);
      // SETPROP(dict, lay, divider_blend_mode);

			// group layer はスクリプト側では layer_id 参照で引くようにする
			if (lay.parent != NULL)
				dict.SetValue(L"group_layer_id", lay.parent->layerId);

			result = dict;
		}

		return result;
	}

	/**
	 * レイヤデータの読み出し(内部処理)
	 * @param layer 読み出し先レイヤ
	 * @param no レイヤ番号
     * @param imageMode イメージモード
	 */
  void _getLayerData(tTJSVariant layer, int no, psd::ImageMode imageMode) {
		if (!layer.AsObjectNoAddRef()->IsInstanceOf(0, 0, 0, L"Layer", NULL)) {
			TVPThrowExceptionMessage(L"not layer");
		}
		checkLayerNo(no);

        psd::LayerInfo &lay = psdFile.layerList[no];
        psd::LayerMask &mask  = lay.extraData.layerMask;

        if (lay.layerType != psd::LAYER_TYPE_NORMAL
            && ! (lay.layerType == psd::LAYER_TYPE_FOLDER 
                  && imageMode == psd::IMAGE_MODE_MASK)) {
          TVPThrowExceptionMessage(L"invalid layer type");
        }

        int left, top, width, height, opacity, type;

        bool dummyMask = false;
        if (imageMode == psd::IMAGE_MODE_MASK) {
          left = mask.left;
          top = mask.top;
          width = mask.width;
          height = mask.height;
          opacity = 255;
          type = ltPsNormal;
          if (width == 0 || height == 0) {
            left = top = 0;
            width = height = 1;
            dummyMask = true;
          }
        } else {
          left = lay.left;
          top = lay.top;
          width = lay.width;
          height = lay.height;
          opacity = lay.opacity;
          type = convBlendMode(lay.blendMode);
        }
        if (width <= 0 || height <= 0) {
          // サイズ０のレイヤはロードできない
          return;
        }

		ncbPropAccessor obj(layer);
        obj.SetValue(L"left", left);
        obj.SetValue(L"top", top);
        obj.SetValue(L"opacity", opacity);
		obj.SetValue(L"width",  width);
		obj.SetValue(L"height", height);
		obj.SetValue(L"type",   type);
        obj.SetValue(L"visible", lay.isVisible());
		obj.SetValue(L"imageLeft",  0);
		obj.SetValue(L"imageTop",   0);
		obj.SetValue(L"imageWidth",  width);
		obj.SetValue(L"imageHeight", height);
		obj.SetValue(L"name", layname(lay));

        if (imageMode == psd::IMAGE_MODE_MASK)
          obj.SetValue(L"defaultMaskColor", mask.defaultColor);

		// 画像データのコピー
        unsigned char *buffer = (unsigned char*)obj.GetValue(L"mainImageBufferForWrite", ncbTypedefs::Tag<tjs_int>());
        int pitch = obj.GetValue(L"mainImageBufferPitch", ncbTypedefs::Tag<tjs_int>());
        if (dummyMask) {
          buffer[0] = buffer[1] = buffer[2] = mask.defaultColor;
          buffer[3] = 255;
        } else {
          psdFile.getLayerImage(lay, buffer, psd::BGRA_LE, pitch, imageMode);
        }

	}


	/**
	 * レイヤデータの読み出し
	 * @param layer 読み出し先レイヤ
	 * @param no レイヤ番号
	 */
	void getLayerData(tTJSVariant layer, int no) {
      _getLayerData(layer, no, psd::IMAGE_MODE_MASKEDIMAGE);
	}

	/**
	 * レイヤデータの読み出し(生イメージ)
	 * @param layer 読み出し先レイヤ
	 * @param no レイヤ番号
	 */
	void getLayerDataRaw(tTJSVariant layer, int no) {
      _getLayerData(layer, no, psd::IMAGE_MODE_IMAGE);
	}

	/**
	 * レイヤデータの読み出し(マスクのみ)
	 * @param layer 読み出し先レイヤ
	 * @param no レイヤ番号
	 */
	void getLayerDataMask(tTJSVariant layer, int no) {
      _getLayerData(layer, no, psd::IMAGE_MODE_MASK);
	}

	/**
	 * スライスデータの読み出し
	 * @return スライス情報辞書 %[ top, left, bottom, right, slices:[ %[ id, group_id, left, top, bottom, right ], ... ] ]
	 *         スライス情報がない場合は void を返す
	 */
	tTJSVariant getSlices() {
		if (!psdFile.isLoaded) TVPThrowExceptionMessage(L"no data");
		tTJSVariant result;	
		ncbDictionaryAccessor dict;
		ncbArrayAccessor arr;
    if (psdFile.slice.isEnabled) {
			if (dict.IsValid()) {
        psd::SliceResource &sr = psdFile.slice;
				dict.SetValue(L"top",    sr.boundingTop);
				dict.SetValue(L"left",   sr.boundingLeft);
				dict.SetValue(L"bottom", sr.boundingBottom);
				dict.SetValue(L"right",  sr.boundingRight);
				dict.SetValue(L"name",   ttstr(sr.groupName.c_str()));
				if (arr.IsValid()) {
					for (int i = 0; i < (int)sr.slices.size(); i++) {
						ncbDictionaryAccessor tmp;
						if (tmp.IsValid()) {
              psd::SliceItem &item = sr.slices[i];
              tmp.SetValue(L"id",      	item.id);
              tmp.SetValue(L"group_id", item.groupId);
              tmp.SetValue(L"origin",   item.origin);
              tmp.SetValue(L"type",     item.type);
              tmp.SetValue(L"left",     item.left);
              tmp.SetValue(L"top",      item.top);
              tmp.SetValue(L"right",    item.right);
              tmp.SetValue(L"bottom",   item.bottom);
              tmp.SetValue(L"color",    ((item.colorA<<24) | (item.colorR<<16) | (item.colorG<<8) | item.colorB));
              tmp.SetValue(L"cell_text_is_html",    item.isCellTextHtml);
              tmp.SetValue(L"horizontal_alignment", item.horizontalAlign);
              tmp.SetValue(L"vertical_alignment",   item.verticalAlign);
              tmp.SetValue(L"associated_layer_id",	item.associatedLayerId);
              tmp.SetValue(L"name",      ttstr(item.name.c_str()));
              tmp.SetValue(L"url",       ttstr(item.url.c_str()));
              tmp.SetValue(L"target",    ttstr(item.target.c_str()));
              tmp.SetValue(L"message",   ttstr(item.message.c_str()));
              tmp.SetValue(L"alt_tag",   ttstr(item.altTag.c_str()));
              tmp.SetValue(L"cell_text", ttstr(item.cellText.c_str()));
              arr.SetValue((tjs_int32)i, tmp.GetDispatch());
						}
					}
					dict.SetValue(L"slices", arr.GetDispatch());
				}
				result = dict;
			}
		}
		return result;
	}

	/**
	 * ガイドデータの読み出し
	 * @return ガイド情報辞書 %[ vertical:[ x1, x2, ... ], horizontal:[ y1, y2, ... ] ]
	 *         ガイド情報がない場合は void を返す
	 */
	tTJSVariant getGuides() {
		if (!psdFile.isLoaded) TVPThrowExceptionMessage(L"no data");
		tTJSVariant result;	
		ncbDictionaryAccessor dict;
		ncbArrayAccessor vert, horz;
    if (psdFile.gridGuide.isEnabled) {
      psd::GridGuideResource gg = psdFile.gridGuide;
			if (dict.IsValid() && vert.IsValid() && horz.IsValid()) {
				dict.SetValue(L"horz_grid",  gg.horizontalGrid);
				dict.SetValue(L"vert_grid",  gg.verticalGrid);
				dict.SetValue(L"vertical",   vert.GetDispatch());
				dict.SetValue(L"horizontal", horz.GetDispatch());
				for (int i = 0, v = 0, h = 0; i < (int)gg.guides.size(); i++) {
					if (gg.guides[i].direction == 0) {
						vert.SetValue(v++, gg.guides[i].location);
					} else {
						horz.SetValue(h++, gg.guides[i].location);
					}
				}
				result = dict;
			}
		}
		return result;
	}

	/**
	 * 合成結果の取得。取得領域は画像全体サイズ内におさまってる必要があります
   * 注意：PSDファイル自体に合成済み画像が存在しない場合は取得に失敗します
   *
	 * @param layer 格納先レイヤ(width,heightサイズに調整される)
	 * @return 取得に成功したら true
	 */
  bool getBlend(tTJSVariant layer) {
		if (!layer.AsObjectNoAddRef()->IsInstanceOf(0, 0, 0, L"Layer", NULL)) {
			TVPThrowExceptionMessage(L"not layer");
		}

		// 合成結果を生成
    if (psdFile.imageData) {

			// 格納先を調整
			ncbPropAccessor obj(layer);
			obj.SetValue(L"width",  get_width());
			obj.SetValue(L"height", get_height());
			obj.SetValue(L"imageLeft",  0);
			obj.SetValue(L"imageTop",   0);
			obj.SetValue(L"imageWidth",  get_width());
			obj.SetValue(L"imageHeight", get_height());

      // 画像データのコピー
      unsigned char *buffer = (unsigned char*)obj.GetValue(L"mainImageBufferForWrite", ncbTypedefs::Tag<tjs_int>());
      int pitch = obj.GetValue(L"mainImageBufferPitch", ncbTypedefs::Tag<tjs_int>());
      psdFile.getMergedImage(buffer, psd::BGRA_LE, pitch);

			return true;
		}

		return false;
	}

	/**
	 * レイヤーカンプ
	 */
	tTJSVariant getLayerComp() {
		if (!psdFile.isLoaded) TVPThrowExceptionMessage(L"no data");
		tTJSVariant result;
    ncbDictionaryAccessor dict;
		ncbArrayAccessor arr;
    int compNum = psdFile.layerComps.size();
    if (compNum > 0) {
      if (dict.IsValid()) {
        dict.SetValue(L"last_applied_id", psdFile.lastAppliedCompId);
        if (arr.IsValid()) {
          for (int i = 0; i < compNum; i++) {
            ncbDictionaryAccessor tmp;
            if (tmp.IsValid()) {
              psd::LayerComp &comp = psdFile.layerComps[i];
              tmp.SetValue(L"id",      	        comp.id);
              tmp.SetValue(L"record_visibility", comp.isRecordVisibility);
              tmp.SetValue(L"record_position",   comp.isRecordPosition);
              tmp.SetValue(L"record_appearance", comp.isRecordAppearance);
              tmp.SetValue(L"name",             ttstr(comp.name.c_str()));
              tmp.SetValue(L"comment",          ttstr(comp.comment.c_str()));
              arr.SetValue((tjs_int32)i,        tmp.GetDispatch());
            }
          }
          dict.SetValue(L"comps", arr.GetDispatch());
        }
        result = dict;
      }
    }
		return result;
	}

	// ------------------------------------------------------------
	// ストレージレイヤ参照用インターフェース
	// ------------------------------------------------------------
	
protected:

	// ストレージ情報登録
	void addToStorage(const ttstr &filename);
	void removeFromStorage();

	bool storageStarted; //< ストレージ用の情報初期化済みフラグ

	// レイヤ名を返す
	ttstr path_layname(psd::LayerInfo &lay) {
		ttstr ret = layname(lay);
		// 正規化
		ttstr from = "/";
		ttstr to   = "_";
		ret.Replace(from, to, true);
		ret.ToLowerCase();
		return ret;
	}

	// レイヤのパス名を返す
	ttstr pathname(psd::LayerInfo &lay) {
		ttstr name = "";
		psd::LayerInfo *p = lay.parent;
		while (p) {
			name = path_layname(*p) + "/" + name;
			p = p->parent;
		}
		return ttstr("root/") + name;
	}

	// ストレージ処理用データの初期化
	void startStorage() {
		if (!storageStarted) {
			storageStarted = true;
			// レイヤ検索用の情報を生成
			int count = (int)psdFile.layerList.size();
			for (int i=count-1;i>=0;i--) {
				psd::LayerInfo &lay = psdFile.layerList[i];
				if (lay.layerType == psd::LAYER_TYPE_NORMAL) {
					pathMap[pathname(lay)][path_layname(lay)] = i;
					layerIdIdxMap[lay.layerId] = i;
				}
			}
		}
	}

	bool checkAllNum(const tjs_char *p) {
		while (*p != '\0') {
			if (!(*p >= '0' && *p <= '9')) {
				return false;
			}
			p++;
		}
		return true;
	}
	
	/*
	 * 指定した名前のレイヤの存在チェック
	 * @param name パスを含むレイヤ名
	 * @param layerIdxRet レイヤインデックス番号を返す
	 */
	bool CheckExistentStorage(const ttstr &filename, int *layerIdxRet=0) {
		startStorage();

		// ルート部を取得
		const tjs_char *p = filename.c_str();

		// id指定の場合
		if (wcsncmp(p, L"id/", 3) == 0) {

			p += 3;

			// 拡張子を除去して判定
			const tjs_char *q;
			if (!(q = wcsrchr(p, '/')) && ((q = wcschr(p, '.')) && (wcscmp(q, BMPEXT) == 0))) {
				ttstr name = ttstr(p, q-p);
				q = name.c_str();
				if (checkAllNum(q)) { // 文字混入禁止
					int id = _wtoi(q);
					LayerIdIdxMap::const_iterator n = layerIdIdxMap.find(id);
					if (n != layerIdIdxMap.end()) {
						if (layerIdxRet) *layerIdxRet = n->second;
						return true;
					}
				}
			}

		} else {

			// パスを分離
			ttstr pname, fname;
			// 最後の/を探す
			const tjs_char *q;
			if ((q = wcsrchr(p, '/'))) {
				pname = ttstr(p, q-p+1);
				fname = ttstr(q+1);
			} else {
				return false;
			}
			
			// 拡張子分離
			ttstr basename;
			p = fname.c_str();
			// 最初の . を探す
			if ((q = wcschr(p, '.')) && (wcscmp(q, BMPEXT) == 0)) {
				basename = ttstr(p, q-p);
			} else {
				return false;
			}

			// 名前を探す
			PathMap::const_iterator n = pathMap.find(pname);
			if (n != pathMap.end()) {
				const NameIdxMap &names = n->second;
				NameIdxMap::const_iterator m = names.find(basename);
				if (m != names.end()) {
					if (layerIdxRet) *layerIdxRet = m->second;
					return true;
				}
			}
		}
		
		return false;
	}

	/*
	 * 指定したパスにあるファイル名一覧の取得
	 * @param pathname パス名
	 * @param lister リスト取得用インターフェース
	 */
	void GetListAt(const ttstr &pathname, iTVPStorageLister *lister) {
		startStorage();

		// ID一覧から名前を生成
		if (pathname == "id/") {
			LayerIdIdxMap::const_iterator it = layerIdIdxMap.begin();
			while (it != layerIdIdxMap.end()) {
				ttstr name = ttstr(it->first);
				lister->Add(name + BMPEXT);
				it++;
			}
			return;
		}

		// パス登録情報から名前を生成
		PathMap::const_iterator n = pathMap.find(pathname);
		if (n != pathMap.end()) {
			const NameIdxMap &names = n->second;
			NameIdxMap::const_iterator it = names.begin();
			while (it != names.end()) {
				ttstr name = it->first;
				lister->Add(name + BMPEXT);
				it++;
			}
		}
	}

	/*
	 * 指定した名前のレイヤの画像ファイルをストリームで返す
	 * @param name パスを含むレイヤ名
	 * @return ファイルストリーム
	 */
	IStream *openLayerImage(const ttstr &name) {

		static int n=0;

		int layerIdx;
		if (CheckExistentStorage(name, &layerIdx)) {
			if (layerIdx < (int)psdFile.layerList.size()) {
				psd::LayerInfo &lay = psdFile.layerList[layerIdx];

				if (lay.layerType != psd::LAYER_TYPE_NORMAL || lay.width <= 0 || lay.height <= 0) {
					return 0;
        }
				int width  = lay.width;
				int height = lay.height;
				int pitch  = width*4;

				int hsize = sizeof(BITMAPFILEHEADER);
				int isize = hsize + sizeof(BITMAPINFOHEADER);
				int size  = isize  + pitch * height;
				
				// グローバルヒープにBMP画像を作成してストリームとして返す
				HGLOBAL handle = ::GlobalAlloc(GMEM_MOVEABLE, size);
				if (handle) {
					unsigned char *p = (unsigned char*)::GlobalLock(handle);
					if (p) {

						BITMAPFILEHEADER bfh;
						bfh.bfType      = 'B' + ('M' << 8);
						bfh.bfSize      = size;
						bfh.bfReserved1 = 0;
						bfh.bfReserved2 = 0;
						bfh.bfOffBits   = isize;
						memcpy(p,        &bfh, sizeof bfh);

						BITMAPINFOHEADER bih;
						bih.biSize = sizeof(bih);
						bih.biWidth = width;
						bih.biHeight = height;
						bih.biPlanes = 1;
						bih.biBitCount = 32;
						bih.biCompression = BI_RGB;
						bih.biSizeImage = 0;
						bih.biXPelsPerMeter = 0;
						bih.biYPelsPerMeter = 0;
						bih.biClrUsed = 0;
						bih.biClrImportant = 0;
						memcpy(p + hsize, &bih, sizeof bih);
						psdFile.getLayerImage(lay, p + isize + pitch * (height - 1), psd::BGRA_LE, -pitch, psd::IMAGE_MODE_MASKEDIMAGE);
						::GlobalUnlock(handle);
						
						IStream *pStream = 0;
						if (SUCCEEDED(::CreateStreamOnHGlobal(handle, TRUE, &pStream))) {
							return pStream;
						}
					}
					::GlobalFree(handle);
				}
			}
		}
		return 0;
	}
	
	// パス名記録用

	typedef std::map<int,int> LayerIdIdxMap; // layerId とレイヤ情報インデックスのマップ
	LayerIdIdxMap layerIdIdxMap;

	typedef std::map<ttstr,int> NameIdxMap;     //< レイヤ名とlayerId のマップ
	typedef std::map<ttstr,NameIdxMap> PathMap; //< パス別のレイヤ名一覧
	PathMap pathMap;
};

NCB_REGISTER_CLASS(PSD) {

	Factory(&ClassT::factory);

	Variant("color_mode_bitmap",              (int)psd::COLOR_MODE_BITMAP);
  Variant("color_mode_grayscale",           (int)psd::COLOR_MODE_GRAYSCALE);
  Variant("color_mode_indexed",             (int)psd::COLOR_MODE_INDEXED);
  Variant("color_mode_rgb",                 (int)psd::COLOR_MODE_RGB);
  Variant("color_mode_cmyk",                (int)psd::COLOR_MODE_CMYK);
  Variant("color_mode_multichannel",        (int)psd::COLOR_MODE_MULTICHANNEL);
  Variant("color_mode_duotone",             (int)psd::COLOR_MODE_DUOTONE);
  Variant("color_mode_lab",                 (int)psd::COLOR_MODE_LAB);
  
  Variant("blend_mode_normal",              (int)psd::BLEND_MODE_NORMAL);
  Variant("blend_mode_dissolve",            (int)psd::BLEND_MODE_DISSOLVE);
  Variant("blend_mode_darken",              (int)psd::BLEND_MODE_DARKEN);
  Variant("blend_mode_multiply",            (int)psd::BLEND_MODE_MULTIPLY);
  Variant("blend_mode_color_burn",          (int)psd::BLEND_MODE_COLOR_BURN);
  Variant("blend_mode_linear_burn",         (int)psd::BLEND_MODE_LINEAR_BURN);
  Variant("blend_mode_lighten",             (int)psd::BLEND_MODE_LIGHTEN);
  Variant("blend_mode_screen",              (int)psd::BLEND_MODE_SCREEN);
  Variant("blend_mode_color_dodge",         (int)psd::BLEND_MODE_COLOR_DODGE);
  Variant("blend_mode_linear_dodge",        (int)psd::BLEND_MODE_LINEAR_DODGE);
  Variant("blend_mode_overlay",             (int)psd::BLEND_MODE_OVERLAY);
  Variant("blend_mode_soft_light",          (int)psd::BLEND_MODE_SOFT_LIGHT);
  Variant("blend_mode_hard_light",          (int)psd::BLEND_MODE_HARD_LIGHT);
  Variant("blend_mode_vivid_light",         (int)psd::BLEND_MODE_VIVID_LIGHT);
  Variant("blend_mode_linear_light",        (int)psd::BLEND_MODE_LINEAR_LIGHT);
  Variant("blend_mode_pin_light",           (int)psd::BLEND_MODE_PIN_LIGHT);
  Variant("blend_mode_hard_mix",            (int)psd::BLEND_MODE_HARD_MIX);
  Variant("blend_mode_difference",          (int)psd::BLEND_MODE_DIFFERENCE);
  Variant("blend_mode_exclusion",           (int)psd::BLEND_MODE_EXCLUSION);
  Variant("blend_mode_hue",                 (int)psd::BLEND_MODE_HUE);
  Variant("blend_mode_saturation",          (int)psd::BLEND_MODE_SATURATION);
  Variant("blend_mode_color",               (int)psd::BLEND_MODE_COLOR);
  Variant("blend_mode_luminosity",          (int)psd::BLEND_MODE_LUMINOSITY);
  Variant("blend_mode_pass_through",        (int)psd::BLEND_MODE_PASS_THROUGH);

  // NOTE libpsd 非互換モード
  Variant("blend_mode_darker_color",        (int)psd::BLEND_MODE_DARKER_COLOR);
  Variant("blend_mode_lighter_color",       (int)psd::BLEND_MODE_LIGHTER_COLOR);
  Variant("blend_mode_subtract",            (int)psd::BLEND_MODE_SUBTRACT);
  Variant("blend_mode_divide",              (int)psd::BLEND_MODE_DIVIDE);
  

  // NOTE この定数はlibpsd互換ではありません(folderまでは互換)
  Variant("layer_type_normal",              (int)psd::LAYER_TYPE_NORMAL);
  Variant("layer_type_hidden",              (int)psd::LAYER_TYPE_HIDDEN);
  Variant("layer_type_folder",              (int)psd::LAYER_TYPE_FOLDER);
  Variant("layer_type_adjust",              (int)psd::LAYER_TYPE_ADJUST);
  Variant("layer_type_fill",                (int)psd::LAYER_TYPE_FILL);

	NCB_METHOD(load);

#define INTPROP(name) Property(TJS_W(# name), &Class::get_ ## name, NULL)

	INTPROP(width);
	INTPROP(height);
	INTPROP(channels);
	INTPROP(depth);
	INTPROP(color_mode);
	INTPROP(layer_count);

	NCB_METHOD(getLayerType);
	NCB_METHOD(getLayerName);
	NCB_METHOD(getLayerInfo);
	NCB_METHOD(getLayerData);
	NCB_METHOD(getLayerDataRaw);
	NCB_METHOD(getLayerDataMask);

	NCB_METHOD(getSlices);
	NCB_METHOD(getGuides);
	NCB_METHOD(getBlend);
  NCB_METHOD(getLayerComp);

  NCB_METHOD(clearStorageCache);
};

// -----------------------------------------------------------------------------
// ストレージ機能
// -----------------------------------------------------------------------------

#define BASENAME L"psd"

/**
 * PSDストレージ
 */
class PSDStorage : public iTVPStorageMedia, tTVPCompactEventCallbackIntf
{
public:

	/**
	 * コンストラクタ
	 */
	PSDStorage() : refCount(1) {
	}

	/**
	 * デストラクタ
	 */
	virtual ~PSDStorage() {
	}

	/*
	 * PSDオブジェクト参照を追加
	 * @param filename 参照ファイル名
	 * @param psd PSDオブジェクト
	 */
	void add(ttstr filename, PSD *psd) {
		psdMap[filename] = psd;
	}
	
	/**
	 * PSDオブジェクト参照の消去要求
	 * @param psd PSDオブジェクト
	 */
	void remove(PSD *psd) {
		PSDMap::iterator it = psdMap.begin();
		while (it != psdMap.end()) {
			if (it->second == psd) {
				it = psdMap.erase(it);
			} else {
				it++;
			}
		}
	}

	/**
	 * キャッシュ情報をクリアする
	 */
	void clearCache() {
		cache.Clear();
	}

public:
	// -----------------------------------
	// iTVPStorageMedia Intefaces
	// -----------------------------------

	virtual void TJS_INTF_METHOD AddRef() {
		refCount++;
	};

	virtual void TJS_INTF_METHOD Release() {
		if (refCount == 1) {
			delete this;
		} else {
			refCount--;
		}
	};

	// returns media name like "file", "http" etc.
	virtual void TJS_INTF_METHOD GetName(ttstr &name) {
		name = BASENAME;
	}

	//	virtual ttstr TJS_INTF_METHOD IsCaseSensitive() = 0;
	// returns whether this media is case sensitive or not

	// normalize domain name according with the media's rule
	virtual void TJS_INTF_METHOD NormalizeDomainName(ttstr &name) {
		// nothing to do
	}

	// normalize path name according with the media's rule
	virtual void TJS_INTF_METHOD NormalizePathName(ttstr &name) {
		// nothing to do
	}

	// check file existence
	virtual bool TJS_INTF_METHOD CheckExistentStorage(const ttstr &name) {
		ttstr fname;
		PSD *psd = getPSD(name, fname);
		if (psd) {
			bool ret = psd->CheckExistentStorage(fname);
			return ret;
		}
		return false;
	}

	// open a storage and return a tTJSBinaryStream instance.
	// name does not contain in-archive storage name but
	// is normalized.
	virtual tTJSBinaryStream * TJS_INTF_METHOD Open(const ttstr & name, tjs_uint32 flags) {
		if (flags == TJS_BS_READ) { // 読み込みのみ
			ttstr fname;
			PSD *psd = getPSD(name, fname);
			if (psd) {
				IStream *stream = psd->openLayerImage(fname);
				if (stream) {
					tTJSBinaryStream *ret = TVPCreateBinaryStreamAdapter(stream);
					stream->Release();
					return ret;
				}
			}
		}
		TVPThrowExceptionMessage(TJS_W("%1:cannot open psdfile"), name);
		return NULL;
	}

	// list files at given place
	virtual void TJS_INTF_METHOD GetListAt(const ttstr &name, iTVPStorageLister * lister) {
		ttstr fname;
		PSD *psd = getPSD(name, fname);
		if (psd) {
			psd->GetListAt(fname, lister);
		}
	}

	// basically the same as above,
	// check wether given name is easily accessible from local OS filesystem.
	// if true, returns local OS native name. otherwise returns an empty string.
	virtual void TJS_INTF_METHOD GetLocallyAccessibleName(ttstr &name) {
		name = "";
	}

public:
	// -----------------------------------
	// tTVPCompactEventCallbackIntf
	// -----------------------------------
	virtual void TJS_INTF_METHOD OnCompact(tjs_int level) {
		if (level > TVP_COMPACT_LEVEL_MINIMIZE) {
			clearCache();
		}
	}
	
protected:

	/*
	 * ファイル名に合致した PSD 情報を取得
	 * @param name ファイル名
	 * @param fname ファイル名を返す
	 * @return PSD情報
	 */
	PSD *getPSD(ttstr name, ttstr &fname) {
		// 小文字で正規化
		name.ToLowerCase();
		// ドメイン名とそれ以降を分離
		ttstr dname;
		const tjs_char *p = name.c_str();
		const tjs_char *q;
		if ((q = wcschr(p, '/'))) {
			dname = ttstr(p, q-p);
			fname = ttstr(q+1);
		} else {
			TVPThrowExceptionMessage(TJS_W("invalid path:%1"), name);
		}

		PSD *psd = 0;

		// 直近のキャッシュが合致する場合はそれを返す
		if (cache.Type() == tvtObject &&
				(psd = ncbInstanceAdaptor<PSD>::GetNativeInstance(cache.AsObjectNoAddRef())) &&
				psd->dname == dname) {
			return psd;
		}

		// PSDオブジェクトの弱参照から探す
		PSDMap::iterator it = psdMap.find(dname);
		if (it != psdMap.end()) {
			// 既存データがある
			cache = it->second->getSelf();
			return it->second;
		}

		// 自分でopenしてそのままキャッシュとして持つ
		TVPExecuteExpression(L"new PSD()", &cache);
		psd = ncbInstanceAdaptor<PSD>::GetNativeInstance(cache.AsObjectNoAddRef());
		if (psd) {
			if (psd->load(dname)) {
				return psd;
			} else {
				clearCache();
			}
		}

		return 0;
	}

private:
	tjs_uint refCount; //< リファレンスカウント

	// PSDオブジェクトのキャッシュ参照
	tTJSVariant cache;
	
	// PSDオブジェクトの弱参照
	typedef std::map<ttstr, PSD*> PSDMap;
	PSDMap psdMap;
};

static PSDStorage *psdStorage = 0;

// 弱参照追加
void
PSD::addToStorage(const ttstr &filename)
{
	// 登録用ベース名を生成
	const tjs_char *p = filename.c_str();
	const tjs_char *q;
	if ((q = wcsrchr(p, '/'))) {
		dname = ttstr(q+1);
	} else {
		dname = filename;
	}
	// 小文字で正規化
	dname.ToLowerCase();
	if (psdStorage != NULL) {
		psdStorage->add(dname, this);
	}
}

// 弱参照解除
void
PSD::removeFromStorage()
{
	if (psdStorage != NULL) {
		psdStorage->remove(this);
	}
}

void
PSD::clearStorageCache()
{
	if (psdStorage != NULL) {
		psdStorage->clearCache();
	}
}

// --------------------------------------------------------------------


void initStorage()
{
	if (psdStorage== NULL) {
		psdStorage = new PSDStorage();
		TVPRegisterStorageMedia(psdStorage);
	}
}

void doneStorage()
{
	if (psdStorage != NULL) {
		TVPUnregisterStorageMedia(psdStorage);
		psdStorage->Release();
		psdStorage = NULL;
	}
}

NCB_PRE_REGIST_CALLBACK(initStorage);
NCB_POST_UNREGIST_CALLBACK(doneStorage);
