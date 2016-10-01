/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#pragma once

#include "afxctl.h"

template<class ComInterface>
struct CComPropAccessor
{
	typedef HRESULT (STDMETHODCALLTYPE ComInterface::*str_get)(BSTR* pVal);
	typedef HRESULT (STDMETHODCALLTYPE ComInterface::*dbl_get)(DOUBLE* pVal);
	typedef HRESULT (STDMETHODCALLTYPE ComInterface::*long_get)(LONG* pVal);
	typedef HRESULT (STDMETHODCALLTYPE ComInterface::*bool_get)(BOOL* pVal);
	typedef HRESULT (STDMETHODCALLTYPE ComInterface::*disp_get)(IDispatch** pVal);

	template<class P1>
	struct Param1 {
		typedef HRESULT (STDMETHODCALLTYPE ComInterface::*disp_get)(P1 param1, IDispatch** pVal);
	};

	typedef HRESULT (STDMETHODCALLTYPE ComInterface::*str_put)(BSTR pVal);
	typedef HRESULT (STDMETHODCALLTYPE ComInterface::*dbl_put)(DOUBLE pVal);
	typedef HRESULT (STDMETHODCALLTYPE ComInterface::*long_put)(LONG pVal);
	typedef HRESULT (STDMETHODCALLTYPE ComInterface::*bool_put)(BOOL pVal);
	typedef HRESULT (STDMETHODCALLTYPE ComInterface::*disp_put)(IDispatch* pVal);

	static void Get(CString& dst, /* const */ ComInterface* obj, str_get get)
	{
		CComBSTR comStrValue;
		(obj->*get)(&comStrValue);
		dst = comStrValue;
	}

	static void Get(double& dst, /* const */ ComInterface* obj, dbl_get get)
	{
		DOUBLE comDblValue;
		(obj->*get)(&comDblValue);
		dst = comDblValue;
	}

	static void Get(long& dst, /* const */ ComInterface* obj, long_get get)
	{
		LONG comLongValue;
		(obj->*get)(&comLongValue);
		dst = comLongValue;
	}

	static void Get(int& dst, /* const */ ComInterface* obj, long_get get)
	{
		long longValue;
		Get(longValue, obj, get);
		dst = longValue;
	}

	static void Get(BOOL& dst, /* const */ ComInterface* obj, bool_get get)
	{
		(obj->*get)(&dst);
	}

	static void Get(bool& dst, /* const */ ComInterface* obj, bool_get get)
	{
		BOOL comBoolValue;
		(obj->*get)(&comBoolValue);
		dst = comBoolValue ? true : false;
	}

	static void Get(CComPtr<IDispatch>& dst, /* const */ ComInterface* obj, disp_get get)
	{
		IDispatch* iDispatchPtr = NULL;
		(obj->*get)(&iDispatchPtr);
		dst.Attach(iDispatchPtr);
	}

	template<class T>
	static void GetQI(CComQIPtr<T>& dst, /* const */ ComInterface* obj, disp_get get)
	{
		CComPtr<IDispatch> dispPtr;
		Get(dispPtr, obj, get);
		dst = dispPtr;
	}

	template<class P1>
	static void Get_P1(CComPtr<IDispatch>& dst, /* const */ ComInterface* obj, typename Param1<P1>::disp_get get, P1 param1)
	{
		IDispatch* iDispatchPtr = NULL;
		(obj->*get)(param1, &iDispatchPtr);
		dst.Attach(iDispatchPtr);
	}

	template<class T, class P1>
	static void GetQI_P1(CComQIPtr<T>& dst, /* const */ ComInterface* obj, typename Param1<P1>::disp_get get, P1 param1)
	{
		CComPtr<IDispatch> dispPtr;
		Get_P1(dispPtr, obj, get, param1);
		dst = dispPtr;
	}

	static void Put(ComInterface* obj, const CString& src, str_put put)
	{
		CComBSTR comStrValue = src;
		(obj->*put)(comStrValue);
	}

	static void Put(ComInterface* obj, const double src, dbl_put put)
	{
		DOUBLE comDblValue = src;
		(obj->*put)(comDblValue);
	}

	static void Put(ComInterface* obj, const long src, long_put put)
	{
		LONG comLongValue = src;
		(obj->*put)(comLongValue);
	}

	static void Put(ComInterface* obj, const int src, long_put put)
	{
		Put(obj, (long)src, put);
	}

	static void Put(ComInterface* obj, const bool src, bool_put put)
	{
		BOOL comBoolValue = src;
		(obj->*put)(comBoolValue);
	}

	static void Put(ComInterface* obj, /* const */ IDispatch* src, disp_put put)
	{
		(obj->*put)(src);
	}


};
