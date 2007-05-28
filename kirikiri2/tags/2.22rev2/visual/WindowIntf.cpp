//---------------------------------------------------------------------------
/*
	TVP2 ( T Visual Presenter 2 )  A script authoring tool
	Copyright (C) 2000-2004  W.Dee <dee@kikyou.info>

	See details of license at "license.txt"
*/
//---------------------------------------------------------------------------
// "Window" TJS Class implementation
//---------------------------------------------------------------------------
// 2004/ 4/30 W.Dee          Added support for Window.mouseCursorState
// 2004/ 4/26 W.Dee          Added support for IME control properties.
// 2004/ 4/19 W.Dee          Implemented onMouseLeave and onMouseEnter as
//                           normal events.
//---------------------------------------------------------------------------

#include "tjsCommHead.h"
#pragma hdrstop

#include "MsgIntf.h"
#include "WindowIntf.h"
#include "LayerIntf.h"
#include "DebugIntf.h"
#include "EventIntf.h"
#include "LayerBitmapIntf.h"
#include "MenuItemIntf.h"
#include "LayerIntf.h"
#include "SysInitIntf.h"
#include "VideoOvlIntf.h"


//---------------------------------------------------------------------------
// Window List
//---------------------------------------------------------------------------
tTJSNI_Window * TVPMainWindow = NULL; // main window
static std::vector<tTJSNI_Window*> TVPWindowVector;
//---------------------------------------------------------------------------
static void TVPRegisterWindowToList(tTJSNI_Window *window)
{
	if(TVPMainWindow == NULL && TVPWindowVector.size() == 0)
	{
		// first time the window is registered
		TVPMainWindow = window; // set as main window
	}
	TVPWindowVector.push_back(window);

	// notify that the layer must lost capture state
	std::vector<tTJSNI_Window*>::iterator i;
	for(i = TVPWindowVector.begin(); i!=TVPWindowVector.end(); i++)
	{
		(*i)->PostReleaseCaptureEvent();
	}
}
//---------------------------------------------------------------------------
static void TVPUnregisterWindowToList(tTJSNI_Window *window)
{
	std::vector<tTJSNI_Window*>::iterator i;
	i = std::find(TVPWindowVector.begin(), TVPWindowVector.end(), window);
	if(i != TVPWindowVector.end())
	{
		bool flag = false;
		if(*i == TVPMainWindow) flag = true;

		TVPWindowVector.erase(i);

		if(flag)
		{
			TVPMainWindowClosed(); // MainWindow had been closed
			TVPMainWindow = NULL;
		}
	}
}
//---------------------------------------------------------------------------
tTJSNI_Window * TVPGetWindowListAt(tjs_int idx) { return TVPWindowVector[idx]; }
//---------------------------------------------------------------------------
tjs_int TVPGetWindowCount() { return TVPWindowVector.size(); }
//---------------------------------------------------------------------------
void TVPClearAllWindowInputEvents()
{
	std::vector<tTJSNI_Window*>::iterator i;
	for(i = TVPWindowVector.begin(); i!=TVPWindowVector.end(); i++)
	{
		(*i)->ClearInputEvents();
	}
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
// tTJSNI_BaseWindow
//---------------------------------------------------------------------------
tTJSNI_BaseWindow::tTJSNI_BaseWindow()
{
	ObjectVectorLocked = false;
	DrawBuffer = NULL;
	MenuItemObject = NULL;
	VideoOverlay = NULL;
	LayerManager = new tTVPLayerManager(this);
	WindowExposedRegion.clear();
	WindowUpdating = false;
}
//---------------------------------------------------------------------------
tTJSNI_BaseWindow::~tTJSNI_BaseWindow()
{
	TVPUnregisterWindowToList(static_cast<tTJSNI_Window*>(this));  // making sure...
	if(LayerManager) delete LayerManager;
}
//---------------------------------------------------------------------------
tjs_error TJS_INTF_METHOD
tTJSNI_BaseWindow::Construct(tjs_int numparams, tTJSVariant **param,
		iTJSDispatch2 *tjs_obj)
{
	Owner = tjs_obj; // no addref
	TVPRegisterWindowToList(static_cast<tTJSNI_Window*>(this));
	return TJS_S_OK;
}
//---------------------------------------------------------------------------
void TJS_INTF_METHOD
tTJSNI_BaseWindow::Invalidate()
{
	// remove from list
	TVPUnregisterWindowToList(static_cast<tTJSNI_Window*>(this));

	// remove all events
	TVPCancelSourceEvents(Owner);
	TVPCancelInputEvents(this);

	// clear all window update events
	TVPRemoveWindowUpdate((tTJSNI_Window*)this);

	// sever the primarylayer
	if(LayerManager) LayerManager->DetachPrimary();

	// free DrawBuffer
	if(DrawBuffer) delete DrawBuffer;

	// disconnect VideoOverlay
	if(VideoOverlay) VideoOverlay->Disconnect();

	// invalidate all registered objects
	ObjectVectorLocked = true;
	std::vector<tTJSVariantClosure>::iterator i;

	for(i = ObjectVector.begin(); i != ObjectVector.end(); i++)
	{
		// invalidate each --
		// objects may throw an exception while invalidating,
		// but here we cannot care for them.
		try
		{
			i->Invalidate(0, NULL, NULL, NULL);
			i->Release();
		}
		catch(eTJSError &e)
		{
			TVPAddLog(e.GetMessage()); // just in case, log the error
		}
	}

	// invalidate menu object
	if(MenuItemObject)
	{
		MenuItemObject->Invalidate(0, NULL, NULL, MenuItemObject);
		MenuItemObject->Release();
		MenuItemObject = NULL;
	}

	// remove all events (again)
	TVPCancelSourceEvents(Owner);
	TVPCancelInputEvents(this);

	// notify that the window is no longer available
	if(LayerManager) LayerManager->SetWindow(NULL);

	// clear all window update events (again)
	TVPRemoveWindowUpdate((tTJSNI_Window*)this);

	inherited::Invalidate();
}
//---------------------------------------------------------------------------
bool tTJSNI_BaseWindow::IsMainWindow() const
{
	return TVPMainWindow == static_cast<const tTJSNI_Window*>(this);
}
//---------------------------------------------------------------------------
tTVPBaseBitmap * tTJSNI_BaseWindow::GetDrawTargetBitmap(const tTVPRect &rect,
	tTVPRect &cliprect)
{
	// retrieve draw target bitmap
	tjs_int w = rect.get_width();
	tjs_int h = rect.get_height();

	if(!DrawBuffer)
	{
		// create draw buffer
		DrawBuffer = new tTVPBaseBitmap(w, h, 32);
	}
	else
	{
		tjs_int bw = DrawBuffer->GetWidth();
		tjs_int bh = DrawBuffer->GetHeight();
		if(bw < w || bh  < h)
		{
			// insufficient size; resize the draw buffer
			tjs_uint neww = bw > w ? bw:w;
			neww += (neww & 1); // align to even
			DrawBuffer->SetSize(neww, bh > h ? bh:h);
		}
	}

	cliprect.left = 0;
	cliprect.top = 0;
	cliprect.right = w;
	cliprect.bottom = h;
	return DrawBuffer;
}
//---------------------------------------------------------------------------
#if 0
void tTJSNI_BaseWindow::PostInputEvent(const ttstr &name, iTJSDispatch2 * params)
{
	// posts input event
	static ttstr key_name(TJS_W("key"));
	static ttstr shift_name(TJS_W("shift"));

	// check input event name
	enum tEventType
	{
		etUnknown, etOnKeyDown, etOnKeyUp, etOnKeyPress
	} type;

	if(name == TJS_W("onKeyDown"))
		type = etOnKeyDown;
	else if(name == TJS_W("onKeyUp"))
		type = etOnKeyUp;
	else if(name == TJS_W("onKeyPress"))
		type = etOnKeyPress;
	else
		type = etUnknown;

	if(type == etUnknown)
		TVPThrowExceptionMessage(TVPSpecifiedEventNameIsUnknown, name);


	if(type == etOnKeyDown || type == etOnKeyUp)
	{
		// this needs params, "key" and "shift"
		if(params == NULL)
			TVPThrowExceptionMessage(
				TVPSpecifiedEventNeedsParameter, name);


		tjs_uint key;
		tjs_uint32 shift = 0;

		tTJSVariant val;
		if(TJS_SUCCEEDED(params->PropGet(0, key_name.c_str(), key_name.GetHint(),
			&val, params)))
			key = (tjs_int)val;
		else
			TVPThrowExceptionMessage(TVPSpecifiedEventNeedsParameter2,
				name, TJS_W("key"));

		if(TJS_SUCCEEDED(params->PropGet(0, shift_name.c_str(), shift_name.GetHint(),
			&val, params)))
			shift = (tjs_int)val;
		else
			TVPThrowExceptionMessage(TVPSpecifiedEventNeedsParameter2,
				name, TJS_W("shift"));

		if(type == etOnKeyDown)
			TVPPostInputEvent(new tTVPOnKeyDownInputEvent(this, key, shift));
		else if(type == etOnKeyUp)
			TVPPostInputEvent(new tTVPOnKeyUpInputEvent(this, key, shift));
	}
	else if(type == etOnKeyPress)
	{
		// this needs param, "key"
		if(params == NULL)
			TVPThrowExceptionMessage(
				TVPSpecifiedEventNeedsParameter, name);


		tjs_uint key;

		tTJSVariant val;
		if(TJS_SUCCEEDED(params->PropGet(0, key_name.c_str(), key_name.GetHint(),
			&val, params)))
			key = (tjs_int)val;
		else
			TVPThrowExceptionMessage(TVPSpecifiedEventNeedsParameter2,
				name, TJS_W("key"));

		TVPPostInputEvent(new tTVPOnKeyPressInputEvent(this, key));
	}
}
#endif
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnClose()
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		tTJSVariant arg[1] = {true};
		static ttstr eventname(TJS_W("onCloseQuery"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 1, arg);
	}
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnClick(tjs_int x, tjs_int y)
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		tTJSVariant arg[2] = { x, y };
		static ttstr eventname(TJS_W("onClick"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 2, arg);
	}
	if(LayerManager) LayerManager->NotifyClick(x, y);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnDoubleClick(tjs_int x, tjs_int y)
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		tTJSVariant arg[2] = { x, y };
		static ttstr eventname(TJS_W("onDoubleClick"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 2, arg);
	}
	if(LayerManager) LayerManager->NotifyDoubleClick(x, y);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnMouseDown(tjs_int x, tjs_int y, tTVPMouseButton mb,
	tjs_uint32 flags)
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		tTJSVariant arg[4] = { x, y, (tjs_int64)mb, (tjs_int64)flags };
		static ttstr eventname(TJS_W("onMouseDown"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 4, arg);
	}
	if(LayerManager) LayerManager->NotifyMouseDown(x, y, mb, flags);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnMouseUp(tjs_int x, tjs_int y, tTVPMouseButton mb,
	tjs_uint32 flags)
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		tTJSVariant arg[4] = { x, y, (tjs_int)mb, (tjs_int)flags };
		static ttstr eventname(TJS_W("onMouseUp"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 4, arg);
	}
	if(LayerManager) LayerManager->NotifyMouseUp(x, y, mb, flags);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnMouseMove(tjs_int x, tjs_int y, tjs_uint32 flags)
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		static ttstr eventname(TJS_W("onMouseMove"));
			tTJSVariant arg[3] = { x, y, (tjs_int64)flags };
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_DISCARDABLE|TVP_EPT_IMMEDIATE
			/*discardable!!*/,
			3, arg);
	}
	if(LayerManager) LayerManager->NotifyMouseMove(x, y, flags);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnReleaseCapture()
{
	if(!CanDeliverEvents()) return;
	if(LayerManager)
		LayerManager->ReleaseCapture();
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnMouseForceLeave()
{
	if(!CanDeliverEvents()) return;
	if(LayerManager) LayerManager->NotifyForceMouseLeave();
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnMouseEnter()
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		static ttstr eventname(TJS_W("onMouseEnter"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 0, NULL);
	}
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnMouseLeave()
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		static ttstr eventname(TJS_W("onMouseLeave"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 0, NULL);
	}
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnKeyDown(tjs_uint key, tjs_uint32 shift)
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		tTJSVariant arg[2] = { (tjs_int)key, (tjs_int)shift };
		static ttstr eventname(TJS_W("onKeyDown"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 2, arg);
	}
	if(LayerManager) LayerManager->NotifyKeyDown(key, shift);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnKeyUp(tjs_uint key, tjs_uint32 shift)
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		tTJSVariant arg[2] = { (tjs_int)key, (tjs_int)shift };
		static ttstr eventname(TJS_W("onKeyUp"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 2, arg);
	}
	if(LayerManager) LayerManager->NotifyKeyUp(key, shift);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnKeyPress(tjs_char key)
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		tjs_char buf[2];
		buf[0] = (tjs_char)key;
		buf[1] = 0;
		tTJSVariant arg[1] = { buf };
		static ttstr eventname(TJS_W("onKeyPress"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 1, arg);
	}
	if(LayerManager) LayerManager->NotifyKeyPress(key);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnFileDrop(const tTJSVariant &array)
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		tTJSVariant arg[1] = { array };
		static ttstr eventname(TJS_W("onFileDrop"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 1, arg);
	}
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::OnMouseWheel(tjs_uint32 shift, tjs_int delta,
	tjs_int x, tjs_int y)
{
	if(!CanDeliverEvents()) return;
	if(Owner)
	{
		tTJSVariant arg[4] = { (tjs_int)shift, delta, x, y };
		static ttstr eventname(TJS_W("onMouseWheel"));
		TVPPostEvent(Owner, Owner, eventname, 0, TVP_EPT_IMMEDIATE, 4, arg);
	}
	if(LayerManager) LayerManager->NotifyMouseWheel(shift, delta, x, y);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::ClearInputEvents()
{
	TVPCancelInputEvents(this);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::PostReleaseCaptureEvent()
{
	TVPPostInputEvent(
		new tTVPOnReleaseCaptureInputEvent(this));
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::NotifyWindowExposureToLayer(const tTVPRect &cliprect)
{
	if(LayerManager)
		LayerManager->NotifyInvalidationFromWindow(cliprect);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::NotifyUpdateRegionFixed(const tTVPComplexRect &updaterects)
{
	// is called by layer manager
	BeginUpdate(updaterects);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::UpdateContent()
{
	// is called from event dispatcher
	if(LayerManager) LayerManager->UpdateToWindow();

 	EndUpdate();
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::BeginUpdate(const tTVPComplexRect & rects)
{
	WindowUpdating = true;
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::EndUpdate()
{
	WindowUpdating = false;
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::DumpPrimaryLayerStructure()
{
	if(LayerManager) LayerManager->DumpPrimaryStructure();
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::NotifyWindowInvalidation()
{
	// is called from primary layer

	// post update event to self
	TVPPostWindowUpdate((tTJSNI_Window*)this);
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::NotifyLayerResize()
{
	// is called from primary layer
	if(WindowUpdating)
		TVPThrowExceptionMessage(TVPInvalidMethodInUpdating);
}
//---------------------------------------------------------------------------
iTJSDispatch2 * tTJSNI_BaseWindow::GetMenuItemObjectNoAddRef()
{
	// return MenuItemObject
	if(MenuItemObject) return MenuItemObject;

	// create MenuItemObect
	if(!Owner) 	TVPThrowExceptionMessage(TVPInternalError,
			TJS_W("tTJSNI_BaseWindow::GetMenuItemObjectNoAddRef"));
	MenuItemObject = TVPCreateMenuItemObject(Owner);
	return MenuItemObject;
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::RegisterVideoOverlayObject(tTJSNI_BaseVideoOverlay * ovl)
{
	if(VideoOverlay) TVPThrowExceptionMessage(TVPWindowHasAlreadyVideoOverlayObject);

	VideoOverlay = ovl;
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::UnregisterVideoOverlayObject(tTJSNI_BaseVideoOverlay * ovl)
{
	VideoOverlay = NULL;
}
//---------------------------------------------------------------------------




//---- methods

//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::Add(tTJSVariantClosure clo)
{
	if(ObjectVectorLocked) return;
	if(ObjectVector.end() == std::find(ObjectVector.begin(), ObjectVector.end(), clo))
	{
		ObjectVector.push_back(clo);
		clo.AddRef();
	}
}
//---------------------------------------------------------------------------
void tTJSNI_BaseWindow::Remove(tTJSVariantClosure clo)
{
	if(ObjectVectorLocked) return;
	std::vector<tTJSVariantClosure>::iterator i;
	i = std::find(ObjectVector.begin(), ObjectVector.end(), clo);
	if(i != ObjectVector.end())
	{
		clo.Release();
		ObjectVector.erase(i);
	}
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
// tTJSNC_Window : TJS Window class
//---------------------------------------------------------------------------
tjs_uint32 tTJSNC_Window::ClassID = -1;
tTJSNC_Window::tTJSNC_Window() : tTJSNativeClass(TJS_W("Window"))
{
	// registration of native members

	TJS_BEGIN_NATIVE_MEMBERS(Window) // constructor
	TJS_DECL_EMPTY_FINALIZE_METHOD
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_CONSTRUCTOR_DECL(/*var.name*/_this, /*var.type*/tTJSNI_Window,
	/*TJS class name*/Window)
{
	return TJS_S_OK;
}
TJS_END_NATIVE_CONSTRUCTOR_DECL(/*TJS class name*/Window)
//----------------------------------------------------------------------




//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/close)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	_this->Close();
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/close)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/beginMove)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	_this->BeginMove();
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/beginMove)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/bringToFront)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	_this->BringToFront();
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/bringToFront)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/update)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	tTVPUpdateType type = utNormal;
	if(numparams >= 2 && param[1]->Type() != tvtVoid)
		type = (tTVPUpdateType)(tjs_int)*param[0];
	_this->Update(type);
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/update)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/showModal)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	_this->ShowModal();
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/showModal)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/setMaskRegion)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	tjs_int threshold = 1;
	if(numparams >= 1 && param[0]->Type() != tvtVoid)
		threshold = (tjs_int)*param[0];
	_this->SetMaskRegion(threshold);
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/setMaskRegion)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/removeMaskRegion)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	_this->RemoveMaskRegion();
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/removeMaskRegion)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/add)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	if(numparams < 1) return TJS_E_BADPARAMCOUNT;
	tTJSVariantClosure clo = param[0]->AsObjectClosureNoAddRef();
	_this->Add(clo);
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/add)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/remove)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	if(numparams < 1) return TJS_E_BADPARAMCOUNT;
	tTJSVariantClosure clo = param[0]->AsObjectClosureNoAddRef();
	_this->Remove(clo);
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/remove)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/setSize)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	if(numparams < 2) return TJS_E_BADPARAMCOUNT;
	_this->SetSize(*param[0], *param[1]);
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/setSize)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/setPos) // not setPosition
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	if(numparams < 2) return TJS_E_BADPARAMCOUNT;
	_this->SetPosition(*param[0], *param[1]);
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/setPos)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/setLayerPos) // not setLayerPosition
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	if(numparams < 2) return TJS_E_BADPARAMCOUNT;
	_this->SetLayerPosition(*param[0], *param[1]);
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/setLayerPos)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/setInnerSize)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	if(numparams < 2) return TJS_E_BADPARAMCOUNT;
	_this->SetInnerSize(*param[0], *param[1]);
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/setInnerSize)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/hideMouseCursor)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
	_this->HideMouseCursor();
	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/hideMouseCursor)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/postInputEvent)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	if(numparams < 1)  return TJS_E_BADPARAMCOUNT;
	ttstr eventname;
	iTJSDispatch2 * eventparams = NULL;

	eventname = *param[0];
	if(numparams >= 2) eventparams = param[1]->AsObjectNoAddRef();

	_this->PostInputEvent(eventname, eventparams);

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/postInputEvent)
//----------------------------------------------------------------------



