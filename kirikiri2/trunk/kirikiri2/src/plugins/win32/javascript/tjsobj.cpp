#include <windows.h>
#include "tp_stub.h"
#include <v8.h>
using namespace v8;

extern Persistent<Context> mainContext;

#include "tjsobj.h"
extern Local<Value> toJSValue(const tTJSVariant &variant);
extern tTJSVariant toVariant(Handle<Value> value);

/**
 * Javascriptに対してエラー通知
 */
Handle<Value>
ERROR_KRKR(tjs_error error)
{
	switch (error) {
	case TJS_E_MEMBERNOTFOUND:
		return ThrowException(String::New("member not found"));
	case TJS_E_NOTIMPL:
		return ThrowException(String::New("not implemented"));
	case TJS_E_INVALIDPARAM:
		return ThrowException(String::New("invalid param"));
	case TJS_E_BADPARAMCOUNT:
		return ThrowException(String::New("bad param count"));
	case TJS_E_INVALIDTYPE:
		return ThrowException(String::New("invalid type"));
	case TJS_E_INVALIDOBJECT:
		return ThrowException(String::New("invalid object"));
	case TJS_E_ACCESSDENYED:
		return ThrowException(String::New("access denyed"));
	case TJS_E_NATIVECLASSCRASH:
		return ThrowException(String::New("navive class crash"));
	default:
		return ThrowException(String::New("failed"));
	}
}

Handle<Value>
ERROR_CREATE()
{
	return ThrowException(String::New("create failed"));
}

Handle<Value>
ERROR_BADINSTANCE()
{
	return ThrowException(String::New("bad instance"));
}

//----------------------------------------------------------------------------
// tTJSVariantをオブジェクトとして保持するための機構
//----------------------------------------------------------------------------

Persistent<ObjectTemplate> TJSObject::objectTemplate;

// オブジェクト定義初期化
void
TJSObject::init()
{
	objectTemplate = Persistent<ObjectTemplate>::New(ObjectTemplate::New());
	objectTemplate->SetNamedPropertyHandler(getter, setter);
	objectTemplate->SetCallAsFunctionHandler(caller);
	objectTemplate->SetInternalFieldCount(1);
}

// オブジェクト定義解放
void
TJSObject::done()
{
	objectTemplate.Dispose();
}

TJSObject::TJSObject(iTJSDispatch2 *dispatch) : TJSBase(TYPE_OBJECT), dispatch(dispatch)
{
	if (dispatch) {
		dispatch->AddRef();
	}
}

TJSObject::~TJSObject()
{
	if (dispatch) {
		dispatch->Release();
	}
}

// パラメータ取得
iTJSDispatch2 *
TJSObject::getDispatch(Handle<Object> obj)
{
	if (obj->InternalFieldCount() > 0) {
		TJSBase *base = (TJSBase*)obj->GetPointerFromInternalField(0);
		if (base->isType(TYPE_OBJECT)) {
			TJSObject *self = (TJSObject*)base;
			return self->dispatch;
		}
	}
	return NULL;
}

// パラメータ解放
void
TJSObject::release(Persistent<Value> object, void *parameter)
{
	TJSObject *self = (TJSObject*)parameter;
	if (self) {
		delete self;
	}
}

// プロパティの取得
Handle<Value>
TJSObject::getter(Local<String> property, const AccessorInfo& info)
{
	iTJSDispatch2 *self = getDispatch(info.This());
	if (self) {
		String::Value propName(property);
		tjs_error error;
		tTJSVariant result;
		if (TJS_SUCCEEDED(error = self->PropGet(0, *propName, NULL, &result, self))) {
			return toJSValue(result);
		} else {
			return ERROR_KRKR(error);
		}
	}
	return ERROR_BADINSTANCE();
}

// プロパティの設定
Handle<Value>
TJSObject::setter(Local<String> property, Local<Value> value, const AccessorInfo& info)
{
	iTJSDispatch2 *self = getDispatch(info.This());
	if (self) {
		String::Value propName(property);
		tTJSVariant param = toVariant(value);
		tjs_error error;
		if (TJS_SUCCEEDED(error = self->PropSet(TJS_MEMBERENSURE, *propName, NULL, &param, self))) {
			return Undefined();
		} else {
			return ERROR_KRKR(error);
		}
	}
	return ERROR_BADINSTANCE();
}

// メソッドの呼び出し
Handle<Value>
TJSObject::caller(const Arguments& args)
{
	iTJSDispatch2 *self   = getDispatch(args.This());
	iTJSDispatch2 *method = getDispatch(args.Callee());
	
	if (self && method) {
		
		Handle<Value> ret;
		
		// 引数変換
		tjs_int argc = args.Length();
		tTJSVariant **argv = new tTJSVariant*[argc];
		for (tjs_int i=0;i<argc;i++) {
			argv[i] = new tTJSVariant();
			*argv[i] = toVariant(args[i]);
		}

		// メソッド呼び出し
		tTJSVariant result;
		tjs_error error;
		if (TJS_SUCCEEDED(error = method->FuncCall(0, NULL, NULL, &result, argc, argv, self))) {
			ret = toJSValue(result);
		} else {
			ret = ERROR_KRKR(error);
		}
		
		if (argv) {
			for (int i=0;i<argc;i++) {
				delete argv[i];
			}
			delete[] argv;
		}
		
		return ret;
	}
	return ERROR_BADINSTANCE();
}

// iTJSDispatch2 をオブジェクト化
Local<Object>
TJSObject::toJSObject(iTJSDispatch2 *dispatch)
{
	Local<Object> obj = objectTemplate->NewInstance();
	if (obj->IsObject()) {
		TJSObject *wrap = new TJSObject(dispatch);
		obj->SetPointerInInternalField(0, (void*)wrap);
		Persistent<Object> ref = Persistent<Object>::New(obj);
		ref.MakeWeak(wrap, release);
	}
	return obj;
}

// tTJSVariant化
bool
TJSObject::getVariant(tTJSVariant &result, Handle<Object> obj)
{
	iTJSDispatch2 *dispatch = getDispatch(obj);
	if (dispatch) {
		result = tTJSVariant(dispatch, dispatch);
		return true;
	}
	return false;
}
