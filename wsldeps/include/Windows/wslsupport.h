

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 501
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __wslsupport_h__
#define __wslsupport_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IWslSupport_FWD_DEFINED__
#define __IWslSupport_FWD_DEFINED__
typedef interface IWslSupport IWslSupport;

#endif 	/* __IWslSupport_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_wslsupport_0000_0000 */
/* [local] */ 

typedef 
enum _WslSupportCreateInstanceFlags
    {
        IgnoreClient	= 0x1
    } 	WslSupportCreateInstanceFlags;

DEFINE_ENUM_FLAG_OPERATORS(WslSupportCreateInstanceFlags);
const GUID CLSID_WslSupport = {0xa9b7a1b9, 0x0671, 0x405c, {0x95, 0xf1, 0xe0, 0x61, 0x2c, 0xb4, 0xce, 0x7e}};
#ifdef __cplusplus
class DECLSPEC_UUID("a9b7a1b9-0671-405c-95f1-e0612cb4ce7e") WslSupport;
#endif


extern RPC_IF_HANDLE __MIDL_itf_wslsupport_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wslsupport_0000_0000_v0_0_s_ifspec;

#ifndef __IWslSupport_INTERFACE_DEFINED__
#define __IWslSupport_INTERFACE_DEFINED__

/* interface IWslSupport */
/* [object][unique][uuid] */ 


EXTERN_C const IID IID_IWslSupport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("46f3c96d-ffa3-42f0-b052-52f5e7ecbb08")
    IWslSupport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegisterDistribution( 
            /* [in] */ __RPC__in LPCWSTR DistributionName,
            /* [in] */ ULONG Version,
            /* [system_handle][in] */ __RPC__in HANDLE TarGzFile,
            /* [system_handle][in] */ __RPC__in HANDLE TarGzPipe,
            /* [in] */ __RPC__in LPCWSTR TargetDirectory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterDistribution( 
            /* [in] */ __RPC__in LPCWSTR DistributionName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDistributionConfiguration( 
            /* [in] */ __RPC__in LPCWSTR DistributionName,
            /* [out] */ __RPC__out ULONG *Version,
            /* [out] */ __RPC__out ULONG *DefaultUid,
            /* [out] */ __RPC__out ULONG *DefaultEnvironmentCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*DefaultEnvironmentCount) LPSTR **DefaultEnvironment,
            /* [out] */ __RPC__out ULONG *WslFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDistributionConfiguration( 
            /* [in] */ __RPC__in LPCWSTR DistributionName,
            /* [in] */ ULONG DefaultUid,
            /* [in] */ ULONG WslFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ListDistributions( 
            /* [out] */ __RPC__out ULONG *Count,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*Count) LPWSTR **Distributions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateInstance( 
            /* [in] */ __RPC__in LPCWSTR DistributionName,
            /* [in] */ ULONG Flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWslSupportVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IWslSupport * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IWslSupport * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IWslSupport * This);
        
        DECLSPEC_XFGVIRT(IWslSupport, RegisterDistribution)
        HRESULT ( STDMETHODCALLTYPE *RegisterDistribution )( 
            __RPC__in IWslSupport * This,
            /* [in] */ __RPC__in LPCWSTR DistributionName,
            /* [in] */ ULONG Version,
            /* [system_handle][in] */ __RPC__in HANDLE TarGzFile,
            /* [system_handle][in] */ __RPC__in HANDLE TarGzPipe,
            /* [in] */ __RPC__in LPCWSTR TargetDirectory);
        
        DECLSPEC_XFGVIRT(IWslSupport, UnregisterDistribution)
        HRESULT ( STDMETHODCALLTYPE *UnregisterDistribution )( 
            __RPC__in IWslSupport * This,
            /* [in] */ __RPC__in LPCWSTR DistributionName);
        
        DECLSPEC_XFGVIRT(IWslSupport, GetDistributionConfiguration)
        HRESULT ( STDMETHODCALLTYPE *GetDistributionConfiguration )( 
            __RPC__in IWslSupport * This,
            /* [in] */ __RPC__in LPCWSTR DistributionName,
            /* [out] */ __RPC__out ULONG *Version,
            /* [out] */ __RPC__out ULONG *DefaultUid,
            /* [out] */ __RPC__out ULONG *DefaultEnvironmentCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*DefaultEnvironmentCount) LPSTR **DefaultEnvironment,
            /* [out] */ __RPC__out ULONG *WslFlags);
        
        DECLSPEC_XFGVIRT(IWslSupport, SetDistributionConfiguration)
        HRESULT ( STDMETHODCALLTYPE *SetDistributionConfiguration )( 
            __RPC__in IWslSupport * This,
            /* [in] */ __RPC__in LPCWSTR DistributionName,
            /* [in] */ ULONG DefaultUid,
            /* [in] */ ULONG WslFlags);
        
        DECLSPEC_XFGVIRT(IWslSupport, ListDistributions)
        HRESULT ( STDMETHODCALLTYPE *ListDistributions )( 
            __RPC__in IWslSupport * This,
            /* [out] */ __RPC__out ULONG *Count,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*Count) LPWSTR **Distributions);
        
        DECLSPEC_XFGVIRT(IWslSupport, CreateInstance)
        HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            __RPC__in IWslSupport * This,
            /* [in] */ __RPC__in LPCWSTR DistributionName,
            /* [in] */ ULONG Flags);
        
        DECLSPEC_XFGVIRT(IWslSupport, Shutdown)
        HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            __RPC__in IWslSupport * This);
        
        END_INTERFACE
    } IWslSupportVtbl;

    interface IWslSupport
    {
        CONST_VTBL struct IWslSupportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWslSupport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWslSupport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWslSupport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWslSupport_RegisterDistribution(This,DistributionName,Version,TarGzFile,TarGzPipe,TargetDirectory)	\
    ( (This)->lpVtbl -> RegisterDistribution(This,DistributionName,Version,TarGzFile,TarGzPipe,TargetDirectory) ) 

#define IWslSupport_UnregisterDistribution(This,DistributionName)	\
    ( (This)->lpVtbl -> UnregisterDistribution(This,DistributionName) ) 

#define IWslSupport_GetDistributionConfiguration(This,DistributionName,Version,DefaultUid,DefaultEnvironmentCount,DefaultEnvironment,WslFlags)	\
    ( (This)->lpVtbl -> GetDistributionConfiguration(This,DistributionName,Version,DefaultUid,DefaultEnvironmentCount,DefaultEnvironment,WslFlags) ) 

#define IWslSupport_SetDistributionConfiguration(This,DistributionName,DefaultUid,WslFlags)	\
    ( (This)->lpVtbl -> SetDistributionConfiguration(This,DistributionName,DefaultUid,WslFlags) ) 

#define IWslSupport_ListDistributions(This,Count,Distributions)	\
    ( (This)->lpVtbl -> ListDistributions(This,Count,Distributions) ) 

#define IWslSupport_CreateInstance(This,DistributionName,Flags)	\
    ( (This)->lpVtbl -> CreateInstance(This,DistributionName,Flags) ) 

#define IWslSupport_Shutdown(This)	\
    ( (This)->lpVtbl -> Shutdown(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWslSupport_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