//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onMouseEnter)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(0, "onMouseEnter", objthis);
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onMouseEnter)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onMouseLeave)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(0, "onMouseLeave", objthis);
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onMouseLeave)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onClick)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(2, "onClick", objthis);
	TVP_ACTION_INVOKE_MEMBER("x");
	TVP_ACTION_INVOKE_MEMBER("y");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onClick)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onDoubleClick)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(2, "onDoubleClick", objthis);
	TVP_ACTION_INVOKE_MEMBER("x");
	TVP_ACTION_INVOKE_MEMBER("y");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onDoubleClick)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onMouseDown)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(4, "onMouseDown", objthis);
	TVP_ACTION_INVOKE_MEMBER("x");
	TVP_ACTION_INVOKE_MEMBER("y");
	TVP_ACTION_INVOKE_MEMBER("button");
	TVP_ACTION_INVOKE_MEMBER("shift");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onMouseDown)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onMouseUp)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(4, "onMouseUp", objthis);
	TVP_ACTION_INVOKE_MEMBER("x");
	TVP_ACTION_INVOKE_MEMBER("y");
	TVP_ACTION_INVOKE_MEMBER("button");
	TVP_ACTION_INVOKE_MEMBER("shift");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onMouseUp)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onMouseMove)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(3, "onMouseMove", objthis);
	TVP_ACTION_INVOKE_MEMBER("x");
	TVP_ACTION_INVOKE_MEMBER("y");
	TVP_ACTION_INVOKE_MEMBER("shift");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onMouseMove)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onMouseWheel)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(4, "onMouseWheel", objthis);
	TVP_ACTION_INVOKE_MEMBER("shift");
	TVP_ACTION_INVOKE_MEMBER("delta");
	TVP_ACTION_INVOKE_MEMBER("x");
	TVP_ACTION_INVOKE_MEMBER("y");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onMouseWheel)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onKeyDown)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(2, "onKeyDown", objthis);
	TVP_ACTION_INVOKE_MEMBER("key");
	TVP_ACTION_INVOKE_MEMBER("shift");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onKeyDown)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onKeyUp)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(2, "onKeyUp", objthis);
	TVP_ACTION_INVOKE_MEMBER("key");
	TVP_ACTION_INVOKE_MEMBER("shift");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onKeyUp)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onKeyPress)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(1, "onKeyPress", objthis);
	TVP_ACTION_INVOKE_MEMBER("key");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onKeyPress)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onFileDrop)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

	TVP_ACTION_INVOKE_BEGIN(1, "onFileDrop", objthis);
	TVP_ACTION_INVOKE_MEMBER("files");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onFileDrop)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_METHOD_DECL(/*func. name*/onCloseQuery)
{
	TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
/*
	// this event does not call "action" method
	TVP_ACTION_INVOKE_BEGIN(1, "onCloseQuery", objthis);
	TVP_ACTION_INVOKE_MEMBER("canClose");
	TVP_ACTION_INVOKE_END(tTJSVariantClosure(objthis, objthis));
*/
	_this->OnCloseQueryCalled((bool)*param[0]);

	return TJS_S_OK;
}
TJS_END_NATIVE_METHOD_DECL(/*func. name*/onCloseQuery)
//----------------------------------------------------------------------


