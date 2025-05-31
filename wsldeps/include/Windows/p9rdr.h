// Copyright (C) Microsoft Corporation. All rights reserved.
#pragma once

#define P9RDR_DEVICE_NAME       L"\\Device\\P9Rdr"
#define P9RDR_MAJOR_VERSION     1
#define P9RDR_MINOR_VERSION     0
#define P9RDR_PROVIDER_NAME     L"Plan 9 Network Provider"
#define P9RDR_UNC_PREFIX        L"wsl.localhost"
#define P9RDR_UNC_COMPAT_PREFIX L"wsl$"

#define IOCTL_P9RDR_START                    CTL_CODE(FILE_DEVICE_UNKNOWN, 1, METHOD_NEITHER, FILE_ANY_ACCESS)
#define IOCTL_P9RDR_ADD_CONNECTION_TARGET    CTL_CODE(FILE_DEVICE_UNKNOWN, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_P9RDR_REMOVE_CONNECTION_TARGET CTL_CODE(FILE_DEVICE_UNKNOWN, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_P9RDR_CLEAR_CONNECTION_TARGETS CTL_CODE(FILE_DEVICE_UNKNOWN, 4, METHOD_NEITHER, FILE_ANY_ACCESS)
#define IOCTL_P9RDR_REGISTER_USER_CALLBACK   CTL_CODE(FILE_DEVICE_UNKNOWN, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_P9RDR_ENUMERATE_CONNECTIONS    CTL_CODE(FILE_DEVICE_UNKNOWN, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define FSCTL_P9RDR_DELETE_CONNECTION        CTL_CODE(FILE_DEVICE_NETWORK_FILE_SYSTEM, 1, METHOD_NEITHER, FILE_ANY_ACCESS)
#define FSCTL_P9RDR_DELETE_CONNECTION_FORCE  CTL_CODE(FILE_DEVICE_NETWORK_FILE_SYSTEM, 2, METHOD_NEITHER, FILE_ANY_ACCESS)

// Data for the IOCTL_P9RDR_ADD_CONNECTION_TARGET ioctl. This struct should be followed by
// ShareNameLength bytes containing the name of the "share" (WCHAR), and ANameLength bytes
// containing the aname to use when connecting (CHAR). When using AF_UNIX, the aname is followed
// by the full NT path of the socket file to connect to.
typedef struct _P9RDR_ADD_CONNECTION_TARGET_INPUT {
    SOCKADDR_STORAGE Address;
    ULONG Uid;
    LUID LogonId;
    USHORT ShareNameLength;
    USHORT ANameLength;
} P9RDR_ADD_CONNECTION_TARGET_INPUT, *PP9RDR_ADD_CONNECTION_TARGET_INPUT;

// Data for the IOCTL_P9RDR_REMOVE_CONNECTION_TARGET ioctl. This struct should be followed by the
// share name to remove.
typedef struct _P9RDR_REMOVE_CONNECTION_TARGET_INPUT {
    LUID LogonId;
} P9RDR_REMOVE_CONNECTION_TARGET_INPUT, *PP9RDR_REMOVE_CONNECTION_TARGET_INPUT;

// Data returned by the IOCTL_P9RDR_ENUMERATE_CONNECTIONS ioctl. This struct will be followed by
// the names and drive letters of each connection, separated by NULL characters. If the output
// buffer was too small, Size will be set to the total size required.
typedef struct _P9RDR_ENUMERATE_CONNECTIONS_OUTPUT {
    ULONG Size;
} P9RDR_ENUMERATE_CONNECTIONS_OUTPUT, *PP9RDR_ENUMERATE_CONNECTIONS_OUTPUT;
