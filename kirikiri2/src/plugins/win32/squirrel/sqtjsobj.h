#ifndef __SQTJS_OBJ_H_
#define __SQTJS_OBJ_H_

#include <sqobject.h>

/**
 * 吉里吉里オブジェクトを保持するクラス
 */
class TJSObject : public sqobject::Object {

public:
	/**
	 * 初期化用
	 */
	static void init();

	/**
	 * クラスの登録
	 * @param v squirrelVM
	 * @param className 登録クラス名
	 * @param tjsClassInfo クラス定義情報(TJSのクラス名のリスト)
	 */
	static void registerClass(HSQUIRRELVM v, const tjs_char *className, tTJSVariant *tjsClassInfo);

	/**
	 * 吉里吉里オブジェクトの取得
	 * @param v squirrelVM
	 * @param idx インデックス
	 * @return 吉里吉里ディスパッチャ
	 */
	static iTJSDispatch2 *getDispatch(HSQUIRRELVM v, int idx);
	
protected:
	// コンストラクタ
	TJSObject();

	// デストラクタ
	~TJSObject();
	
	/**
	 * オブジェクトのリリーサ
	 */
	static SQRESULT release(SQUserPointer up, SQInteger size);

	/**
	 * TJSオブジェクトのコンストラクタ
	 * 引数1 オブジェクト
	 * 引数2 クラス名
	 * 引数3 引数
	 */
	static SQRESULT tjsConstructor(HSQUIRRELVM v);

	/**
	 * TJSオブジェクト用のメソッド
	 * 引数1 オブジェクト
	 * 引数2 メンバ名
	 * 引数3 引数の配列
	 */
	static SQRESULT tjsInvoker(HSQUIRRELVM v);

	/**
	 * TJSオブジェクト用のプロパティゲッター
	 * 引数1 オブジェクト
	 * 引数2 プロパティ名
	 */
	static SQRESULT tjsGetter(HSQUIRRELVM v);

	/**
	 * TJSオブジェクト用のプロパティセッター
	 * 引数1 オブジェクト
	 * 引数2 プロパティ名
	 * 引数3 設定値
	 */
	static SQRESULT tjsSetter(HSQUIRRELVM v);
	
private:
	// 処理対象オブジェクト
	iTJSDispatch2 *dispatch;

};

#endif
