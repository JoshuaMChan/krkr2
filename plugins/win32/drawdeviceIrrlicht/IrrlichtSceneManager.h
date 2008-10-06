#ifndef IRRLICHTSCENEMANAGER_H
#define IRRLICHTSCENEMANAGER_H

#include <windows.h>
#include "tp_stub.h"
#include <irrlicht.h>

/**
 * シーンマネージャ操作用クラス
 */
class IrrlichtSceneManager {

protected:
	irr::scene::ISceneManager *smgr;
	
public:
	IrrlichtSceneManager();
	IrrlichtSceneManager(irr::scene::ISceneManager *smgr);
	IrrlichtSceneManager(const IrrlichtSceneManager &orig);
	~IrrlichtSceneManager();

	// ------------------------------------------------------------
	// シーン制御
	// ------------------------------------------------------------
public:	
	/**
	 * シーンデータファイルの読み込み
	 * @param filename シーンデータファイル(irrファイル)
	 * @return 読み込みに成功したら true
	 */
	bool loadScene(const char *filename);

	/**
	 * カメラの設定
	 */
	void addCameraSceneNode(tTJSVariant position, tTJSVariant lookat, int id);
};

#endif