//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(visible)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetVisible();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetVisible(*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(visible)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(caption)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		ttstr res;
		_this->GetCaption(res);
		*result = res;
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetCaption(*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(caption)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(width)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetWidth();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetWidth(*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(width)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(height)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetHeight();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetHeight(*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(height)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(left)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetLeft();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetLeft(*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(left)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(top)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetTop();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetTop(*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(top)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(layerLeft)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetLayerLeft();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetLayerLeft(*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(layerLeft)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(layerTop)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetLayerTop();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetLayerTop(*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(layerTop)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(innerSunken)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetInnerSunken();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetInnerSunken(param->operator bool());
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(innerSunken)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(innerWidth)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetInnerWidth();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetInnerWidth(*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(innerWidth)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(innerHeight)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetInnerHeight();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetInnerHeight(*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(innerHeight)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(borderStyle)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = (tjs_int)_this->GetBorderStyle();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetBorderStyle((tTVPBorderStyle)(tjs_int)*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(borderStyle)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(stayOnTop)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetStayOnTop();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetStayOnTop(param->operator bool());
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(stayOnTop)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(showScrollBars)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetShowScrollBars();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetShowScrollBars(param->operator bool());
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(showScrollBars)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(useMouseKey)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetUseMouseKey();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetUseMouseKey(param->operator bool());
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(useMouseKey)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(imeMode) // not defaultImeMode
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = (tjs_int)_this->GetDefaultImeMode();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetDefaultImeMode((tTVPImeMode)(tjs_int)*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(imeMode)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(mouseCursorState)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = (tjs_int)_this->GetMouseCursorState();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetMouseCursorState((tTVPMouseCursorState)(tjs_int)*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(mouseCursorState)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(menu)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		iTJSDispatch2 *dsp = _this->GetMenuItemObjectNoAddRef();
		*result = tTJSVariant(dsp, dsp);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_DENY_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(menu)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(fullScreen)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		*result = _this->GetFullScreen();
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		_this->SetFullScreen((tjs_int)*param);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(fullScreen)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(mainWindow) /* static */
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		if(TVPMainWindow)
		{
			iTJSDispatch2 *dsp = TVPMainWindow->GetOwnerNoAddRef();
			*result = tTJSVariant(dsp, dsp);
		}
		else
		{
			*result = tTJSVariant((iTJSDispatch2*)NULL);
		}
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_DENY_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(mainWindow)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(focusedLayer)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		tTJSNI_BaseLayer *lay = _this->GetLayerManager()->GetFocusedLayer();
		if(lay && lay->GetOwnerNoAddRef())
			*result = tTJSVariant(lay->GetOwnerNoAddRef(), lay->GetOwnerNoAddRef());
		else
			*result = tTJSVariant((iTJSDispatch2*)NULL);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_BEGIN_NATIVE_PROP_SETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);

		tTJSNI_BaseLayer *to = NULL;

		if(param->Type() != tvtVoid)
		{
			tTJSVariantClosure clo = param->AsObjectClosureNoAddRef();
			if(clo.Object)
			{
				if(TJS_FAILED(clo.Object->NativeInstanceSupport(TJS_NIS_GETINSTANCE,
					tTJSNC_Layer::ClassID, (iTJSNativeInstance**)&to)))
					TVPThrowExceptionMessage(TVPSpecifyLayer);
			}
		}

		_this->GetLayerManager()->SetFocusTo(to);

		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(focusedLayer)
//----------------------------------------------------------------------
TJS_BEGIN_NATIVE_PROP_DECL(primaryLayer)
{
	TJS_BEGIN_NATIVE_PROP_GETTER
	{
		TJS_GET_NATIVE_INSTANCE(/*var. name*/_this, /*var. type*/tTJSNI_Window);
		tTJSNI_BaseLayer *pri = _this->GetLayerManager()->GetPrimaryLayer();
		if(!pri) TVPThrowExceptionMessage(TVPWindowHasNoLayer);

		if(pri && pri->GetOwnerNoAddRef())
			*result = tTJSVariant(pri->GetOwnerNoAddRef(), pri->GetOwnerNoAddRef());
		else
			*result = tTJSVariant((iTJSDispatch2*)NULL);
		return TJS_S_OK;
	}
	TJS_END_NATIVE_PROP_GETTER

	TJS_DENY_NATIVE_PROP_SETTER
}
TJS_END_NATIVE_PROP_DECL(primaryLayer)
//----------------------------------------------------------------------

	TJS_END_NATIVE_MEMBERS

}
//---------------------------------------------------------------------------
