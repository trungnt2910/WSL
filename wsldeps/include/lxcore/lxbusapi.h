/*++

Copyright (c) Microsoft. All rights reserved.

Module Name:

    lxbusapi.h

Abstract:

    Public header for the lxbus API.

--*/

//
// WARNING: The APIs defined in this file are consumed by Lifted WSL, which is out of box.
// Do not make changes to this file since that could break existing lifted WSL releases.
//

#pragma once

#if defined(_MSC_VER)
#define ALIGNED_(X) __declspec(align(X))
#define COMPILER_ASSERT_(X) static_assert(X, #X)

#elif defined(__GNUC__)
#define ALIGNED_(X) __attribute__ ((aligned(X)))
#define COMPILER_ASSERT_C1(A,B) A ## B
#define COMPILER_ASSERT_C2(A,B) COMPILER_ASSERT_C1(A,B)
#define COMPILER_ASSERT_(X) typedef char COMPILER_ASSERT_C2(__ca_,__LINE__)[(X)?1:-1]

#define FILE_DEVICE_UNKNOWN             0x00000022
#define FILE_ANY_ACCESS                 0
#define METHOD_NEITHER                  3
#define CTL_CODE( DeviceType, Function, Method, Access ) (                 \
    ((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method) \
)

#else
#error Unsupported compiler or build environment

#endif

#define LXBUS_DEVICE_NAME "/dev/lxss"

//
// A console identifier describes a marshaled console on a message port.
//

typedef long long LXBUS_IPC_CONSOLE_ID, *PLXBUS_IPC_CONSOLE_ID;
typedef long long const *PCLXBUS_IPC_CONSOLE_ID;

#define LXBUS_IPC_CONSOLE_ID_INVALID 0

//
// A handle identifier describes a marshaled handle on a message port.
//

typedef long long LXBUS_IPC_HANDLE_ID, *PLXBUS_IPC_HANDLE_ID;
typedef long long const *PCLXBUS_IPC_HANDLE_ID;

#define LXBUS_IPC_HANDLE_ID_INVALID 0

//
// A server identifier describes a marshaled server port.
//

typedef long long LXBUS_SERVER_ID, *PLXBUS_SERVER_ID;
typedef long long const *PCLXBUS_IPC_SERVER_PORT_ID;

//
// A fork token identifier describes a marshaled fork token on a message port.
//

typedef long long LXBUS_IPC_FORK_TOKEN_ID, *PLXBUS_IPC_FORK_TOKEN_ID;
typedef long long const *PCLXBUS_IPC_FORK_TOKEN_ID;

#define LXBUS_IPC_FORK_TOKEN_ID_INVALID 0

//
// A process identifier describes a marshaled process on a message port.
//

typedef long long LXBUS_IPC_PROCESS_ID, *PLXBUS_IPC_PROCESS_ID;
typedef long long const *PCLXBUS_IPC_PROCESS_ID;

#define LXBUS_IPC_PROCESS_ID_INVALID 0

//
// Connect to server and wait for connection ioctls specify a timeout in
// milliseconds. The below value can be used to specify an infinite timeout.
//

#define LXBUS_IPC_INFINITE_TIMEOUT ((unsigned int)-1)

//
// Lxbus messages.
//

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_CREATE_UNNAMED_SERVER_PARAMETERS {
    struct {
        int ServerPort;
        LXBUS_SERVER_ID ServerId;
    } Output;

} LXBUS_IPC_MESSAGE_CREATE_UNNAMED_SERVER_PARAMETERS, *PLXBUS_IPC_MESSAGE_CREATE_UNNAMED_SERVER_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_CREATE_UNNAMED_SERVER_PARAMETERS) == 16);

typedef struct _LXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_DATA {
    unsigned int ClientProcess;
} LXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_DATA, *PLXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_DATA;
typedef const LXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_DATA *PCLXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_DATA;

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_DISCONNECT_CONSOLE_PARAMETERS {
    struct {
        LXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_DATA ConsoleData;
    } Input;

} LXBUS_IPC_MESSAGE_DISCONNECT_CONSOLE_PARAMETERS, *PLXBUS_IPC_MESSAGE_DISCONNECT_CONSOLE_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_DISCONNECT_CONSOLE_PARAMETERS) == 8);

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_PARAMETERS {
    struct {
        LXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_DATA ConsoleData;
    } Input;

    struct {
        LXBUS_IPC_CONSOLE_ID ConsoleId;
    } Output;

} LXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_PARAMETERS, *PLXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_MARSHAL_CONSOLE_PARAMETERS) == 8);


typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_MARSHAL_FORK_TOKEN_PARAMETERS {
    struct {
        unsigned int TokenHandle;
    } Input;

    struct {
        LXBUS_IPC_FORK_TOKEN_ID ForkTokenId;
    } Output;

} LXBUS_IPC_MESSAGE_MARSHAL_FORK_TOKEN_PARAMETERS, *PLXBUS_IPC_MESSAGE_MARSHAL_FORK_TOKEN_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_MARSHAL_FORK_TOKEN_PARAMETERS) == 8);


typedef enum _LXBUS_IPC_MESSAGE_MARSHAL_HANDLE_TYPE {
    LxBusIpcMarshalHandleTypeConsole = 0,
    LxBusIpcMarshalHandleTypeInput,
    LxBusIpcMarshalHandleTypeOutput,
    LxBusIpcMarshalHandleTypeMaximum
} LXBUS_IPC_MESSAGE_MARSHAL_HANDLE_TYPE, *PLXBUS_IPC_MESSAGE_MARSHAL_HANDLE_TYPE;

typedef struct _LXBUS_IPC_MESSAGE_MARSHAL_HANDLE_DATA {
    unsigned int Handle;
    LXBUS_IPC_MESSAGE_MARSHAL_HANDLE_TYPE HandleType;
} LXBUS_IPC_MESSAGE_MARSHAL_HANDLE_DATA, *PLXBUS_IPC_MESSAGE_MARSHAL_HANDLE_DATA;
typedef const LXBUS_IPC_MESSAGE_MARSHAL_HANDLE_DATA *PCLXBUS_IPC_MESSAGE_MARSHAL_HANDLE_DATA;

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_MARSHAL_HANDLE_PARAMETERS {
    struct {
        LXBUS_IPC_MESSAGE_MARSHAL_HANDLE_DATA HandleData;
    } Input;

    struct {
        LXBUS_IPC_HANDLE_ID HandleId;
    } Output;

} LXBUS_IPC_MESSAGE_MARSHAL_HANDLE_PARAMETERS, *PLXBUS_IPC_MESSAGE_MARSHAL_HANDLE_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_MARSHAL_HANDLE_PARAMETERS) == 8);


#define LXBUS_IPC_MARSHAL_PROCESS_FLAG_TERMINATE_ON_CLOSE 0x1

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_MARSHAL_PROCESS_PARAMETERS {
    struct {
        int Process;
        unsigned int Flags;
    } Input;

    struct {
        LXBUS_IPC_PROCESS_ID ProcessId;
    } Output;

} LXBUS_IPC_MESSAGE_MARSHAL_PROCESS_PARAMETERS, *PLXBUS_IPC_MESSAGE_MARSHAL_PROCESS_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_MARSHAL_PROCESS_PARAMETERS) == 8);


typedef union _LXBUS_REGISTER_SERVER_PARAMETERS {
    struct {
        const char* ServerName; // Must be a NULL terminated string.
    } Input;

    struct {
        int ServerPort;
    } Output;

} LXBUS_REGISTER_SERVER_PARAMETERS, *PLXBUS_REGISTER_SERVER_PARAMETERS;
typedef const LXBUS_REGISTER_SERVER_PARAMETERS *PCLXBUS_REGISTER_SERVER_PARAMETERS;

typedef struct ALIGNED_(8) _LXBUS_USER_CALLBACK_DATA {
    unsigned long long CallbackId;
    char Data[1];
} LXBUS_USER_CALLBACK_DATA, *PLXBUS_USER_CALLBACK_DATA;

typedef const LXBUS_USER_CALLBACK_DATA *PCLXBUS_USER_CALLBACK_DATA;

typedef enum _LXBUS_USER_CALLBACK_TYPE {
    LxBusUserCallbackTypeUnspecified,
    LxBusUserCallbackTypeResult,
    LxBusUserCallbackTypeVirtualNetwork,
    LxBusUserCallbackTypeIptables
} LXBUS_USER_CALLBACK_TYPE;

typedef struct ALIGNED_(8) _LXBUS_REGISTER_USER_CALLBACK_PARAMETERS {
    struct {
        LXBUS_USER_CALLBACK_TYPE CallbackType;
        struct {
            unsigned long long CallbackId;
            long Result;
        } ResultData;
    } Input;
} LXBUS_REGISTER_USER_CALLBACK_PARAMETERS, *PLXBUS_REGISTER_USER_CALLBACK_PARAMETERS;
typedef const LXBUS_REGISTER_USER_CALLBACK_PARAMETERS *PCLXBUS_REGISTER_USER_CALLBACK_PARAMETERS;

