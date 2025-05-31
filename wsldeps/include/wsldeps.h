/*++

Copyright (c) Microsoft. All rights reserved.

Module Name:

    wsldeps.h

Abstract:

    This file contains exported methods for the wsldeps library

--*/

#pragma once

#include <rpc.h>

#ifdef __cplusplus
extern "C"
{
#endif

    __declspec(dllimport) HRESULT WINAPI WslDepsRegisterGnsRpcServer(void* SecurityDescriptor, UUID* EndpointId);
    __declspec(dllimport) HRESULT WINAPI WslDepsUnregisterGnsRpcServer(UUID* EndpointId);

#ifdef __cplusplus
}
#endif