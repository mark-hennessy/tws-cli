

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Fri Mar 28 14:51:23 2014
 */
/* Compiler settings for .\Tws.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __Tws_i_h__
#define __Tws_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IComboLeg_FWD_DEFINED__
#define __IComboLeg_FWD_DEFINED__
typedef interface IComboLeg IComboLeg;
#endif 	/* __IComboLeg_FWD_DEFINED__ */


#ifndef __IComboLegList_FWD_DEFINED__
#define __IComboLegList_FWD_DEFINED__
typedef interface IComboLegList IComboLegList;
#endif 	/* __IComboLegList_FWD_DEFINED__ */


#ifndef __IUnderComp_FWD_DEFINED__
#define __IUnderComp_FWD_DEFINED__
typedef interface IUnderComp IUnderComp;
#endif 	/* __IUnderComp_FWD_DEFINED__ */


#ifndef __IContract_FWD_DEFINED__
#define __IContract_FWD_DEFINED__
typedef interface IContract IContract;
#endif 	/* __IContract_FWD_DEFINED__ */


#ifndef __IContractDetails_FWD_DEFINED__
#define __IContractDetails_FWD_DEFINED__
typedef interface IContractDetails IContractDetails;
#endif 	/* __IContractDetails_FWD_DEFINED__ */


#ifndef __ITagValue_FWD_DEFINED__
#define __ITagValue_FWD_DEFINED__
typedef interface ITagValue ITagValue;
#endif 	/* __ITagValue_FWD_DEFINED__ */


#ifndef __ITagValueList_FWD_DEFINED__
#define __ITagValueList_FWD_DEFINED__
typedef interface ITagValueList ITagValueList;
#endif 	/* __ITagValueList_FWD_DEFINED__ */


#ifndef __IOrder_FWD_DEFINED__
#define __IOrder_FWD_DEFINED__
typedef interface IOrder IOrder;
#endif 	/* __IOrder_FWD_DEFINED__ */


#ifndef __IOrderState_FWD_DEFINED__
#define __IOrderState_FWD_DEFINED__
typedef interface IOrderState IOrderState;
#endif 	/* __IOrderState_FWD_DEFINED__ */


#ifndef __IExecution_FWD_DEFINED__
#define __IExecution_FWD_DEFINED__
typedef interface IExecution IExecution;
#endif 	/* __IExecution_FWD_DEFINED__ */


#ifndef __IExecutionFilter_FWD_DEFINED__
#define __IExecutionFilter_FWD_DEFINED__
typedef interface IExecutionFilter IExecutionFilter;
#endif 	/* __IExecutionFilter_FWD_DEFINED__ */


#ifndef __IScannerSubscription_FWD_DEFINED__
#define __IScannerSubscription_FWD_DEFINED__
typedef interface IScannerSubscription IScannerSubscription;
#endif 	/* __IScannerSubscription_FWD_DEFINED__ */


#ifndef __IOrderComboLeg_FWD_DEFINED__
#define __IOrderComboLeg_FWD_DEFINED__
typedef interface IOrderComboLeg IOrderComboLeg;
#endif 	/* __IOrderComboLeg_FWD_DEFINED__ */


#ifndef __IOrderComboLegList_FWD_DEFINED__
#define __IOrderComboLegList_FWD_DEFINED__
typedef interface IOrderComboLegList IOrderComboLegList;
#endif 	/* __IOrderComboLegList_FWD_DEFINED__ */


#ifndef __ICommissionReport_FWD_DEFINED__
#define __ICommissionReport_FWD_DEFINED__
typedef interface ICommissionReport ICommissionReport;
#endif 	/* __ICommissionReport_FWD_DEFINED__ */


#ifndef ___DTws_FWD_DEFINED__
#define ___DTws_FWD_DEFINED__
typedef interface _DTws _DTws;
#endif 	/* ___DTws_FWD_DEFINED__ */


#ifndef ___DTwsEvents_FWD_DEFINED__
#define ___DTwsEvents_FWD_DEFINED__
typedef interface _DTwsEvents _DTwsEvents;
#endif 	/* ___DTwsEvents_FWD_DEFINED__ */


#ifndef __Tws_FWD_DEFINED__
#define __Tws_FWD_DEFINED__

#ifdef __cplusplus
typedef class Tws Tws;
#else
typedef struct Tws Tws;
#endif /* __cplusplus */

#endif 	/* __Tws_FWD_DEFINED__ */


/* header files for imported files */
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __TWSLib_LIBRARY_DEFINED__
#define __TWSLib_LIBRARY_DEFINED__

/* library TWSLib */
/* [control][helpstring][helpfile][version][uuid] */ 


EXTERN_C const IID LIBID_TWSLib;

#ifndef __IComboLeg_INTERFACE_DEFINED__
#define __IComboLeg_INTERFACE_DEFINED__