typedef enum _LXBUS_IPC_MESSAGE_RELEASE_TYPE {
    LxBusIpcReleaseTypeConsole = 0,
    LxBusIpcReleaseTypeHandle,
    LxBusIpcReleaseTypeForkToken,
    LxBusIpcReleaseTypeMaximum
} LXBUS_IPC_MESSAGE_RELEASE_TYPE, *PLXBUS_IPC_MESSAGE_RELEASE_TYPE;

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_IOCTL_CANCEL_MARSHAL_PARAMETERS {
    struct {
        union {
            LXBUS_IPC_CONSOLE_ID Console;
            LXBUS_IPC_FORK_TOKEN_ID Token;
            LXBUS_IPC_HANDLE_ID Handle;
        } Id;

        LXBUS_IPC_MESSAGE_RELEASE_TYPE Type;

    } Input;

} LXBUS_IPC_MESSAGE_IOCTL_CANCEL_MARSHAL_PARAMETERS, *PLXBUS_IPC_MESSAGE_IOCTL_CANCEL_MARSHAL_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_IOCTL_CANCEL_MARSHAL_PARAMETERS) == 16);

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_UNMARSHAL_PROCESS_PARAMETERS {
    struct {
        LXBUS_IPC_PROCESS_ID ProcessId;
    } Input;

    struct {
        int ProcessHandle;
    } Output;

} LXBUS_IPC_MESSAGE_UNMARSHAL_PROCESS_PARAMETERS, *PLXBUS_IPC_MESSAGE_UNMARSHAL_PROCESS_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_UNMARSHAL_PROCESS_PARAMETERS) == 8);

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_UNMARSHAL_VFS_FILE_PARAMETERS {
    struct {
        LXBUS_IPC_HANDLE_ID VfsFileId;
    } Input;

    struct {
        int Handle;
    } Output;

} LXBUS_IPC_MESSAGE_UNMARSHAL_VFS_FILE_PARAMETERS, *PLXBUS_IPC_MESSAGE_UNMARSHAL_VFS_FILE_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_UNMARSHAL_VFS_FILE_PARAMETERS) == 8);

//
// LxBus server port ioctl parameters.
//

typedef union _LXBUS_IPC_SERVER_WAIT_FOR_CONNECTION_PARAMETERS {
    struct {
        unsigned long TimeoutMs;
    } Input;

    struct {
        int MessagePort;
    } Output;
} LXBUS_IPC_SERVER_WAIT_FOR_CONNECTION_PARAMETERS, *PLXBUS_IPC_SERVER_WAIT_FOR_CONNECTION_PARAMETERS;

typedef union _LXBUS_IPC_LX_PROCESS_WAIT_FOR_TERMINATION_PARAMETERS {
    struct {
        unsigned int TimeoutMs;
    } Input;

    struct {
        int ExitStatus;
    } Output;

} LXBUS_IPC_LX_PROCESS_WAIT_FOR_TERMINATION_PARAMETERS, *PLXBUS_IPC_LX_PROCESS_WAIT_FOR_TERMINATION_PARAMETERS;
typedef const LXBUS_IPC_LX_PROCESS_WAIT_FOR_TERMINATION_PARAMETERS *PCLXBUS_IPC_LX_PROCESS_WAIT_FOR_TERMINATION_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_LX_PROCESS_WAIT_FOR_TERMINATION_PARAMETERS) == 4);

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_UNMARSHAL_HANDLE_PARAMETERS {
    struct {
        LXBUS_IPC_HANDLE_ID HandleId;
    } Input;

    struct {
        int FileDescriptor;
    } Output;

} LXBUS_IPC_MESSAGE_UNMARSHAL_HANDLE_PARAMETERS, *PLXBUS_IPC_MESSAGE_UNMARSHAL_HANDLE_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_UNMARSHAL_HANDLE_PARAMETERS) == 8);

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_UNMARSHAL_CONSOLE_PARAMETERS {
    struct {
        LXBUS_IPC_CONSOLE_ID ConsoleId;
    } Input;

    struct {
        int FileDescriptor;
    } Output;

} LXBUS_IPC_MESSAGE_UNMARSHAL_CONSOLE_PARAMETERS, *PLXBUS_IPC_MESSAGE_UNMARSHAL_CONSOLE_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_UNMARSHAL_CONSOLE_PARAMETERS) == 8);

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_UNMARSHAL_FORK_TOKEN_PARAMETERS {
    struct {
        LXBUS_IPC_FORK_TOKEN_ID ForkTokenId;
    } Input;

} LXBUS_IPC_MESSAGE_UNMARSHAL_FORK_TOKEN_PARAMETERS, *PLXBUS_IPC_MESSAGE_UNMARSHAL_FORK_TOKEN_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_UNMARSHAL_FORK_TOKEN_PARAMETERS) == 8);

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_MARSHAL_VFS_FILE_PARAMETERS {
    struct {
        int Fd;
    } Input;

    struct {
        LXBUS_IPC_HANDLE_ID VfsFileId;
    } Output;

} LXBUS_IPC_MESSAGE_MARSHAL_VFS_FILE_PARAMETERS, *PLXBUS_IPC_MESSAGE_MARSHAL_VFS_FILE_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_MARSHAL_VFS_FILE_PARAMETERS) == 8);

#define LXBUS_IPC_SERVER_ID_INVALID 0

//
// The unmarshal server ioctl specifies a server id to unmarshal which will be
// set as the current thread's unnamed server port.
//

typedef union ALIGNED_(8) _LXBUS_IPC_MESSAGE_UNMARSHAL_SERVER_PARAMETERS {
    struct {
        LXBUS_SERVER_ID ServerId;
    } Input;

} LXBUS_IPC_MESSAGE_UNMARSHAL_SERVER_PARAMETERS, *PLXBUS_IPC_MESSAGE_UNMARSHAL_SERVER_PARAMETERS;

static_assert(sizeof(LXBUS_IPC_MESSAGE_UNMARSHAL_SERVER_PARAMETERS) == 8);

//
// The connect server ioctl establishes a connenection with a named or unnamed
// server. Unnamed connections use the LX thread's server which is set by
// unmarshaling a server port.  The connect ioctl supplies a timeout
// representing how long to wait for the connection to be established. The
// server must call wait for connection to accept the connection.
//
// N.B. If the connect server ioctl supplies the the wait for server
//      registration flag, the connection can wait twice with the supplied
//      timeout value:
//          1. Waiting for the server to be registered.
//          2. Waiting for the server to call wait for connection.
//

#define LXBUS_IPC_CONNECT_FLAG_WAIT_FOR_SERVER_REGISTRATION 0x1
#define LXBUS_IPC_CONNECT_FLAG_UNNAMED_SERVER 0x2

typedef union ALIGNED_(8) _LXBUS_CONNECT_SERVER_PARAMETERS {
    struct {
        const char* ServerName; // Must be a NULL terminated string.
        unsigned int TimeoutMs;
        unsigned int Flags;
    } Input;

    struct {
        int MessagePort;
    } Output;

} LXBUS_CONNECT_SERVER_PARAMETERS, *PLXBUS_CONNECT_SERVER_PARAMETERS;
typedef const LXBUS_CONNECT_SERVER_PARAMETERS *PCLXBUS_CONNECT_SERVER_PARAMETERS;

//
// Lxbus ioctl codes.
//

#define LXBUS_IOCTL_REGISTER_SERVER \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 10, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IOCTL_CONNECT_SERVER \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 11, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_SERVER_IOCTL_WAIT_FOR_CONNECTION \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 12, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IOCTL_REGISTER_USER_CALLBACK \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 19, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define LXBUS_ROOT_IOCTL_CREATE_INSTANCE \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 27, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IOCTL_SET_INSTANCE_STATE \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 28, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_INSTANCE_IOCTL_GET_INIT_EXIT_STATUS \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 29, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_MARSHAL_PROCESS \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 37, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_UNMARSHAL_PROCESS \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 38, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_MARSHAL_HANDLE \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 39, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_UNMARSHAL_HANDLE \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 40, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_MARSHAL_CONSOLE \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 41, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_UNMARSHAL_CONSOLE \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 42, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_MARSHAL_FORK_TOKEN \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 43, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_UNMARSHAL_FORK_TOKEN \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 44, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_MARSHAL_VFS_FILE \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 45, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_UNMARSHAL_VFS_FILE \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 46, METHOD_NEITHER, FILE_ANY_ACCESS)

    #define LXBUS_IPC_MESSAGE_IOCTL_CREATE_UNNAMED_SERVER \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 48, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_UNMARSHAL_SERVER \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 49, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_CANCEL_MARSHAL \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 50, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_MESSAGE_IOCTL_DISCONNECT_CONSOLE \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 51, METHOD_NEITHER, FILE_ANY_ACCESS)

#define LXBUS_IPC_LX_PROCESS_IOCTL_WAIT_FOR_TERMINATION \
    CTL_CODE(FILE_DEVICE_UNKNOWN, 52, METHOD_NEITHER, FILE_ANY_ACCESS)