/* interface IComboLeg */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IComboLeg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("573E95CF-F67C-4367-A95B-CB7599BD0673")
    IComboLeg : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_conId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_conId( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ratio( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ratio( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_action( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_action( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_exchange( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_exchange( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_openClose( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_openClose( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_shortSaleSlot( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_shortSaleSlot( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_designatedLocation( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_designatedLocation( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_exemptCode( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_exemptCode( 
            /* [in] */ LONG newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IComboLegVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComboLeg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComboLeg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComboLeg * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComboLeg * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComboLeg * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComboLeg * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComboLeg * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_conId )( 
            IComboLeg * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_conId )( 
            IComboLeg * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ratio )( 
            IComboLeg * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ratio )( 
            IComboLeg * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_action )( 
            IComboLeg * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_action )( 
            IComboLeg * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_exchange )( 
            IComboLeg * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_exchange )( 
            IComboLeg * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_openClose )( 
            IComboLeg * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_openClose )( 
            IComboLeg * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_shortSaleSlot )( 
            IComboLeg * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_shortSaleSlot )( 
            IComboLeg * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_designatedLocation )( 
            IComboLeg * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_designatedLocation )( 
            IComboLeg * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_exemptCode )( 
            IComboLeg * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_exemptCode )( 
            IComboLeg * This,
            /* [in] */ LONG newVal);
        
        END_INTERFACE
    } IComboLegVtbl;

    interface IComboLeg
    {
        CONST_VTBL struct IComboLegVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComboLeg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IComboLeg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IComboLeg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IComboLeg_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IComboLeg_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IComboLeg_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IComboLeg_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IComboLeg_get_conId(This,pVal)	\
    (This)->lpVtbl -> get_conId(This,pVal)

#define IComboLeg_put_conId(This,newVal)	\
    (This)->lpVtbl -> put_conId(This,newVal)

#define IComboLeg_get_ratio(This,pVal)	\
    (This)->lpVtbl -> get_ratio(This,pVal)

#define IComboLeg_put_ratio(This,newVal)	\
    (This)->lpVtbl -> put_ratio(This,newVal)

#define IComboLeg_get_action(This,pVal)	\
    (This)->lpVtbl -> get_action(This,pVal)

#define IComboLeg_put_action(This,newVal)	\
    (This)->lpVtbl -> put_action(This,newVal)

#define IComboLeg_get_exchange(This,pVal)	\
    (This)->lpVtbl -> get_exchange(This,pVal)

#define IComboLeg_put_exchange(This,newVal)	\
    (This)->lpVtbl -> put_exchange(This,newVal)

#define IComboLeg_get_openClose(This,pVal)	\
    (This)->lpVtbl -> get_openClose(This,pVal)

#define IComboLeg_put_openClose(This,newVal)	\
    (This)->lpVtbl -> put_openClose(This,newVal)

#define IComboLeg_get_shortSaleSlot(This,pVal)	\
    (This)->lpVtbl -> get_shortSaleSlot(This,pVal)

#define IComboLeg_put_shortSaleSlot(This,newVal)	\
    (This)->lpVtbl -> put_shortSaleSlot(This,newVal)

#define IComboLeg_get_designatedLocation(This,pVal)	\
    (This)->lpVtbl -> get_designatedLocation(This,pVal)

#define IComboLeg_put_designatedLocation(This,newVal)	\
    (This)->lpVtbl -> put_designatedLocation(This,newVal)

#define IComboLeg_get_exemptCode(This,pVal)	\
    (This)->lpVtbl -> get_exemptCode(This,pVal)

#define IComboLeg_put_exemptCode(This,newVal)	\
    (This)->lpVtbl -> put_exemptCode(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComboLeg_get_conId_Proxy( 
    IComboLeg * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IComboLeg_get_conId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IComboLeg_put_conId_Proxy( 
    IComboLeg * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IComboLeg_put_conId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComboLeg_get_ratio_Proxy( 
    IComboLeg * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IComboLeg_get_ratio_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IComboLeg_put_ratio_Proxy( 
    IComboLeg * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IComboLeg_put_ratio_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComboLeg_get_action_Proxy( 
    IComboLeg * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IComboLeg_get_action_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IComboLeg_put_action_Proxy( 
    IComboLeg * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IComboLeg_put_action_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComboLeg_get_exchange_Proxy( 
    IComboLeg * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IComboLeg_get_exchange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IComboLeg_put_exchange_Proxy( 
    IComboLeg * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IComboLeg_put_exchange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComboLeg_get_openClose_Proxy( 
    IComboLeg * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IComboLeg_get_openClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IComboLeg_put_openClose_Proxy( 
    IComboLeg * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IComboLeg_put_openClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComboLeg_get_shortSaleSlot_Proxy( 
    IComboLeg * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IComboLeg_get_shortSaleSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IComboLeg_put_shortSaleSlot_Proxy( 
    IComboLeg * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IComboLeg_put_shortSaleSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComboLeg_get_designatedLocation_Proxy( 
    IComboLeg * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IComboLeg_get_designatedLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IComboLeg_put_designatedLocation_Proxy( 
    IComboLeg * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IComboLeg_put_designatedLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IComboLeg_get_exemptCode_Proxy( 
    IComboLeg * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IComboLeg_get_exemptCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IComboLeg_put_exemptCode_Proxy( 
    IComboLeg * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IComboLeg_put_exemptCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IComboLeg_INTERFACE_DEFINED__ */


#ifndef __IComboLegList_INTERFACE_DEFINED__
#define __IComboLegList_INTERFACE_DEFINED__

/* interface IComboLegList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IComboLegList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BE3E5CD3-6F13-4D39-981C-4F75C063C2BA")
    IComboLegList : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG index,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IDispatch **leg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IComboLegListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComboLegList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComboLegList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComboLegList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComboLegList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComboLegList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComboLegList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComboLegList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IComboLegList * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IComboLegList * This,
            /* [in] */ LONG index,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IComboLegList * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IComboLegList * This,
            /* [retval][out] */ IDispatch **leg);
        
        END_INTERFACE
    } IComboLegListVtbl;

    interface IComboLegList
    {
        CONST_VTBL struct IComboLegListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComboLegList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IComboLegList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IComboLegList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IComboLegList_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IComboLegList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IComboLegList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IComboLegList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IComboLegList_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define IComboLegList_get_Item(This,index,pVal)	\
    (This)->lpVtbl -> get_Item(This,index,pVal)

#define IComboLegList_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IComboLegList_Add(This,leg)	\
    (This)->lpVtbl -> Add(This,leg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IComboLegList_get__NewEnum_Proxy( 
    IComboLegList * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB IComboLegList_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IComboLegList_get_Item_Proxy( 
    IComboLegList * This,
    /* [in] */ LONG index,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB IComboLegList_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IComboLegList_get_Count_Proxy( 
    IComboLegList * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IComboLegList_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IComboLegList_Add_Proxy( 
    IComboLegList * This,
    /* [retval][out] */ IDispatch **leg);


void __RPC_STUB IComboLegList_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IComboLegList_INTERFACE_DEFINED__ */


#ifndef __IUnderComp_INTERFACE_DEFINED__
#define __IUnderComp_INTERFACE_DEFINED__

/* interface IUnderComp */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IUnderComp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E5EE73C4-7D45-428E-A347-821CBF918AA6")
    IUnderComp : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_conId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_conId( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_delta( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_delta( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_price( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_price( 
            /* [in] */ DOUBLE newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUnderCompVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnderComp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnderComp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnderComp * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUnderComp * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUnderComp * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUnderComp * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUnderComp * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_conId )( 
            IUnderComp * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_conId )( 
            IUnderComp * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_delta )( 
            IUnderComp * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_delta )( 
            IUnderComp * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_price )( 
            IUnderComp * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_price )( 
            IUnderComp * This,
            /* [in] */ DOUBLE newVal);
        
        END_INTERFACE
    } IUnderCompVtbl;

    interface IUnderComp
    {
        CONST_VTBL struct IUnderCompVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnderComp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnderComp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnderComp_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUnderComp_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUnderComp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUnderComp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUnderComp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUnderComp_get_conId(This,pVal)	\
    (This)->lpVtbl -> get_conId(This,pVal)

#define IUnderComp_put_conId(This,newVal)	\
    (This)->lpVtbl -> put_conId(This,newVal)

#define IUnderComp_get_delta(This,pVal)	\
    (This)->lpVtbl -> get_delta(This,pVal)

#define IUnderComp_put_delta(This,newVal)	\
    (This)->lpVtbl -> put_delta(This,newVal)

#define IUnderComp_get_price(This,pVal)	\
    (This)->lpVtbl -> get_price(This,pVal)

#define IUnderComp_put_price(This,newVal)	\
    (This)->lpVtbl -> put_price(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnderComp_get_conId_Proxy( 
    IUnderComp * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IUnderComp_get_conId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnderComp_put_conId_Proxy( 
    IUnderComp * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IUnderComp_put_conId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnderComp_get_delta_Proxy( 
    IUnderComp * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IUnderComp_get_delta_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnderComp_put_delta_Proxy( 
    IUnderComp * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IUnderComp_put_delta_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUnderComp_get_price_Proxy( 
    IUnderComp * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IUnderComp_get_price_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUnderComp_put_price_Proxy( 
    IUnderComp * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IUnderComp_put_price_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUnderComp_INTERFACE_DEFINED__ */


#ifndef __IContract_INTERFACE_DEFINED__
#define __IContract_INTERFACE_DEFINED__

/* interface IContract */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IContract;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AE6A66F3-8FA9-4076-9C1F-3728B10A4CC7")
    IContract : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_conId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_conId( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_symbol( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_symbol( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_secType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_secType( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_expiry( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_expiry( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_strike( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_strike( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_right( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_right( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_multiplier( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_multiplier( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_exchange( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_exchange( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_primaryExchange( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_primaryExchange( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_currency( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_currency( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_localSymbol( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_localSymbol( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_tradingClass( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_tradingClass( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_includeExpired( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_includeExpired( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_comboLegs( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_comboLegs( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_underComp( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_underComp( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_comboLegsDescrip( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_secIdType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_secIdType( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_secId( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_secId( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IContractVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IContract * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IContract * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IContract * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IContract * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IContract * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IContract * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IContract * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_conId )( 
            IContract * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_conId )( 
            IContract * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_symbol )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_symbol )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_secType )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_secType )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_expiry )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_expiry )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_strike )( 
            IContract * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_strike )( 
            IContract * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_right )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_right )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_multiplier )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_multiplier )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_exchange )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_exchange )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_primaryExchange )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_primaryExchange )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_currency )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_currency )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_localSymbol )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_localSymbol )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_tradingClass )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_tradingClass )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_includeExpired )( 
            IContract * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_includeExpired )( 
            IContract * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_comboLegs )( 
            IContract * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_comboLegs )( 
            IContract * This,
            /* [in] */ IDispatch *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_underComp )( 
            IContract * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_underComp )( 
            IContract * This,
            /* [in] */ IDispatch *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_comboLegsDescrip )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_secIdType )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_secIdType )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_secId )( 
            IContract * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_secId )( 
            IContract * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IContractVtbl;

    interface IContract
    {
        CONST_VTBL struct IContractVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContract_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IContract_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IContract_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IContract_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IContract_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IContract_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IContract_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IContract_get_conId(This,pVal)	\
    (This)->lpVtbl -> get_conId(This,pVal)

#define IContract_put_conId(This,newVal)	\
    (This)->lpVtbl -> put_conId(This,newVal)

#define IContract_get_symbol(This,pVal)	\
    (This)->lpVtbl -> get_symbol(This,pVal)

#define IContract_put_symbol(This,newVal)	\
    (This)->lpVtbl -> put_symbol(This,newVal)

#define IContract_get_secType(This,pVal)	\
    (This)->lpVtbl -> get_secType(This,pVal)

#define IContract_put_secType(This,newVal)	\
    (This)->lpVtbl -> put_secType(This,newVal)

#define IContract_get_expiry(This,pVal)	\
    (This)->lpVtbl -> get_expiry(This,pVal)

#define IContract_put_expiry(This,newVal)	\
    (This)->lpVtbl -> put_expiry(This,newVal)

#define IContract_get_strike(This,pVal)	\
    (This)->lpVtbl -> get_strike(This,pVal)

#define IContract_put_strike(This,newVal)	\
    (This)->lpVtbl -> put_strike(This,newVal)

#define IContract_get_right(This,pVal)	\
    (This)->lpVtbl -> get_right(This,pVal)

#define IContract_put_right(This,newVal)	\
    (This)->lpVtbl -> put_right(This,newVal)

#define IContract_get_multiplier(This,pVal)	\
    (This)->lpVtbl -> get_multiplier(This,pVal)

#define IContract_put_multiplier(This,newVal)	\
    (This)->lpVtbl -> put_multiplier(This,newVal)

#define IContract_get_exchange(This,pVal)	\
    (This)->lpVtbl -> get_exchange(This,pVal)

#define IContract_put_exchange(This,newVal)	\
    (This)->lpVtbl -> put_exchange(This,newVal)

#define IContract_get_primaryExchange(This,pVal)	\
    (This)->lpVtbl -> get_primaryExchange(This,pVal)

#define IContract_put_primaryExchange(This,newVal)	\
    (This)->lpVtbl -> put_primaryExchange(This,newVal)

#define IContract_get_currency(This,pVal)	\
    (This)->lpVtbl -> get_currency(This,pVal)

#define IContract_put_currency(This,newVal)	\
    (This)->lpVtbl -> put_currency(This,newVal)

#define IContract_get_localSymbol(This,pVal)	\
    (This)->lpVtbl -> get_localSymbol(This,pVal)

#define IContract_put_localSymbol(This,newVal)	\
    (This)->lpVtbl -> put_localSymbol(This,newVal)

#define IContract_get_tradingClass(This,pVal)	\
    (This)->lpVtbl -> get_tradingClass(This,pVal)

#define IContract_put_tradingClass(This,newVal)	\
    (This)->lpVtbl -> put_tradingClass(This,newVal)

#define IContract_get_includeExpired(This,pVal)	\
    (This)->lpVtbl -> get_includeExpired(This,pVal)

#define IContract_put_includeExpired(This,newVal)	\
    (This)->lpVtbl -> put_includeExpired(This,newVal)

#define IContract_get_comboLegs(This,pVal)	\
    (This)->lpVtbl -> get_comboLegs(This,pVal)

#define IContract_putref_comboLegs(This,newVal)	\
    (This)->lpVtbl -> putref_comboLegs(This,newVal)

#define IContract_get_underComp(This,pVal)	\
    (This)->lpVtbl -> get_underComp(This,pVal)

#define IContract_putref_underComp(This,newVal)	\
    (This)->lpVtbl -> putref_underComp(This,newVal)

#define IContract_get_comboLegsDescrip(This,pVal)	\
    (This)->lpVtbl -> get_comboLegsDescrip(This,pVal)

#define IContract_get_secIdType(This,pVal)	\
    (This)->lpVtbl -> get_secIdType(This,pVal)

#define IContract_put_secIdType(This,newVal)	\
    (This)->lpVtbl -> put_secIdType(This,newVal)

#define IContract_get_secId(This,pVal)	\
    (This)->lpVtbl -> get_secId(This,pVal)

#define IContract_put_secId(This,newVal)	\
    (This)->lpVtbl -> put_secId(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_conId_Proxy( 
    IContract * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IContract_get_conId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_conId_Proxy( 
    IContract * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IContract_put_conId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_symbol_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_symbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_symbol_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_symbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_secType_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_secType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_secType_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_secType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_expiry_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_expiry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_expiry_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_expiry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_strike_Proxy( 
    IContract * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IContract_get_strike_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_strike_Proxy( 
    IContract * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IContract_put_strike_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_right_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_right_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_right_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_right_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_multiplier_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_multiplier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_multiplier_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_multiplier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_exchange_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_exchange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_exchange_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_exchange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_primaryExchange_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_primaryExchange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_primaryExchange_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_primaryExchange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_currency_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_currency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_currency_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_currency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_localSymbol_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_localSymbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_localSymbol_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_localSymbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_tradingClass_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_tradingClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_tradingClass_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_tradingClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_includeExpired_Proxy( 
    IContract * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IContract_get_includeExpired_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_includeExpired_Proxy( 
    IContract * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IContract_put_includeExpired_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_comboLegs_Proxy( 
    IContract * This,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB IContract_get_comboLegs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE IContract_putref_comboLegs_Proxy( 
    IContract * This,
    /* [in] */ IDispatch *newVal);


void __RPC_STUB IContract_putref_comboLegs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_underComp_Proxy( 
    IContract * This,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB IContract_get_underComp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE IContract_putref_underComp_Proxy( 
    IContract * This,
    /* [in] */ IDispatch *newVal);


void __RPC_STUB IContract_putref_underComp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_comboLegsDescrip_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_comboLegsDescrip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_secIdType_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_secIdType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_secIdType_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_secIdType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContract_get_secId_Proxy( 
    IContract * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContract_get_secId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IContract_put_secId_Proxy( 
    IContract * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IContract_put_secId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IContract_INTERFACE_DEFINED__ */


#ifndef __IContractDetails_INTERFACE_DEFINED__
#define __IContractDetails_INTERFACE_DEFINED__

/* interface IContractDetails */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IContractDetails;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("64F03988-ED93-452E-830B-3420DF21BAF9")
    IContractDetails : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_marketName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_minTick( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_priceMagnifier( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_orderTypes( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_validExchanges( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_underConId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_longName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_contractMonth( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_industry( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_category( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_subcategory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_timeZoneId( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_tradingHours( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_liquidHours( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_summary( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_secIdList( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_cusip( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ratings( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_descAppend( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_bondType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_couponType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_callable( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_putable( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_coupon( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_convertible( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_maturity( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_issueDate( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nextOptionDate( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nextOptionType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nextOptionPartial( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_notes( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_evRule( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_evMultiplier( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IContractDetailsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IContractDetails * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IContractDetails * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IContractDetails * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IContractDetails * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IContractDetails * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IContractDetails * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IContractDetails * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_marketName )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_minTick )( 
            IContractDetails * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_priceMagnifier )( 
            IContractDetails * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_orderTypes )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_validExchanges )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_underConId )( 
            IContractDetails * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_longName )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_contractMonth )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_industry )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_category )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_subcategory )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_timeZoneId )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_tradingHours )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_liquidHours )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_summary )( 
            IContractDetails * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_secIdList )( 
            IContractDetails * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_cusip )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ratings )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_descAppend )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_bondType )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_couponType )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_callable )( 
            IContractDetails * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_putable )( 
            IContractDetails * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_coupon )( 
            IContractDetails * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_convertible )( 
            IContractDetails * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_maturity )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_issueDate )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_nextOptionDate )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_nextOptionType )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_nextOptionPartial )( 
            IContractDetails * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_notes )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_evRule )( 
            IContractDetails * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_evMultiplier )( 
            IContractDetails * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        END_INTERFACE
    } IContractDetailsVtbl;

    interface IContractDetails
    {
        CONST_VTBL struct IContractDetailsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContractDetails_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IContractDetails_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IContractDetails_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IContractDetails_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IContractDetails_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IContractDetails_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IContractDetails_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IContractDetails_get_marketName(This,pVal)	\
    (This)->lpVtbl -> get_marketName(This,pVal)

#define IContractDetails_get_minTick(This,pVal)	\
    (This)->lpVtbl -> get_minTick(This,pVal)

#define IContractDetails_get_priceMagnifier(This,pVal)	\
    (This)->lpVtbl -> get_priceMagnifier(This,pVal)

#define IContractDetails_get_orderTypes(This,pVal)	\
    (This)->lpVtbl -> get_orderTypes(This,pVal)

#define IContractDetails_get_validExchanges(This,pVal)	\
    (This)->lpVtbl -> get_validExchanges(This,pVal)

#define IContractDetails_get_underConId(This,pVal)	\
    (This)->lpVtbl -> get_underConId(This,pVal)

#define IContractDetails_get_longName(This,pVal)	\
    (This)->lpVtbl -> get_longName(This,pVal)

#define IContractDetails_get_contractMonth(This,pVal)	\
    (This)->lpVtbl -> get_contractMonth(This,pVal)

#define IContractDetails_get_industry(This,pVal)	\
    (This)->lpVtbl -> get_industry(This,pVal)

#define IContractDetails_get_category(This,pVal)	\
    (This)->lpVtbl -> get_category(This,pVal)

#define IContractDetails_get_subcategory(This,pVal)	\
    (This)->lpVtbl -> get_subcategory(This,pVal)

#define IContractDetails_get_timeZoneId(This,pVal)	\
    (This)->lpVtbl -> get_timeZoneId(This,pVal)

#define IContractDetails_get_tradingHours(This,pVal)	\
    (This)->lpVtbl -> get_tradingHours(This,pVal)

#define IContractDetails_get_liquidHours(This,pVal)	\
    (This)->lpVtbl -> get_liquidHours(This,pVal)

#define IContractDetails_get_summary(This,pVal)	\
    (This)->lpVtbl -> get_summary(This,pVal)

#define IContractDetails_get_secIdList(This,pVal)	\
    (This)->lpVtbl -> get_secIdList(This,pVal)

#define IContractDetails_get_cusip(This,pVal)	\
    (This)->lpVtbl -> get_cusip(This,pVal)

#define IContractDetails_get_ratings(This,pVal)	\
    (This)->lpVtbl -> get_ratings(This,pVal)

#define IContractDetails_get_descAppend(This,pVal)	\
    (This)->lpVtbl -> get_descAppend(This,pVal)

#define IContractDetails_get_bondType(This,pVal)	\
    (This)->lpVtbl -> get_bondType(This,pVal)

#define IContractDetails_get_couponType(This,pVal)	\
    (This)->lpVtbl -> get_couponType(This,pVal)

#define IContractDetails_get_callable(This,pVal)	\
    (This)->lpVtbl -> get_callable(This,pVal)

#define IContractDetails_get_putable(This,pVal)	\
    (This)->lpVtbl -> get_putable(This,pVal)

#define IContractDetails_get_coupon(This,pVal)	\
    (This)->lpVtbl -> get_coupon(This,pVal)

#define IContractDetails_get_convertible(This,pVal)	\
    (This)->lpVtbl -> get_convertible(This,pVal)

#define IContractDetails_get_maturity(This,pVal)	\
    (This)->lpVtbl -> get_maturity(This,pVal)

#define IContractDetails_get_issueDate(This,pVal)	\
    (This)->lpVtbl -> get_issueDate(This,pVal)

#define IContractDetails_get_nextOptionDate(This,pVal)	\
    (This)->lpVtbl -> get_nextOptionDate(This,pVal)

#define IContractDetails_get_nextOptionType(This,pVal)	\
    (This)->lpVtbl -> get_nextOptionType(This,pVal)

#define IContractDetails_get_nextOptionPartial(This,pVal)	\
    (This)->lpVtbl -> get_nextOptionPartial(This,pVal)

#define IContractDetails_get_notes(This,pVal)	\
    (This)->lpVtbl -> get_notes(This,pVal)

#define IContractDetails_get_evRule(This,pVal)	\
    (This)->lpVtbl -> get_evRule(This,pVal)

#define IContractDetails_get_evMultiplier(This,pVal)	\
    (This)->lpVtbl -> get_evMultiplier(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_marketName_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_marketName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_minTick_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IContractDetails_get_minTick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_priceMagnifier_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IContractDetails_get_priceMagnifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_orderTypes_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_orderTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_validExchanges_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_validExchanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_underConId_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IContractDetails_get_underConId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_longName_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_longName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_contractMonth_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_contractMonth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_industry_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_industry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_category_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_category_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_subcategory_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_subcategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_timeZoneId_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_timeZoneId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_tradingHours_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_tradingHours_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_liquidHours_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_liquidHours_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_summary_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB IContractDetails_get_summary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_secIdList_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB IContractDetails_get_secIdList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_cusip_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_cusip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_ratings_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_ratings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_descAppend_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_descAppend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_bondType_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_bondType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_couponType_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_couponType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_callable_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IContractDetails_get_callable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_putable_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IContractDetails_get_putable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_coupon_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IContractDetails_get_coupon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_convertible_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IContractDetails_get_convertible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_maturity_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_maturity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_issueDate_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_issueDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_nextOptionDate_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_nextOptionDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_nextOptionType_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_nextOptionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_nextOptionPartial_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IContractDetails_get_nextOptionPartial_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_notes_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_notes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_evRule_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IContractDetails_get_evRule_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IContractDetails_get_evMultiplier_Proxy( 
    IContractDetails * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IContractDetails_get_evMultiplier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IContractDetails_INTERFACE_DEFINED__ */


#ifndef __ITagValue_INTERFACE_DEFINED__
#define __ITagValue_INTERFACE_DEFINED__

/* interface ITagValue */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITagValue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("06FF1D3F-F12F-47D1-9443-A74D3CD58723")
    ITagValue : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_tag( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_tag( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_value( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_value( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITagValueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITagValue * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITagValue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITagValue * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITagValue * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITagValue * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITagValue * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITagValue * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_tag )( 
            ITagValue * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_tag )( 
            ITagValue * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_value )( 
            ITagValue * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_value )( 
            ITagValue * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } ITagValueVtbl;

    interface ITagValue
    {
        CONST_VTBL struct ITagValueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITagValue_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITagValue_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITagValue_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITagValue_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITagValue_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITagValue_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITagValue_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITagValue_get_tag(This,pVal)	\
    (This)->lpVtbl -> get_tag(This,pVal)

#define ITagValue_put_tag(This,newVal)	\
    (This)->lpVtbl -> put_tag(This,newVal)

#define ITagValue_get_value(This,pVal)	\
    (This)->lpVtbl -> get_value(This,pVal)

#define ITagValue_put_value(This,newVal)	\
    (This)->lpVtbl -> put_value(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITagValue_get_tag_Proxy( 
    ITagValue * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ITagValue_get_tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITagValue_put_tag_Proxy( 
    ITagValue * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ITagValue_put_tag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITagValue_get_value_Proxy( 
    ITagValue * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ITagValue_get_value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITagValue_put_value_Proxy( 
    ITagValue * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ITagValue_put_value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITagValue_INTERFACE_DEFINED__ */


#ifndef __ITagValueList_INTERFACE_DEFINED__
#define __ITagValueList_INTERFACE_DEFINED__

/* interface ITagValueList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITagValueList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CC48E64E-C1A7-4867-8738-578404D75088")
    ITagValueList : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG index,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddEmpty( 
            /* [retval][out] */ IDispatch **leg) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR tag,
            /* [in] */ BSTR value,
            /* [retval][out] */ IDispatch **leg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITagValueListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITagValueList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITagValueList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITagValueList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITagValueList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITagValueList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITagValueList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITagValueList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            ITagValueList * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            ITagValueList * This,
            /* [in] */ LONG index,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ITagValueList * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddEmpty )( 
            ITagValueList * This,
            /* [retval][out] */ IDispatch **leg);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            ITagValueList * This,
            /* [in] */ BSTR tag,
            /* [in] */ BSTR value,
            /* [retval][out] */ IDispatch **leg);
        
        END_INTERFACE
    } ITagValueListVtbl;

    interface ITagValueList
    {
        CONST_VTBL struct ITagValueListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITagValueList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITagValueList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITagValueList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITagValueList_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITagValueList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITagValueList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITagValueList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITagValueList_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define ITagValueList_get_Item(This,index,pVal)	\
    (This)->lpVtbl -> get_Item(This,index,pVal)

#define ITagValueList_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define ITagValueList_AddEmpty(This,leg)	\
    (This)->lpVtbl -> AddEmpty(This,leg)

#define ITagValueList_Add(This,tag,value,leg)	\
    (This)->lpVtbl -> Add(This,tag,value,leg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE ITagValueList_get__NewEnum_Proxy( 
    ITagValueList * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB ITagValueList_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ITagValueList_get_Item_Proxy( 
    ITagValueList * This,
    /* [in] */ LONG index,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB ITagValueList_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ITagValueList_get_Count_Proxy( 
    ITagValueList * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB ITagValueList_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE ITagValueList_AddEmpty_Proxy( 
    ITagValueList * This,
    /* [retval][out] */ IDispatch **leg);


void __RPC_STUB ITagValueList_AddEmpty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE ITagValueList_Add_Proxy( 
    ITagValueList * This,
    /* [in] */ BSTR tag,
    /* [in] */ BSTR value,
    /* [retval][out] */ IDispatch **leg);


void __RPC_STUB ITagValueList_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITagValueList_INTERFACE_DEFINED__ */


#ifndef __IOrder_INTERFACE_DEFINED__
#define __IOrder_INTERFACE_DEFINED__

/* interface IOrder */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOrder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("25D97F3D-2C4D-4080-9250-D2FB8071BE58")
    IOrder : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_orderId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_orderId( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_clientId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_clientId( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_permId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_permId( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_action( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_action( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_totalQuantity( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_totalQuantity( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_orderType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_orderType( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_lmtPrice( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_lmtPrice( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_auxPrice( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_auxPrice( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_timeInForce( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_timeInForce( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_activeStartTime( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_activeStartTime( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_activeStopTime( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_activeStopTime( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ocaGroup( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ocaGroup( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ocaType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ocaType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_orderRef( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_orderRef( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_transmit( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_transmit( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_parentId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_parentId( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_blockOrder( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_blockOrder( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_sweepToFill( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_sweepToFill( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_displaySize( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_displaySize( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_triggerMethod( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_triggerMethod( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_outsideRth( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_outsideRth( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_hidden( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_hidden( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_goodAfterTime( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_goodAfterTime( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_goodTillDate( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_goodTillDate( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_overridePercentageConstraints( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_overridePercentageConstraints( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_rule80A( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_rule80A( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_allOrNone( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_allOrNone( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_minQty( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_minQty( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_percentOffset( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_percentOffset( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_trailStopPrice( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_trailStopPrice( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_trailingPercent( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_trailingPercent( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_whatIf( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_whatIf( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_notHeld( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_notHeld( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_faGroup( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_faGroup( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_faProfile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_faProfile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_faMethod( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_faMethod( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_faPercentage( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_faPercentage( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_openClose( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_openClose( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_origin( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_origin( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_shortSaleSlot( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_shortSaleSlot( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_designatedLocation( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_designatedLocation( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_exemptCode( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_exemptCode( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_discretionaryAmt( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_discretionaryAmt( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_eTradeOnly( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_eTradeOnly( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_firmQuoteOnly( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_firmQuoteOnly( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nbboPriceCap( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_nbboPriceCap( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_optOutSmartRouting( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_optOutSmartRouting( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_auctionStrategy( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_auctionStrategy( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_startingPrice( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_startingPrice( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_stockRefPrice( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_stockRefPrice( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_delta( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_delta( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_stockRangeLower( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_stockRangeLower( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_stockRangeUpper( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_stockRangeUpper( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_volatility( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_volatility( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_volatilityType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_volatilityType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_continuousUpdate( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_continuousUpdate( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_referencePriceType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_referencePriceType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_deltaNeutralOrderType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_deltaNeutralOrderType( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_deltaNeutralAuxPrice( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_deltaNeutralAuxPrice( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_deltaNeutralConId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_deltaNeutralConId( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_deltaNeutralSettlingFirm( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_deltaNeutralSettlingFirm( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_deltaNeutralClearingAccount( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_deltaNeutralClearingAccount( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_deltaNeutralClearingIntent( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_deltaNeutralClearingIntent( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_deltaNeutralOpenClose( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_deltaNeutralOpenClose( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_deltaNeutralShortSale( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_deltaNeutralShortSale( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_deltaNeutralShortSaleSlot( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_deltaNeutralShortSaleSlot( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_deltaNeutralDesignatedLocation( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_deltaNeutralDesignatedLocation( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_basisPoints( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_basisPoints( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_basisPointsType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_basisPointsType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scaleInitLevelSize( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scaleInitLevelSize( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scaleSubsLevelSize( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scaleSubsLevelSize( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scalePriceIncrement( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scalePriceIncrement( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scalePriceAdjustValue( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scalePriceAdjustValue( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scalePriceAdjustInterval( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scalePriceAdjustInterval( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scaleProfitOffset( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scaleProfitOffset( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scaleAutoReset( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scaleAutoReset( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scaleInitPosition( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scaleInitPosition( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scaleInitFillQty( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scaleInitFillQty( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scaleRandomPercent( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scaleRandomPercent( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scaleTable( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scaleTable( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_hedgeType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_hedgeType( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_hedgeParam( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_hedgeParam( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_account( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_account( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_settlingFirm( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_settlingFirm( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_clearingAccount( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_clearingAccount( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_clearingIntent( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_clearingIntent( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_algoStrategy( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_algoStrategy( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_algoParams( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_algoParams( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_smartComboRoutingParams( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_smartComboRoutingParams( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_orderComboLegs( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_orderComboLegs( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_orderMiscOptions( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_orderMiscOptions( 
            /* [in] */ IDispatch *newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOrderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOrder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOrder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOrder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOrder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOrder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOrder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOrder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_orderId )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_orderId )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_clientId )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_clientId )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_permId )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_permId )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_action )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_action )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_totalQuantity )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_totalQuantity )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_orderType )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_orderType )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_lmtPrice )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_lmtPrice )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_auxPrice )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_auxPrice )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_timeInForce )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_timeInForce )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_activeStartTime )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_activeStartTime )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_activeStopTime )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_activeStopTime )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ocaGroup )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ocaGroup )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ocaType )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ocaType )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_orderRef )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_orderRef )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_transmit )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_transmit )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_parentId )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_parentId )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_blockOrder )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_blockOrder )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_sweepToFill )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_sweepToFill )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_displaySize )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_displaySize )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_triggerMethod )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_triggerMethod )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_outsideRth )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_outsideRth )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_hidden )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_hidden )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_goodAfterTime )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_goodAfterTime )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_goodTillDate )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_goodTillDate )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_overridePercentageConstraints )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_overridePercentageConstraints )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_rule80A )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_rule80A )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_allOrNone )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_allOrNone )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_minQty )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_minQty )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_percentOffset )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_percentOffset )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_trailStopPrice )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_trailStopPrice )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_trailingPercent )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_trailingPercent )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_whatIf )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_whatIf )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_notHeld )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_notHeld )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_faGroup )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_faGroup )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_faProfile )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_faProfile )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_faMethod )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_faMethod )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_faPercentage )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_faPercentage )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_openClose )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_openClose )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_origin )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_origin )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_shortSaleSlot )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_shortSaleSlot )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_designatedLocation )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_designatedLocation )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_exemptCode )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_exemptCode )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_discretionaryAmt )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_discretionaryAmt )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_eTradeOnly )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_eTradeOnly )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_firmQuoteOnly )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_firmQuoteOnly )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_nbboPriceCap )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_nbboPriceCap )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_optOutSmartRouting )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_optOutSmartRouting )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_auctionStrategy )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_auctionStrategy )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_startingPrice )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_startingPrice )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_stockRefPrice )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_stockRefPrice )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_delta )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_delta )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_stockRangeLower )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_stockRangeLower )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_stockRangeUpper )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_stockRangeUpper )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_volatility )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_volatility )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_volatilityType )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_volatilityType )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_continuousUpdate )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_continuousUpdate )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_referencePriceType )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_referencePriceType )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_deltaNeutralOrderType )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_deltaNeutralOrderType )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_deltaNeutralAuxPrice )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_deltaNeutralAuxPrice )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_deltaNeutralConId )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_deltaNeutralConId )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_deltaNeutralSettlingFirm )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_deltaNeutralSettlingFirm )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_deltaNeutralClearingAccount )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_deltaNeutralClearingAccount )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_deltaNeutralClearingIntent )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_deltaNeutralClearingIntent )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_deltaNeutralOpenClose )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_deltaNeutralOpenClose )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_deltaNeutralShortSale )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_deltaNeutralShortSale )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_deltaNeutralShortSaleSlot )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_deltaNeutralShortSaleSlot )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_deltaNeutralDesignatedLocation )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_deltaNeutralDesignatedLocation )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_basisPoints )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_basisPoints )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_basisPointsType )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_basisPointsType )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scaleInitLevelSize )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scaleInitLevelSize )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scaleSubsLevelSize )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scaleSubsLevelSize )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scalePriceIncrement )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scalePriceIncrement )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scalePriceAdjustValue )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scalePriceAdjustValue )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scalePriceAdjustInterval )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scalePriceAdjustInterval )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scaleProfitOffset )( 
            IOrder * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scaleProfitOffset )( 
            IOrder * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scaleAutoReset )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scaleAutoReset )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scaleInitPosition )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scaleInitPosition )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scaleInitFillQty )( 
            IOrder * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scaleInitFillQty )( 
            IOrder * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scaleRandomPercent )( 
            IOrder * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scaleRandomPercent )( 
            IOrder * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scaleTable )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scaleTable )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_hedgeType )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_hedgeType )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_hedgeParam )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_hedgeParam )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_account )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_account )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_settlingFirm )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_settlingFirm )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_clearingAccount )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_clearingAccount )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_clearingIntent )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_clearingIntent )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_algoStrategy )( 
            IOrder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_algoStrategy )( 
            IOrder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_algoParams )( 
            IOrder * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_algoParams )( 
            IOrder * This,
            /* [in] */ IDispatch *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_smartComboRoutingParams )( 
            IOrder * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_smartComboRoutingParams )( 
            IOrder * This,
            /* [in] */ IDispatch *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_orderComboLegs )( 
            IOrder * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_orderComboLegs )( 
            IOrder * This,
            /* [in] */ IDispatch *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_orderMiscOptions )( 
            IOrder * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_orderMiscOptions )( 
            IOrder * This,
            /* [in] */ IDispatch *newVal);
        
        END_INTERFACE
    } IOrderVtbl;

    interface IOrder
    {
        CONST_VTBL struct IOrderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOrder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOrder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOrder_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOrder_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOrder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOrder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOrder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOrder_get_orderId(This,pVal)	\
    (This)->lpVtbl -> get_orderId(This,pVal)

#define IOrder_put_orderId(This,newVal)	\
    (This)->lpVtbl -> put_orderId(This,newVal)

#define IOrder_get_clientId(This,pVal)	\
    (This)->lpVtbl -> get_clientId(This,pVal)

#define IOrder_put_clientId(This,newVal)	\
    (This)->lpVtbl -> put_clientId(This,newVal)

#define IOrder_get_permId(This,pVal)	\
    (This)->lpVtbl -> get_permId(This,pVal)

#define IOrder_put_permId(This,newVal)	\
    (This)->lpVtbl -> put_permId(This,newVal)

#define IOrder_get_action(This,pVal)	\
    (This)->lpVtbl -> get_action(This,pVal)

#define IOrder_put_action(This,newVal)	\
    (This)->lpVtbl -> put_action(This,newVal)

#define IOrder_get_totalQuantity(This,pVal)	\
    (This)->lpVtbl -> get_totalQuantity(This,pVal)

#define IOrder_put_totalQuantity(This,newVal)	\
    (This)->lpVtbl -> put_totalQuantity(This,newVal)

#define IOrder_get_orderType(This,pVal)	\
    (This)->lpVtbl -> get_orderType(This,pVal)

#define IOrder_put_orderType(This,newVal)	\
    (This)->lpVtbl -> put_orderType(This,newVal)

#define IOrder_get_lmtPrice(This,pVal)	\
    (This)->lpVtbl -> get_lmtPrice(This,pVal)

#define IOrder_put_lmtPrice(This,newVal)	\
    (This)->lpVtbl -> put_lmtPrice(This,newVal)

#define IOrder_get_auxPrice(This,pVal)	\
    (This)->lpVtbl -> get_auxPrice(This,pVal)

#define IOrder_put_auxPrice(This,newVal)	\
    (This)->lpVtbl -> put_auxPrice(This,newVal)

#define IOrder_get_timeInForce(This,pVal)	\
    (This)->lpVtbl -> get_timeInForce(This,pVal)

#define IOrder_put_timeInForce(This,newVal)	\
    (This)->lpVtbl -> put_timeInForce(This,newVal)

#define IOrder_get_activeStartTime(This,pVal)	\
    (This)->lpVtbl -> get_activeStartTime(This,pVal)

#define IOrder_put_activeStartTime(This,newVal)	\
    (This)->lpVtbl -> put_activeStartTime(This,newVal)

#define IOrder_get_activeStopTime(This,pVal)	\
    (This)->lpVtbl -> get_activeStopTime(This,pVal)

#define IOrder_put_activeStopTime(This,newVal)	\
    (This)->lpVtbl -> put_activeStopTime(This,newVal)

#define IOrder_get_ocaGroup(This,pVal)	\
    (This)->lpVtbl -> get_ocaGroup(This,pVal)

#define IOrder_put_ocaGroup(This,newVal)	\
    (This)->lpVtbl -> put_ocaGroup(This,newVal)

#define IOrder_get_ocaType(This,pVal)	\
    (This)->lpVtbl -> get_ocaType(This,pVal)

#define IOrder_put_ocaType(This,newVal)	\
    (This)->lpVtbl -> put_ocaType(This,newVal)

#define IOrder_get_orderRef(This,pVal)	\
    (This)->lpVtbl -> get_orderRef(This,pVal)

#define IOrder_put_orderRef(This,newVal)	\
    (This)->lpVtbl -> put_orderRef(This,newVal)

#define IOrder_get_transmit(This,pVal)	\
    (This)->lpVtbl -> get_transmit(This,pVal)

#define IOrder_put_transmit(This,newVal)	\
    (This)->lpVtbl -> put_transmit(This,newVal)

#define IOrder_get_parentId(This,pVal)	\
    (This)->lpVtbl -> get_parentId(This,pVal)

#define IOrder_put_parentId(This,newVal)	\
    (This)->lpVtbl -> put_parentId(This,newVal)

#define IOrder_get_blockOrder(This,pVal)	\
    (This)->lpVtbl -> get_blockOrder(This,pVal)

#define IOrder_put_blockOrder(This,newVal)	\
    (This)->lpVtbl -> put_blockOrder(This,newVal)

#define IOrder_get_sweepToFill(This,pVal)	\
    (This)->lpVtbl -> get_sweepToFill(This,pVal)

#define IOrder_put_sweepToFill(This,newVal)	\
    (This)->lpVtbl -> put_sweepToFill(This,newVal)

#define IOrder_get_displaySize(This,pVal)	\
    (This)->lpVtbl -> get_displaySize(This,pVal)

#define IOrder_put_displaySize(This,newVal)	\
    (This)->lpVtbl -> put_displaySize(This,newVal)

#define IOrder_get_triggerMethod(This,pVal)	\
    (This)->lpVtbl -> get_triggerMethod(This,pVal)

#define IOrder_put_triggerMethod(This,newVal)	\
    (This)->lpVtbl -> put_triggerMethod(This,newVal)

#define IOrder_get_outsideRth(This,pVal)	\
    (This)->lpVtbl -> get_outsideRth(This,pVal)

#define IOrder_put_outsideRth(This,newVal)	\
    (This)->lpVtbl -> put_outsideRth(This,newVal)

#define IOrder_get_hidden(This,pVal)	\
    (This)->lpVtbl -> get_hidden(This,pVal)

#define IOrder_put_hidden(This,newVal)	\
    (This)->lpVtbl -> put_hidden(This,newVal)

#define IOrder_get_goodAfterTime(This,pVal)	\
    (This)->lpVtbl -> get_goodAfterTime(This,pVal)

#define IOrder_put_goodAfterTime(This,newVal)	\
    (This)->lpVtbl -> put_goodAfterTime(This,newVal)

#define IOrder_get_goodTillDate(This,pVal)	\
    (This)->lpVtbl -> get_goodTillDate(This,pVal)

#define IOrder_put_goodTillDate(This,newVal)	\
    (This)->lpVtbl -> put_goodTillDate(This,newVal)

#define IOrder_get_overridePercentageConstraints(This,pVal)	\
    (This)->lpVtbl -> get_overridePercentageConstraints(This,pVal)

#define IOrder_put_overridePercentageConstraints(This,newVal)	\
    (This)->lpVtbl -> put_overridePercentageConstraints(This,newVal)

#define IOrder_get_rule80A(This,pVal)	\
    (This)->lpVtbl -> get_rule80A(This,pVal)

#define IOrder_put_rule80A(This,newVal)	\
    (This)->lpVtbl -> put_rule80A(This,newVal)

#define IOrder_get_allOrNone(This,pVal)	\
    (This)->lpVtbl -> get_allOrNone(This,pVal)

#define IOrder_put_allOrNone(This,newVal)	\
    (This)->lpVtbl -> put_allOrNone(This,newVal)

#define IOrder_get_minQty(This,pVal)	\
    (This)->lpVtbl -> get_minQty(This,pVal)

#define IOrder_put_minQty(This,newVal)	\
    (This)->lpVtbl -> put_minQty(This,newVal)

#define IOrder_get_percentOffset(This,pVal)	\
    (This)->lpVtbl -> get_percentOffset(This,pVal)

#define IOrder_put_percentOffset(This,newVal)	\
    (This)->lpVtbl -> put_percentOffset(This,newVal)

#define IOrder_get_trailStopPrice(This,pVal)	\
    (This)->lpVtbl -> get_trailStopPrice(This,pVal)

#define IOrder_put_trailStopPrice(This,newVal)	\
    (This)->lpVtbl -> put_trailStopPrice(This,newVal)

#define IOrder_get_trailingPercent(This,pVal)	\
    (This)->lpVtbl -> get_trailingPercent(This,pVal)

#define IOrder_put_trailingPercent(This,newVal)	\
    (This)->lpVtbl -> put_trailingPercent(This,newVal)

#define IOrder_get_whatIf(This,pVal)	\
    (This)->lpVtbl -> get_whatIf(This,pVal)

#define IOrder_put_whatIf(This,newVal)	\
    (This)->lpVtbl -> put_whatIf(This,newVal)

#define IOrder_get_notHeld(This,pVal)	\
    (This)->lpVtbl -> get_notHeld(This,pVal)

#define IOrder_put_notHeld(This,newVal)	\
    (This)->lpVtbl -> put_notHeld(This,newVal)

#define IOrder_get_faGroup(This,pVal)	\
    (This)->lpVtbl -> get_faGroup(This,pVal)

#define IOrder_put_faGroup(This,newVal)	\
    (This)->lpVtbl -> put_faGroup(This,newVal)

#define IOrder_get_faProfile(This,pVal)	\
    (This)->lpVtbl -> get_faProfile(This,pVal)

#define IOrder_put_faProfile(This,newVal)	\
    (This)->lpVtbl -> put_faProfile(This,newVal)

#define IOrder_get_faMethod(This,pVal)	\
    (This)->lpVtbl -> get_faMethod(This,pVal)

#define IOrder_put_faMethod(This,newVal)	\
    (This)->lpVtbl -> put_faMethod(This,newVal)

#define IOrder_get_faPercentage(This,pVal)	\
    (This)->lpVtbl -> get_faPercentage(This,pVal)

#define IOrder_put_faPercentage(This,newVal)	\
    (This)->lpVtbl -> put_faPercentage(This,newVal)

#define IOrder_get_openClose(This,pVal)	\
    (This)->lpVtbl -> get_openClose(This,pVal)

#define IOrder_put_openClose(This,newVal)	\
    (This)->lpVtbl -> put_openClose(This,newVal)

#define IOrder_get_origin(This,pVal)	\
    (This)->lpVtbl -> get_origin(This,pVal)

#define IOrder_put_origin(This,newVal)	\
    (This)->lpVtbl -> put_origin(This,newVal)

#define IOrder_get_shortSaleSlot(This,pVal)	\
    (This)->lpVtbl -> get_shortSaleSlot(This,pVal)

#define IOrder_put_shortSaleSlot(This,newVal)	\
    (This)->lpVtbl -> put_shortSaleSlot(This,newVal)

#define IOrder_get_designatedLocation(This,pVal)	\
    (This)->lpVtbl -> get_designatedLocation(This,pVal)

#define IOrder_put_designatedLocation(This,newVal)	\
    (This)->lpVtbl -> put_designatedLocation(This,newVal)

#define IOrder_get_exemptCode(This,pVal)	\
    (This)->lpVtbl -> get_exemptCode(This,pVal)

#define IOrder_put_exemptCode(This,newVal)	\
    (This)->lpVtbl -> put_exemptCode(This,newVal)

#define IOrder_get_discretionaryAmt(This,pVal)	\
    (This)->lpVtbl -> get_discretionaryAmt(This,pVal)

#define IOrder_put_discretionaryAmt(This,newVal)	\
    (This)->lpVtbl -> put_discretionaryAmt(This,newVal)

#define IOrder_get_eTradeOnly(This,pVal)	\
    (This)->lpVtbl -> get_eTradeOnly(This,pVal)

#define IOrder_put_eTradeOnly(This,newVal)	\
    (This)->lpVtbl -> put_eTradeOnly(This,newVal)

#define IOrder_get_firmQuoteOnly(This,pVal)	\
    (This)->lpVtbl -> get_firmQuoteOnly(This,pVal)

#define IOrder_put_firmQuoteOnly(This,newVal)	\
    (This)->lpVtbl -> put_firmQuoteOnly(This,newVal)

#define IOrder_get_nbboPriceCap(This,pVal)	\
    (This)->lpVtbl -> get_nbboPriceCap(This,pVal)

#define IOrder_put_nbboPriceCap(This,newVal)	\
    (This)->lpVtbl -> put_nbboPriceCap(This,newVal)

#define IOrder_get_optOutSmartRouting(This,pVal)	\
    (This)->lpVtbl -> get_optOutSmartRouting(This,pVal)

#define IOrder_put_optOutSmartRouting(This,newVal)	\
    (This)->lpVtbl -> put_optOutSmartRouting(This,newVal)

#define IOrder_get_auctionStrategy(This,pVal)	\
    (This)->lpVtbl -> get_auctionStrategy(This,pVal)

#define IOrder_put_auctionStrategy(This,newVal)	\
    (This)->lpVtbl -> put_auctionStrategy(This,newVal)

#define IOrder_get_startingPrice(This,pVal)	\
    (This)->lpVtbl -> get_startingPrice(This,pVal)

#define IOrder_put_startingPrice(This,newVal)	\
    (This)->lpVtbl -> put_startingPrice(This,newVal)

#define IOrder_get_stockRefPrice(This,pVal)	\
    (This)->lpVtbl -> get_stockRefPrice(This,pVal)

#define IOrder_put_stockRefPrice(This,newVal)	\
    (This)->lpVtbl -> put_stockRefPrice(This,newVal)

#define IOrder_get_delta(This,pVal)	\
    (This)->lpVtbl -> get_delta(This,pVal)

#define IOrder_put_delta(This,newVal)	\
    (This)->lpVtbl -> put_delta(This,newVal)

#define IOrder_get_stockRangeLower(This,pVal)	\
    (This)->lpVtbl -> get_stockRangeLower(This,pVal)

#define IOrder_put_stockRangeLower(This,newVal)	\
    (This)->lpVtbl -> put_stockRangeLower(This,newVal)

#define IOrder_get_stockRangeUpper(This,pVal)	\
    (This)->lpVtbl -> get_stockRangeUpper(This,pVal)

#define IOrder_put_stockRangeUpper(This,newVal)	\
    (This)->lpVtbl -> put_stockRangeUpper(This,newVal)

#define IOrder_get_volatility(This,pVal)	\
    (This)->lpVtbl -> get_volatility(This,pVal)

#define IOrder_put_volatility(This,newVal)	\
    (This)->lpVtbl -> put_volatility(This,newVal)

#define IOrder_get_volatilityType(This,pVal)	\
    (This)->lpVtbl -> get_volatilityType(This,pVal)

#define IOrder_put_volatilityType(This,newVal)	\
    (This)->lpVtbl -> put_volatilityType(This,newVal)

#define IOrder_get_continuousUpdate(This,pVal)	\
    (This)->lpVtbl -> get_continuousUpdate(This,pVal)

#define IOrder_put_continuousUpdate(This,newVal)	\
    (This)->lpVtbl -> put_continuousUpdate(This,newVal)

#define IOrder_get_referencePriceType(This,pVal)	\
    (This)->lpVtbl -> get_referencePriceType(This,pVal)

#define IOrder_put_referencePriceType(This,newVal)	\
    (This)->lpVtbl -> put_referencePriceType(This,newVal)

#define IOrder_get_deltaNeutralOrderType(This,pVal)	\
    (This)->lpVtbl -> get_deltaNeutralOrderType(This,pVal)

#define IOrder_put_deltaNeutralOrderType(This,newVal)	\
    (This)->lpVtbl -> put_deltaNeutralOrderType(This,newVal)

#define IOrder_get_deltaNeutralAuxPrice(This,pVal)	\
    (This)->lpVtbl -> get_deltaNeutralAuxPrice(This,pVal)

#define IOrder_put_deltaNeutralAuxPrice(This,newVal)	\
    (This)->lpVtbl -> put_deltaNeutralAuxPrice(This,newVal)

#define IOrder_get_deltaNeutralConId(This,pVal)	\
    (This)->lpVtbl -> get_deltaNeutralConId(This,pVal)

#define IOrder_put_deltaNeutralConId(This,newVal)	\
    (This)->lpVtbl -> put_deltaNeutralConId(This,newVal)

#define IOrder_get_deltaNeutralSettlingFirm(This,pVal)	\
    (This)->lpVtbl -> get_deltaNeutralSettlingFirm(This,pVal)

#define IOrder_put_deltaNeutralSettlingFirm(This,newVal)	\
    (This)->lpVtbl -> put_deltaNeutralSettlingFirm(This,newVal)

#define IOrder_get_deltaNeutralClearingAccount(This,pVal)	\
    (This)->lpVtbl -> get_deltaNeutralClearingAccount(This,pVal)

#define IOrder_put_deltaNeutralClearingAccount(This,newVal)	\
    (This)->lpVtbl -> put_deltaNeutralClearingAccount(This,newVal)

#define IOrder_get_deltaNeutralClearingIntent(This,pVal)	\
    (This)->lpVtbl -> get_deltaNeutralClearingIntent(This,pVal)

#define IOrder_put_deltaNeutralClearingIntent(This,newVal)	\
    (This)->lpVtbl -> put_deltaNeutralClearingIntent(This,newVal)

#define IOrder_get_deltaNeutralOpenClose(This,pVal)	\
    (This)->lpVtbl -> get_deltaNeutralOpenClose(This,pVal)

#define IOrder_put_deltaNeutralOpenClose(This,newVal)	\
    (This)->lpVtbl -> put_deltaNeutralOpenClose(This,newVal)

#define IOrder_get_deltaNeutralShortSale(This,pVal)	\
    (This)->lpVtbl -> get_deltaNeutralShortSale(This,pVal)

#define IOrder_put_deltaNeutralShortSale(This,newVal)	\
    (This)->lpVtbl -> put_deltaNeutralShortSale(This,newVal)

#define IOrder_get_deltaNeutralShortSaleSlot(This,pVal)	\
    (This)->lpVtbl -> get_deltaNeutralShortSaleSlot(This,pVal)

#define IOrder_put_deltaNeutralShortSaleSlot(This,newVal)	\
    (This)->lpVtbl -> put_deltaNeutralShortSaleSlot(This,newVal)

#define IOrder_get_deltaNeutralDesignatedLocation(This,pVal)	\
    (This)->lpVtbl -> get_deltaNeutralDesignatedLocation(This,pVal)

#define IOrder_put_deltaNeutralDesignatedLocation(This,newVal)	\
    (This)->lpVtbl -> put_deltaNeutralDesignatedLocation(This,newVal)

#define IOrder_get_basisPoints(This,pVal)	\
    (This)->lpVtbl -> get_basisPoints(This,pVal)

#define IOrder_put_basisPoints(This,newVal)	\
    (This)->lpVtbl -> put_basisPoints(This,newVal)

#define IOrder_get_basisPointsType(This,pVal)	\
    (This)->lpVtbl -> get_basisPointsType(This,pVal)

#define IOrder_put_basisPointsType(This,newVal)	\
    (This)->lpVtbl -> put_basisPointsType(This,newVal)

#define IOrder_get_scaleInitLevelSize(This,pVal)	\
    (This)->lpVtbl -> get_scaleInitLevelSize(This,pVal)

#define IOrder_put_scaleInitLevelSize(This,newVal)	\
    (This)->lpVtbl -> put_scaleInitLevelSize(This,newVal)

#define IOrder_get_scaleSubsLevelSize(This,pVal)	\
    (This)->lpVtbl -> get_scaleSubsLevelSize(This,pVal)

#define IOrder_put_scaleSubsLevelSize(This,newVal)	\
    (This)->lpVtbl -> put_scaleSubsLevelSize(This,newVal)

#define IOrder_get_scalePriceIncrement(This,pVal)	\
    (This)->lpVtbl -> get_scalePriceIncrement(This,pVal)

#define IOrder_put_scalePriceIncrement(This,newVal)	\
    (This)->lpVtbl -> put_scalePriceIncrement(This,newVal)

#define IOrder_get_scalePriceAdjustValue(This,pVal)	\
    (This)->lpVtbl -> get_scalePriceAdjustValue(This,pVal)

#define IOrder_put_scalePriceAdjustValue(This,newVal)	\
    (This)->lpVtbl -> put_scalePriceAdjustValue(This,newVal)

#define IOrder_get_scalePriceAdjustInterval(This,pVal)	\
    (This)->lpVtbl -> get_scalePriceAdjustInterval(This,pVal)

#define IOrder_put_scalePriceAdjustInterval(This,newVal)	\
    (This)->lpVtbl -> put_scalePriceAdjustInterval(This,newVal)

#define IOrder_get_scaleProfitOffset(This,pVal)	\
    (This)->lpVtbl -> get_scaleProfitOffset(This,pVal)

#define IOrder_put_scaleProfitOffset(This,newVal)	\
    (This)->lpVtbl -> put_scaleProfitOffset(This,newVal)

#define IOrder_get_scaleAutoReset(This,pVal)	\
    (This)->lpVtbl -> get_scaleAutoReset(This,pVal)

#define IOrder_put_scaleAutoReset(This,newVal)	\
    (This)->lpVtbl -> put_scaleAutoReset(This,newVal)

#define IOrder_get_scaleInitPosition(This,pVal)	\
    (This)->lpVtbl -> get_scaleInitPosition(This,pVal)

#define IOrder_put_scaleInitPosition(This,newVal)	\
    (This)->lpVtbl -> put_scaleInitPosition(This,newVal)

#define IOrder_get_scaleInitFillQty(This,pVal)	\
    (This)->lpVtbl -> get_scaleInitFillQty(This,pVal)

#define IOrder_put_scaleInitFillQty(This,newVal)	\
    (This)->lpVtbl -> put_scaleInitFillQty(This,newVal)

#define IOrder_get_scaleRandomPercent(This,pVal)	\
    (This)->lpVtbl -> get_scaleRandomPercent(This,pVal)

#define IOrder_put_scaleRandomPercent(This,newVal)	\
    (This)->lpVtbl -> put_scaleRandomPercent(This,newVal)

#define IOrder_get_scaleTable(This,pVal)	\
    (This)->lpVtbl -> get_scaleTable(This,pVal)

#define IOrder_put_scaleTable(This,newVal)	\
    (This)->lpVtbl -> put_scaleTable(This,newVal)

#define IOrder_get_hedgeType(This,pVal)	\
    (This)->lpVtbl -> get_hedgeType(This,pVal)

#define IOrder_put_hedgeType(This,newVal)	\
    (This)->lpVtbl -> put_hedgeType(This,newVal)

#define IOrder_get_hedgeParam(This,pVal)	\
    (This)->lpVtbl -> get_hedgeParam(This,pVal)

#define IOrder_put_hedgeParam(This,newVal)	\
    (This)->lpVtbl -> put_hedgeParam(This,newVal)

#define IOrder_get_account(This,pVal)	\
    (This)->lpVtbl -> get_account(This,pVal)

#define IOrder_put_account(This,newVal)	\
    (This)->lpVtbl -> put_account(This,newVal)

#define IOrder_get_settlingFirm(This,pVal)	\
    (This)->lpVtbl -> get_settlingFirm(This,pVal)

#define IOrder_put_settlingFirm(This,newVal)	\
    (This)->lpVtbl -> put_settlingFirm(This,newVal)

#define IOrder_get_clearingAccount(This,pVal)	\
    (This)->lpVtbl -> get_clearingAccount(This,pVal)

#define IOrder_put_clearingAccount(This,newVal)	\
    (This)->lpVtbl -> put_clearingAccount(This,newVal)

#define IOrder_get_clearingIntent(This,pVal)	\
    (This)->lpVtbl -> get_clearingIntent(This,pVal)

#define IOrder_put_clearingIntent(This,newVal)	\
    (This)->lpVtbl -> put_clearingIntent(This,newVal)

#define IOrder_get_algoStrategy(This,pVal)	\
    (This)->lpVtbl -> get_algoStrategy(This,pVal)

#define IOrder_put_algoStrategy(This,newVal)	\
    (This)->lpVtbl -> put_algoStrategy(This,newVal)

#define IOrder_get_algoParams(This,pVal)	\
    (This)->lpVtbl -> get_algoParams(This,pVal)

#define IOrder_putref_algoParams(This,newVal)	\
    (This)->lpVtbl -> putref_algoParams(This,newVal)

#define IOrder_get_smartComboRoutingParams(This,pVal)	\
    (This)->lpVtbl -> get_smartComboRoutingParams(This,pVal)

#define IOrder_putref_smartComboRoutingParams(This,newVal)	\
    (This)->lpVtbl -> putref_smartComboRoutingParams(This,newVal)

#define IOrder_get_orderComboLegs(This,pVal)	\
    (This)->lpVtbl -> get_orderComboLegs(This,pVal)

#define IOrder_putref_orderComboLegs(This,newVal)	\
    (This)->lpVtbl -> putref_orderComboLegs(This,newVal)

#define IOrder_get_orderMiscOptions(This,pVal)	\
    (This)->lpVtbl -> get_orderMiscOptions(This,pVal)

#define IOrder_putref_orderMiscOptions(This,newVal)	\
    (This)->lpVtbl -> putref_orderMiscOptions(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_orderId_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_orderId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_orderId_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_orderId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_clientId_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_clientId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_clientId_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_clientId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_permId_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_permId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_permId_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_permId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_action_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_action_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_action_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_action_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_totalQuantity_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_totalQuantity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_totalQuantity_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_totalQuantity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_orderType_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_orderType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_orderType_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_orderType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_lmtPrice_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_lmtPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_lmtPrice_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_lmtPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_auxPrice_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_auxPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_auxPrice_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_auxPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_timeInForce_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_timeInForce_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_timeInForce_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_timeInForce_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_activeStartTime_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_activeStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_activeStartTime_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_activeStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_activeStopTime_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_activeStopTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_activeStopTime_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_activeStopTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_ocaGroup_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_ocaGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_ocaGroup_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_ocaGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_ocaType_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_ocaType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_ocaType_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_ocaType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_orderRef_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_orderRef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_orderRef_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_orderRef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_transmit_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_transmit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_transmit_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_transmit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_parentId_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_parentId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_parentId_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_parentId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_blockOrder_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_blockOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_blockOrder_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_blockOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_sweepToFill_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_sweepToFill_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_sweepToFill_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_sweepToFill_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_displaySize_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_displaySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_displaySize_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_displaySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_triggerMethod_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_triggerMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_triggerMethod_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_triggerMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_outsideRth_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_outsideRth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_outsideRth_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_outsideRth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_hidden_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_hidden_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_hidden_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_hidden_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_goodAfterTime_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_goodAfterTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_goodAfterTime_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_goodAfterTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_goodTillDate_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_goodTillDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_goodTillDate_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_goodTillDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_overridePercentageConstraints_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_overridePercentageConstraints_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_overridePercentageConstraints_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_overridePercentageConstraints_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_rule80A_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_rule80A_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_rule80A_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_rule80A_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_allOrNone_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_allOrNone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_allOrNone_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_allOrNone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_minQty_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_minQty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_minQty_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_minQty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_percentOffset_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_percentOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_percentOffset_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_percentOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_trailStopPrice_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_trailStopPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_trailStopPrice_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_trailStopPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_trailingPercent_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_trailingPercent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_trailingPercent_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_trailingPercent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_whatIf_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_whatIf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_whatIf_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_whatIf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_notHeld_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_notHeld_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_notHeld_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_notHeld_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_faGroup_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_faGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_faGroup_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_faGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_faProfile_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_faProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_faProfile_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_faProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_faMethod_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_faMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_faMethod_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_faMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_faPercentage_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_faPercentage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_faPercentage_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_faPercentage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_openClose_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_openClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_openClose_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_openClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_origin_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_origin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_origin_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_origin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_shortSaleSlot_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_shortSaleSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_shortSaleSlot_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_shortSaleSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_designatedLocation_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_designatedLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_designatedLocation_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_designatedLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_exemptCode_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_exemptCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_exemptCode_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_exemptCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_discretionaryAmt_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_discretionaryAmt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_discretionaryAmt_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_discretionaryAmt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_eTradeOnly_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_eTradeOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_eTradeOnly_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_eTradeOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_firmQuoteOnly_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_firmQuoteOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_firmQuoteOnly_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_firmQuoteOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_nbboPriceCap_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_nbboPriceCap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_nbboPriceCap_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_nbboPriceCap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_optOutSmartRouting_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_optOutSmartRouting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_optOutSmartRouting_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_optOutSmartRouting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_auctionStrategy_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_auctionStrategy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_auctionStrategy_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_auctionStrategy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_startingPrice_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_startingPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_startingPrice_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_startingPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_stockRefPrice_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_stockRefPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_stockRefPrice_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_stockRefPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_delta_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_delta_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_delta_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_delta_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_stockRangeLower_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_stockRangeLower_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_stockRangeLower_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_stockRangeLower_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_stockRangeUpper_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_stockRangeUpper_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_stockRangeUpper_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_stockRangeUpper_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_volatility_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_volatility_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_volatility_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_volatility_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_volatilityType_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_volatilityType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_volatilityType_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_volatilityType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_continuousUpdate_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_continuousUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_continuousUpdate_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_continuousUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_referencePriceType_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_referencePriceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_referencePriceType_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_referencePriceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_deltaNeutralOrderType_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_deltaNeutralOrderType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_deltaNeutralOrderType_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_deltaNeutralOrderType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_deltaNeutralAuxPrice_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_deltaNeutralAuxPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_deltaNeutralAuxPrice_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_deltaNeutralAuxPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_deltaNeutralConId_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_deltaNeutralConId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_deltaNeutralConId_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_deltaNeutralConId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_deltaNeutralSettlingFirm_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_deltaNeutralSettlingFirm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_deltaNeutralSettlingFirm_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_deltaNeutralSettlingFirm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_deltaNeutralClearingAccount_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_deltaNeutralClearingAccount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_deltaNeutralClearingAccount_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_deltaNeutralClearingAccount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_deltaNeutralClearingIntent_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_deltaNeutralClearingIntent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_deltaNeutralClearingIntent_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_deltaNeutralClearingIntent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_deltaNeutralOpenClose_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_deltaNeutralOpenClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_deltaNeutralOpenClose_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_deltaNeutralOpenClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_deltaNeutralShortSale_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_deltaNeutralShortSale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_deltaNeutralShortSale_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_deltaNeutralShortSale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_deltaNeutralShortSaleSlot_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_deltaNeutralShortSaleSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_deltaNeutralShortSaleSlot_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_deltaNeutralShortSaleSlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_deltaNeutralDesignatedLocation_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_deltaNeutralDesignatedLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_deltaNeutralDesignatedLocation_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_deltaNeutralDesignatedLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_basisPoints_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_basisPoints_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_basisPoints_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_basisPoints_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_basisPointsType_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_basisPointsType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_basisPointsType_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_basisPointsType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scaleInitLevelSize_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_scaleInitLevelSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scaleInitLevelSize_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_scaleInitLevelSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scaleSubsLevelSize_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_scaleSubsLevelSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scaleSubsLevelSize_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_scaleSubsLevelSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scalePriceIncrement_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_scalePriceIncrement_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scalePriceIncrement_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_scalePriceIncrement_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scalePriceAdjustValue_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_scalePriceAdjustValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scalePriceAdjustValue_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_scalePriceAdjustValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scalePriceAdjustInterval_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_scalePriceAdjustInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scalePriceAdjustInterval_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_scalePriceAdjustInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scaleProfitOffset_Proxy( 
    IOrder * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrder_get_scaleProfitOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scaleProfitOffset_Proxy( 
    IOrder * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrder_put_scaleProfitOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scaleAutoReset_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_scaleAutoReset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scaleAutoReset_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_scaleAutoReset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scaleInitPosition_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_scaleInitPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scaleInitPosition_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_scaleInitPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scaleInitFillQty_Proxy( 
    IOrder * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrder_get_scaleInitFillQty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scaleInitFillQty_Proxy( 
    IOrder * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IOrder_put_scaleInitFillQty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scaleRandomPercent_Proxy( 
    IOrder * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IOrder_get_scaleRandomPercent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scaleRandomPercent_Proxy( 
    IOrder * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IOrder_put_scaleRandomPercent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_scaleTable_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_scaleTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_scaleTable_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_scaleTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_hedgeType_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_hedgeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_hedgeType_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_hedgeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_hedgeParam_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_hedgeParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_hedgeParam_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_hedgeParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_account_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_account_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_account_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_account_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_settlingFirm_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_settlingFirm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_settlingFirm_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_settlingFirm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_clearingAccount_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_clearingAccount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_clearingAccount_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_clearingAccount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_clearingIntent_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_clearingIntent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_clearingIntent_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_clearingIntent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_algoStrategy_Proxy( 
    IOrder * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrder_get_algoStrategy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrder_put_algoStrategy_Proxy( 
    IOrder * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOrder_put_algoStrategy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_algoParams_Proxy( 
    IOrder * This,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB IOrder_get_algoParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE IOrder_putref_algoParams_Proxy( 
    IOrder * This,
    /* [in] */ IDispatch *newVal);


void __RPC_STUB IOrder_putref_algoParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_smartComboRoutingParams_Proxy( 
    IOrder * This,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB IOrder_get_smartComboRoutingParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE IOrder_putref_smartComboRoutingParams_Proxy( 
    IOrder * This,
    /* [in] */ IDispatch *newVal);


void __RPC_STUB IOrder_putref_smartComboRoutingParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_orderComboLegs_Proxy( 
    IOrder * This,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB IOrder_get_orderComboLegs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE IOrder_putref_orderComboLegs_Proxy( 
    IOrder * This,
    /* [in] */ IDispatch *newVal);


void __RPC_STUB IOrder_putref_orderComboLegs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrder_get_orderMiscOptions_Proxy( 
    IOrder * This,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB IOrder_get_orderMiscOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE IOrder_putref_orderMiscOptions_Proxy( 
    IOrder * This,
    /* [in] */ IDispatch *newVal);


void __RPC_STUB IOrder_putref_orderMiscOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOrder_INTERFACE_DEFINED__ */


#ifndef __IOrderState_INTERFACE_DEFINED__
#define __IOrderState_INTERFACE_DEFINED__

/* interface IOrderState */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOrderState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7B33AE1F-99B0-4BCB-A024-42335897A6AF")
    IOrderState : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_status( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_initMargin( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_maintMargin( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_equityWithLoan( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_commission( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_minCommission( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_maxCommission( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_commissionCurrency( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_warningText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOrderStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOrderState * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOrderState * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOrderState * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOrderState * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOrderState * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOrderState * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOrderState * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_status )( 
            IOrderState * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_initMargin )( 
            IOrderState * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_maintMargin )( 
            IOrderState * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_equityWithLoan )( 
            IOrderState * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_commission )( 
            IOrderState * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_minCommission )( 
            IOrderState * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_maxCommission )( 
            IOrderState * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_commissionCurrency )( 
            IOrderState * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_warningText )( 
            IOrderState * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IOrderStateVtbl;

    interface IOrderState
    {
        CONST_VTBL struct IOrderStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOrderState_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOrderState_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOrderState_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOrderState_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOrderState_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOrderState_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOrderState_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOrderState_get_status(This,pVal)	\
    (This)->lpVtbl -> get_status(This,pVal)

#define IOrderState_get_initMargin(This,pVal)	\
    (This)->lpVtbl -> get_initMargin(This,pVal)

#define IOrderState_get_maintMargin(This,pVal)	\
    (This)->lpVtbl -> get_maintMargin(This,pVal)

#define IOrderState_get_equityWithLoan(This,pVal)	\
    (This)->lpVtbl -> get_equityWithLoan(This,pVal)

#define IOrderState_get_commission(This,pVal)	\
    (This)->lpVtbl -> get_commission(This,pVal)

#define IOrderState_get_minCommission(This,pVal)	\
    (This)->lpVtbl -> get_minCommission(This,pVal)

#define IOrderState_get_maxCommission(This,pVal)	\
    (This)->lpVtbl -> get_maxCommission(This,pVal)

#define IOrderState_get_commissionCurrency(This,pVal)	\
    (This)->lpVtbl -> get_commissionCurrency(This,pVal)

#define IOrderState_get_warningText(This,pVal)	\
    (This)->lpVtbl -> get_warningText(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrderState_get_status_Proxy( 
    IOrderState * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrderState_get_status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrderState_get_initMargin_Proxy( 
    IOrderState * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrderState_get_initMargin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrderState_get_maintMargin_Proxy( 
    IOrderState * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrderState_get_maintMargin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrderState_get_equityWithLoan_Proxy( 
    IOrderState * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrderState_get_equityWithLoan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrderState_get_commission_Proxy( 
    IOrderState * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrderState_get_commission_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrderState_get_minCommission_Proxy( 
    IOrderState * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrderState_get_minCommission_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrderState_get_maxCommission_Proxy( 
    IOrderState * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrderState_get_maxCommission_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrderState_get_commissionCurrency_Proxy( 
    IOrderState * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrderState_get_commissionCurrency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrderState_get_warningText_Proxy( 
    IOrderState * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IOrderState_get_warningText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOrderState_INTERFACE_DEFINED__ */


#ifndef __IExecution_INTERFACE_DEFINED__
#define __IExecution_INTERFACE_DEFINED__

/* interface IExecution */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IExecution;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58BDEC36-791C-4E2E-88A4-6E4339392B5B")
    IExecution : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_execId( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_orderId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_clientId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_permId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_time( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_acctNumber( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_exchange( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_side( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_shares( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_price( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_liquidation( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_cumQty( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_avgPrice( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_orderRef( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_evRule( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_evMultiplier( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExecutionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExecution * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExecution * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExecution * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IExecution * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IExecution * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IExecution * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IExecution * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_execId )( 
            IExecution * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_orderId )( 
            IExecution * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_clientId )( 
            IExecution * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_permId )( 
            IExecution * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_time )( 
            IExecution * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_acctNumber )( 
            IExecution * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_exchange )( 
            IExecution * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_side )( 
            IExecution * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_shares )( 
            IExecution * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_price )( 
            IExecution * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_liquidation )( 
            IExecution * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_cumQty )( 
            IExecution * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_avgPrice )( 
            IExecution * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_orderRef )( 
            IExecution * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_evRule )( 
            IExecution * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_evMultiplier )( 
            IExecution * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        END_INTERFACE
    } IExecutionVtbl;

    interface IExecution
    {
        CONST_VTBL struct IExecutionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExecution_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExecution_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExecution_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExecution_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExecution_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExecution_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExecution_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExecution_get_execId(This,pVal)	\
    (This)->lpVtbl -> get_execId(This,pVal)

#define IExecution_get_orderId(This,pVal)	\
    (This)->lpVtbl -> get_orderId(This,pVal)

#define IExecution_get_clientId(This,pVal)	\
    (This)->lpVtbl -> get_clientId(This,pVal)

#define IExecution_get_permId(This,pVal)	\
    (This)->lpVtbl -> get_permId(This,pVal)

#define IExecution_get_time(This,pVal)	\
    (This)->lpVtbl -> get_time(This,pVal)

#define IExecution_get_acctNumber(This,pVal)	\
    (This)->lpVtbl -> get_acctNumber(This,pVal)

#define IExecution_get_exchange(This,pVal)	\
    (This)->lpVtbl -> get_exchange(This,pVal)

#define IExecution_get_side(This,pVal)	\
    (This)->lpVtbl -> get_side(This,pVal)

#define IExecution_get_shares(This,pVal)	\
    (This)->lpVtbl -> get_shares(This,pVal)

#define IExecution_get_price(This,pVal)	\
    (This)->lpVtbl -> get_price(This,pVal)

#define IExecution_get_liquidation(This,pVal)	\
    (This)->lpVtbl -> get_liquidation(This,pVal)

#define IExecution_get_cumQty(This,pVal)	\
    (This)->lpVtbl -> get_cumQty(This,pVal)

#define IExecution_get_avgPrice(This,pVal)	\
    (This)->lpVtbl -> get_avgPrice(This,pVal)

#define IExecution_get_orderRef(This,pVal)	\
    (This)->lpVtbl -> get_orderRef(This,pVal)

#define IExecution_get_evRule(This,pVal)	\
    (This)->lpVtbl -> get_evRule(This,pVal)

#define IExecution_get_evMultiplier(This,pVal)	\
    (This)->lpVtbl -> get_evMultiplier(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_execId_Proxy( 
    IExecution * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecution_get_execId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_orderId_Proxy( 
    IExecution * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IExecution_get_orderId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_clientId_Proxy( 
    IExecution * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IExecution_get_clientId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_permId_Proxy( 
    IExecution * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IExecution_get_permId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_time_Proxy( 
    IExecution * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecution_get_time_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_acctNumber_Proxy( 
    IExecution * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecution_get_acctNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_exchange_Proxy( 
    IExecution * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecution_get_exchange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_side_Proxy( 
    IExecution * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecution_get_side_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_shares_Proxy( 
    IExecution * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IExecution_get_shares_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_price_Proxy( 
    IExecution * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IExecution_get_price_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_liquidation_Proxy( 
    IExecution * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IExecution_get_liquidation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_cumQty_Proxy( 
    IExecution * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IExecution_get_cumQty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_avgPrice_Proxy( 
    IExecution * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IExecution_get_avgPrice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_orderRef_Proxy( 
    IExecution * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecution_get_orderRef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_evRule_Proxy( 
    IExecution * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecution_get_evRule_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecution_get_evMultiplier_Proxy( 
    IExecution * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IExecution_get_evMultiplier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExecution_INTERFACE_DEFINED__ */


#ifndef __IExecutionFilter_INTERFACE_DEFINED__
#define __IExecutionFilter_INTERFACE_DEFINED__

/* interface IExecutionFilter */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IExecutionFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3553EA07-F281-433D-B2A4-4CB722A9859B")
    IExecutionFilter : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_clientId( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_clientId( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_acctCode( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_acctCode( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_time( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_time( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_symbol( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_symbol( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_secType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_secType( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_exchange( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_exchange( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_side( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_side( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExecutionFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExecutionFilter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExecutionFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExecutionFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IExecutionFilter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IExecutionFilter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IExecutionFilter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IExecutionFilter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_clientId )( 
            IExecutionFilter * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_clientId )( 
            IExecutionFilter * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_acctCode )( 
            IExecutionFilter * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_acctCode )( 
            IExecutionFilter * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_time )( 
            IExecutionFilter * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_time )( 
            IExecutionFilter * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_symbol )( 
            IExecutionFilter * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_symbol )( 
            IExecutionFilter * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_secType )( 
            IExecutionFilter * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_secType )( 
            IExecutionFilter * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_exchange )( 
            IExecutionFilter * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_exchange )( 
            IExecutionFilter * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_side )( 
            IExecutionFilter * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_side )( 
            IExecutionFilter * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IExecutionFilterVtbl;

    interface IExecutionFilter
    {
        CONST_VTBL struct IExecutionFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExecutionFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExecutionFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExecutionFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExecutionFilter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExecutionFilter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExecutionFilter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExecutionFilter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExecutionFilter_get_clientId(This,pVal)	\
    (This)->lpVtbl -> get_clientId(This,pVal)

#define IExecutionFilter_put_clientId(This,newVal)	\
    (This)->lpVtbl -> put_clientId(This,newVal)

#define IExecutionFilter_get_acctCode(This,pVal)	\
    (This)->lpVtbl -> get_acctCode(This,pVal)

#define IExecutionFilter_put_acctCode(This,newVal)	\
    (This)->lpVtbl -> put_acctCode(This,newVal)

#define IExecutionFilter_get_time(This,pVal)	\
    (This)->lpVtbl -> get_time(This,pVal)

#define IExecutionFilter_put_time(This,newVal)	\
    (This)->lpVtbl -> put_time(This,newVal)

#define IExecutionFilter_get_symbol(This,pVal)	\
    (This)->lpVtbl -> get_symbol(This,pVal)

#define IExecutionFilter_put_symbol(This,newVal)	\
    (This)->lpVtbl -> put_symbol(This,newVal)

#define IExecutionFilter_get_secType(This,pVal)	\
    (This)->lpVtbl -> get_secType(This,pVal)

#define IExecutionFilter_put_secType(This,newVal)	\
    (This)->lpVtbl -> put_secType(This,newVal)

#define IExecutionFilter_get_exchange(This,pVal)	\
    (This)->lpVtbl -> get_exchange(This,pVal)

#define IExecutionFilter_put_exchange(This,newVal)	\
    (This)->lpVtbl -> put_exchange(This,newVal)

#define IExecutionFilter_get_side(This,pVal)	\
    (This)->lpVtbl -> get_side(This,pVal)

#define IExecutionFilter_put_side(This,newVal)	\
    (This)->lpVtbl -> put_side(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_get_clientId_Proxy( 
    IExecutionFilter * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IExecutionFilter_get_clientId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_put_clientId_Proxy( 
    IExecutionFilter * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IExecutionFilter_put_clientId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_get_acctCode_Proxy( 
    IExecutionFilter * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecutionFilter_get_acctCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_put_acctCode_Proxy( 
    IExecutionFilter * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IExecutionFilter_put_acctCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_get_time_Proxy( 
    IExecutionFilter * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecutionFilter_get_time_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_put_time_Proxy( 
    IExecutionFilter * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IExecutionFilter_put_time_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_get_symbol_Proxy( 
    IExecutionFilter * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecutionFilter_get_symbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_put_symbol_Proxy( 
    IExecutionFilter * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IExecutionFilter_put_symbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_get_secType_Proxy( 
    IExecutionFilter * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecutionFilter_get_secType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_put_secType_Proxy( 
    IExecutionFilter * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IExecutionFilter_put_secType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_get_exchange_Proxy( 
    IExecutionFilter * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecutionFilter_get_exchange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_put_exchange_Proxy( 
    IExecutionFilter * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IExecutionFilter_put_exchange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_get_side_Proxy( 
    IExecutionFilter * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IExecutionFilter_get_side_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IExecutionFilter_put_side_Proxy( 
    IExecutionFilter * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IExecutionFilter_put_side_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExecutionFilter_INTERFACE_DEFINED__ */


#ifndef __IScannerSubscription_INTERFACE_DEFINED__
#define __IScannerSubscription_INTERFACE_DEFINED__

/* interface IScannerSubscription */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IScannerSubscription;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6BBE7E50-795D-4C45-A69E-E1EEB7918DD2")
    IScannerSubscription : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_instrument( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_instrument( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_locations( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_locations( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scanCode( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scanCode( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_numberOfRows( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_numberOfRows( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_priceAbove( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_priceAbove( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_priceBelow( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_priceBelow( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_volumeAbove( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_volumeAbove( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_averageOptionVolumeAbove( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_averageOptionVolumeAbove( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_marketCapAbove( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_marketCapAbove( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_marketCapBelow( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_marketCapBelow( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moodyRatingAbove( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moodyRatingAbove( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moodyRatingBelow( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moodyRatingBelow( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_spRatingAbove( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_spRatingAbove( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_spRatingBelow( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_spRatingBelow( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_maturityDateAbove( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_maturityDateAbove( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_maturityDateBelow( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_maturityDateBelow( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_couponRateAbove( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_couponRateAbove( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_couponRateBelow( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_couponRateBelow( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_excludeConvertible( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_excludeConvertible( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_scannerSettingPairs( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_scannerSettingPairs( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_stockTypeFilter( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_stockTypeFilter( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScannerSubscriptionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScannerSubscription * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScannerSubscription * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScannerSubscription * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IScannerSubscription * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IScannerSubscription * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IScannerSubscription * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IScannerSubscription * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_instrument )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_instrument )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_locations )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_locations )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scanCode )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scanCode )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_numberOfRows )( 
            IScannerSubscription * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_numberOfRows )( 
            IScannerSubscription * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_priceAbove )( 
            IScannerSubscription * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_priceAbove )( 
            IScannerSubscription * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_priceBelow )( 
            IScannerSubscription * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_priceBelow )( 
            IScannerSubscription * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_volumeAbove )( 
            IScannerSubscription * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_volumeAbove )( 
            IScannerSubscription * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_averageOptionVolumeAbove )( 
            IScannerSubscription * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_averageOptionVolumeAbove )( 
            IScannerSubscription * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_marketCapAbove )( 
            IScannerSubscription * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_marketCapAbove )( 
            IScannerSubscription * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_marketCapBelow )( 
            IScannerSubscription * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_marketCapBelow )( 
            IScannerSubscription * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moodyRatingAbove )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moodyRatingAbove )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moodyRatingBelow )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moodyRatingBelow )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_spRatingAbove )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_spRatingAbove )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_spRatingBelow )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_spRatingBelow )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_maturityDateAbove )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_maturityDateAbove )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_maturityDateBelow )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_maturityDateBelow )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_couponRateAbove )( 
            IScannerSubscription * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_couponRateAbove )( 
            IScannerSubscription * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_couponRateBelow )( 
            IScannerSubscription * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_couponRateBelow )( 
            IScannerSubscription * This,
            /* [in] */ DOUBLE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_excludeConvertible )( 
            IScannerSubscription * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_excludeConvertible )( 
            IScannerSubscription * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_scannerSettingPairs )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_scannerSettingPairs )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_stockTypeFilter )( 
            IScannerSubscription * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_stockTypeFilter )( 
            IScannerSubscription * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IScannerSubscriptionVtbl;

    interface IScannerSubscription
    {
        CONST_VTBL struct IScannerSubscriptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScannerSubscription_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IScannerSubscription_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IScannerSubscription_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IScannerSubscription_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IScannerSubscription_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IScannerSubscription_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IScannerSubscription_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IScannerSubscription_get_instrument(This,pVal)	\
    (This)->lpVtbl -> get_instrument(This,pVal)

#define IScannerSubscription_put_instrument(This,newVal)	\
    (This)->lpVtbl -> put_instrument(This,newVal)

#define IScannerSubscription_get_locations(This,pVal)	\
    (This)->lpVtbl -> get_locations(This,pVal)

#define IScannerSubscription_put_locations(This,newVal)	\
    (This)->lpVtbl -> put_locations(This,newVal)

#define IScannerSubscription_get_scanCode(This,pVal)	\
    (This)->lpVtbl -> get_scanCode(This,pVal)

#define IScannerSubscription_put_scanCode(This,newVal)	\
    (This)->lpVtbl -> put_scanCode(This,newVal)

#define IScannerSubscription_get_numberOfRows(This,pVal)	\
    (This)->lpVtbl -> get_numberOfRows(This,pVal)

#define IScannerSubscription_put_numberOfRows(This,newVal)	\
    (This)->lpVtbl -> put_numberOfRows(This,newVal)

#define IScannerSubscription_get_priceAbove(This,pVal)	\
    (This)->lpVtbl -> get_priceAbove(This,pVal)

#define IScannerSubscription_put_priceAbove(This,newVal)	\
    (This)->lpVtbl -> put_priceAbove(This,newVal)

#define IScannerSubscription_get_priceBelow(This,pVal)	\
    (This)->lpVtbl -> get_priceBelow(This,pVal)

#define IScannerSubscription_put_priceBelow(This,newVal)	\
    (This)->lpVtbl -> put_priceBelow(This,newVal)

#define IScannerSubscription_get_volumeAbove(This,pVal)	\
    (This)->lpVtbl -> get_volumeAbove(This,pVal)

#define IScannerSubscription_put_volumeAbove(This,newVal)	\
    (This)->lpVtbl -> put_volumeAbove(This,newVal)

#define IScannerSubscription_get_averageOptionVolumeAbove(This,pVal)	\
    (This)->lpVtbl -> get_averageOptionVolumeAbove(This,pVal)

#define IScannerSubscription_put_averageOptionVolumeAbove(This,newVal)	\
    (This)->lpVtbl -> put_averageOptionVolumeAbove(This,newVal)

#define IScannerSubscription_get_marketCapAbove(This,pVal)	\
    (This)->lpVtbl -> get_marketCapAbove(This,pVal)

#define IScannerSubscription_put_marketCapAbove(This,newVal)	\
    (This)->lpVtbl -> put_marketCapAbove(This,newVal)

#define IScannerSubscription_get_marketCapBelow(This,pVal)	\
    (This)->lpVtbl -> get_marketCapBelow(This,pVal)

#define IScannerSubscription_put_marketCapBelow(This,newVal)	\
    (This)->lpVtbl -> put_marketCapBelow(This,newVal)

#define IScannerSubscription_get_moodyRatingAbove(This,pVal)	\
    (This)->lpVtbl -> get_moodyRatingAbove(This,pVal)

#define IScannerSubscription_put_moodyRatingAbove(This,newVal)	\
    (This)->lpVtbl -> put_moodyRatingAbove(This,newVal)

#define IScannerSubscription_get_moodyRatingBelow(This,pVal)	\
    (This)->lpVtbl -> get_moodyRatingBelow(This,pVal)

#define IScannerSubscription_put_moodyRatingBelow(This,newVal)	\
    (This)->lpVtbl -> put_moodyRatingBelow(This,newVal)

#define IScannerSubscription_get_spRatingAbove(This,pVal)	\
    (This)->lpVtbl -> get_spRatingAbove(This,pVal)

#define IScannerSubscription_put_spRatingAbove(This,newVal)	\
    (This)->lpVtbl -> put_spRatingAbove(This,newVal)

#define IScannerSubscription_get_spRatingBelow(This,pVal)	\
    (This)->lpVtbl -> get_spRatingBelow(This,pVal)

#define IScannerSubscription_put_spRatingBelow(This,newVal)	\
    (This)->lpVtbl -> put_spRatingBelow(This,newVal)

#define IScannerSubscription_get_maturityDateAbove(This,pVal)	\
    (This)->lpVtbl -> get_maturityDateAbove(This,pVal)

#define IScannerSubscription_put_maturityDateAbove(This,newVal)	\
    (This)->lpVtbl -> put_maturityDateAbove(This,newVal)

#define IScannerSubscription_get_maturityDateBelow(This,pVal)	\
    (This)->lpVtbl -> get_maturityDateBelow(This,pVal)

#define IScannerSubscription_put_maturityDateBelow(This,newVal)	\
    (This)->lpVtbl -> put_maturityDateBelow(This,newVal)

#define IScannerSubscription_get_couponRateAbove(This,pVal)	\
    (This)->lpVtbl -> get_couponRateAbove(This,pVal)

#define IScannerSubscription_put_couponRateAbove(This,newVal)	\
    (This)->lpVtbl -> put_couponRateAbove(This,newVal)

#define IScannerSubscription_get_couponRateBelow(This,pVal)	\
    (This)->lpVtbl -> get_couponRateBelow(This,pVal)

#define IScannerSubscription_put_couponRateBelow(This,newVal)	\
    (This)->lpVtbl -> put_couponRateBelow(This,newVal)

#define IScannerSubscription_get_excludeConvertible(This,pVal)	\
    (This)->lpVtbl -> get_excludeConvertible(This,pVal)

#define IScannerSubscription_put_excludeConvertible(This,newVal)	\
    (This)->lpVtbl -> put_excludeConvertible(This,newVal)

#define IScannerSubscription_get_scannerSettingPairs(This,pVal)	\
    (This)->lpVtbl -> get_scannerSettingPairs(This,pVal)

#define IScannerSubscription_put_scannerSettingPairs(This,newVal)	\
    (This)->lpVtbl -> put_scannerSettingPairs(This,newVal)

#define IScannerSubscription_get_stockTypeFilter(This,pVal)	\
    (This)->lpVtbl -> get_stockTypeFilter(This,pVal)

#define IScannerSubscription_put_stockTypeFilter(This,newVal)	\
    (This)->lpVtbl -> put_stockTypeFilter(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_instrument_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_instrument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_instrument_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_instrument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_locations_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_locations_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_locations_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_locations_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_scanCode_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_scanCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_scanCode_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_scanCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_numberOfRows_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IScannerSubscription_get_numberOfRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_numberOfRows_Proxy( 
    IScannerSubscription * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IScannerSubscription_put_numberOfRows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_priceAbove_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IScannerSubscription_get_priceAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_priceAbove_Proxy( 
    IScannerSubscription * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IScannerSubscription_put_priceAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_priceBelow_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IScannerSubscription_get_priceBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_priceBelow_Proxy( 
    IScannerSubscription * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IScannerSubscription_put_priceBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_volumeAbove_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IScannerSubscription_get_volumeAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_volumeAbove_Proxy( 
    IScannerSubscription * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IScannerSubscription_put_volumeAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_averageOptionVolumeAbove_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IScannerSubscription_get_averageOptionVolumeAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_averageOptionVolumeAbove_Proxy( 
    IScannerSubscription * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IScannerSubscription_put_averageOptionVolumeAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_marketCapAbove_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IScannerSubscription_get_marketCapAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_marketCapAbove_Proxy( 
    IScannerSubscription * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IScannerSubscription_put_marketCapAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_marketCapBelow_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IScannerSubscription_get_marketCapBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_marketCapBelow_Proxy( 
    IScannerSubscription * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IScannerSubscription_put_marketCapBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_moodyRatingAbove_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_moodyRatingAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_moodyRatingAbove_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_moodyRatingAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_moodyRatingBelow_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_moodyRatingBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_moodyRatingBelow_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_moodyRatingBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_spRatingAbove_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_spRatingAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_spRatingAbove_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_spRatingAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_spRatingBelow_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_spRatingBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_spRatingBelow_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_spRatingBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_maturityDateAbove_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_maturityDateAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_maturityDateAbove_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_maturityDateAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_maturityDateBelow_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_maturityDateBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_maturityDateBelow_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_maturityDateBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_couponRateAbove_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IScannerSubscription_get_couponRateAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_couponRateAbove_Proxy( 
    IScannerSubscription * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IScannerSubscription_put_couponRateAbove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_couponRateBelow_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IScannerSubscription_get_couponRateBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_couponRateBelow_Proxy( 
    IScannerSubscription * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IScannerSubscription_put_couponRateBelow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_excludeConvertible_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IScannerSubscription_get_excludeConvertible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_excludeConvertible_Proxy( 
    IScannerSubscription * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IScannerSubscription_put_excludeConvertible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_scannerSettingPairs_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_scannerSettingPairs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_scannerSettingPairs_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_scannerSettingPairs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_get_stockTypeFilter_Proxy( 
    IScannerSubscription * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IScannerSubscription_get_stockTypeFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IScannerSubscription_put_stockTypeFilter_Proxy( 
    IScannerSubscription * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IScannerSubscription_put_stockTypeFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IScannerSubscription_INTERFACE_DEFINED__ */


#ifndef __IOrderComboLeg_INTERFACE_DEFINED__
#define __IOrderComboLeg_INTERFACE_DEFINED__

/* interface IOrderComboLeg */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOrderComboLeg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("639C4479-D0B6-49a3-B524-AEA6A9574945")
    IOrderComboLeg : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_price( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_price( 
            /* [in] */ DOUBLE newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOrderComboLegVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOrderComboLeg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOrderComboLeg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOrderComboLeg * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOrderComboLeg * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOrderComboLeg * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOrderComboLeg * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOrderComboLeg * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_price )( 
            IOrderComboLeg * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_price )( 
            IOrderComboLeg * This,
            /* [in] */ DOUBLE newVal);
        
        END_INTERFACE
    } IOrderComboLegVtbl;

    interface IOrderComboLeg
    {
        CONST_VTBL struct IOrderComboLegVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOrderComboLeg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOrderComboLeg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOrderComboLeg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOrderComboLeg_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOrderComboLeg_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOrderComboLeg_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOrderComboLeg_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOrderComboLeg_get_price(This,pVal)	\
    (This)->lpVtbl -> get_price(This,pVal)

#define IOrderComboLeg_put_price(This,newVal)	\
    (This)->lpVtbl -> put_price(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOrderComboLeg_get_price_Proxy( 
    IOrderComboLeg * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB IOrderComboLeg_get_price_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOrderComboLeg_put_price_Proxy( 
    IOrderComboLeg * This,
    /* [in] */ DOUBLE newVal);


void __RPC_STUB IOrderComboLeg_put_price_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOrderComboLeg_INTERFACE_DEFINED__ */


#ifndef __IOrderComboLegList_INTERFACE_DEFINED__
#define __IOrderComboLegList_INTERFACE_DEFINED__

/* interface IOrderComboLegList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOrderComboLegList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("39F18DDF-687D-421d-8BB9-4F389D69E428")
    IOrderComboLegList : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG index,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IDispatch **leg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOrderComboLegListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOrderComboLegList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOrderComboLegList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOrderComboLegList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOrderComboLegList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOrderComboLegList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOrderComboLegList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOrderComboLegList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IOrderComboLegList * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IOrderComboLegList * This,
            /* [in] */ LONG index,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IOrderComboLegList * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IOrderComboLegList * This,
            /* [retval][out] */ IDispatch **leg);
        
        END_INTERFACE
    } IOrderComboLegListVtbl;

    interface IOrderComboLegList
    {
        CONST_VTBL struct IOrderComboLegListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOrderComboLegList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOrderComboLegList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOrderComboLegList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOrderComboLegList_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOrderComboLegList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOrderComboLegList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOrderComboLegList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOrderComboLegList_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define IOrderComboLegList_get_Item(This,index,pVal)	\
    (This)->lpVtbl -> get_Item(This,index,pVal)

#define IOrderComboLegList_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IOrderComboLegList_Add(This,leg)	\
    (This)->lpVtbl -> Add(This,leg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IOrderComboLegList_get__NewEnum_Proxy( 
    IOrderComboLegList * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB IOrderComboLegList_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IOrderComboLegList_get_Item_Proxy( 
    IOrderComboLegList * This,
    /* [in] */ LONG index,
    /* [retval][out] */ IDispatch **pVal);


void __RPC_STUB IOrderComboLegList_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IOrderComboLegList_get_Count_Proxy( 
    IOrderComboLegList * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB IOrderComboLegList_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOrderComboLegList_Add_Proxy( 
    IOrderComboLegList * This,
    /* [retval][out] */ IDispatch **leg);


void __RPC_STUB IOrderComboLegList_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOrderComboLegList_INTERFACE_DEFINED__ */


#ifndef __ICommissionReport_INTERFACE_DEFINED__
#define __ICommissionReport_INTERFACE_DEFINED__

/* interface ICommissionReport */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICommissionReport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51AE469F-D859-4537-A0BA-A93992F395BB")
    ICommissionReport : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_execId( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_commission( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_currency( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_realizedPNL( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_yield( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_yieldRedemptionDate( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICommissionReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICommissionReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICommissionReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICommissionReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICommissionReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICommissionReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICommissionReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICommissionReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_execId )( 
            ICommissionReport * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_commission )( 
            ICommissionReport * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_currency )( 
            ICommissionReport * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_realizedPNL )( 
            ICommissionReport * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_yield )( 
            ICommissionReport * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_yieldRedemptionDate )( 
            ICommissionReport * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } ICommissionReportVtbl;

    interface ICommissionReport
    {
        CONST_VTBL struct ICommissionReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICommissionReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICommissionReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICommissionReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICommissionReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICommissionReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICommissionReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICommissionReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICommissionReport_get_execId(This,pVal)	\
    (This)->lpVtbl -> get_execId(This,pVal)

#define ICommissionReport_get_commission(This,pVal)	\
    (This)->lpVtbl -> get_commission(This,pVal)

#define ICommissionReport_get_currency(This,pVal)	\
    (This)->lpVtbl -> get_currency(This,pVal)

#define ICommissionReport_get_realizedPNL(This,pVal)	\
    (This)->lpVtbl -> get_realizedPNL(This,pVal)

#define ICommissionReport_get_yield(This,pVal)	\
    (This)->lpVtbl -> get_yield(This,pVal)

#define ICommissionReport_get_yieldRedemptionDate(This,pVal)	\
    (This)->lpVtbl -> get_yieldRedemptionDate(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICommissionReport_get_execId_Proxy( 
    ICommissionReport * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ICommissionReport_get_execId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICommissionReport_get_commission_Proxy( 
    ICommissionReport * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB ICommissionReport_get_commission_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICommissionReport_get_currency_Proxy( 
    ICommissionReport * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ICommissionReport_get_currency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICommissionReport_get_realizedPNL_Proxy( 
    ICommissionReport * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB ICommissionReport_get_realizedPNL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICommissionReport_get_yield_Proxy( 
    ICommissionReport * This,
    /* [retval][out] */ DOUBLE *pVal);


void __RPC_STUB ICommissionReport_get_yield_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICommissionReport_get_yieldRedemptionDate_Proxy( 
    ICommissionReport * This,
    /* [retval][out] */ LONG *pVal);


void __RPC_STUB ICommissionReport_get_yieldRedemptionDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICommissionReport_INTERFACE_DEFINED__ */


#ifndef ___DTws_DISPINTERFACE_DEFINED__
#define ___DTws_DISPINTERFACE_DEFINED__

/* dispinterface _DTws */
/* [hidden][helpstring][uuid] */ 


EXTERN_C const IID DIID__DTws;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0A77CCF6-052C-11D6-B0EC-00B0D074179C")
    _DTws : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DTwsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DTws * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DTws * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DTws * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DTws * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DTws * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DTws * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DTws * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DTwsVtbl;

    interface _DTws
    {
        CONST_VTBL struct _DTwsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DTws_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DTws_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DTws_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DTws_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DTws_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DTws_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DTws_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DTws_DISPINTERFACE_DEFINED__ */


#ifndef ___DTwsEvents_DISPINTERFACE_DEFINED__
#define ___DTwsEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DTwsEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DTwsEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0A77CCF7-052C-11D6-B0EC-00B0D074179C")
    _DTwsEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DTwsEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DTwsEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DTwsEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DTwsEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DTwsEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DTwsEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DTwsEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DTwsEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DTwsEventsVtbl;

    interface _DTwsEvents
    {
        CONST_VTBL struct _DTwsEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DTwsEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DTwsEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DTwsEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DTwsEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DTwsEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DTwsEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DTwsEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DTwsEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Tws;

#ifdef __cplusplus

class DECLSPEC_UUID("0A77CCF8-052C-11D6-B0EC-00B0D074179C")
Tws;
#endif
#endif /* __TWSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


