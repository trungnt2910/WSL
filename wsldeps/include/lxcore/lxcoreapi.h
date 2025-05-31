/*++

Copyright (c) Microsoft. All rights reserved.

Module Name:

    lxcoreapi.h

Abstract:

    Public header for lxcore APIs.

--*/

//
// WARNING: The APIs defined in this file are consumed by Lifted WSL, which is out of box.
// Do not make changes to this file since that could break existing lifted WSL releases.
//

#pragma once

#include "lxbusapi.h"
#define LX_UID_ROOT (0)
#define LX_GID_ROOT (0)
#define LX_UID_INVALID MAX_LX_UID_T
#define LX_GID_INVALID MAX_LX_GID_T


//
// uid_t and gid_t are unsigned 32-bit integers.
//

typedef ULONG LX_UID_T, *PLX_UID_T;

#define MIN_LX_UID_T ((ULONG)0)
#define MAX_LX_UID_T MAXULONG

typedef ULONG LX_GID_T, *PLX_GID_T;

#define MIN_LX_GID_T ((ULONG)0)
#define MAX_LX_GID_T MAXULONG


//
// mode_t is an unsigned 32-bit integer.
//

typedef ULONG LX_MODE_T, *PLX_MODE_T;

#define MIN_LX_MODE_T ((ULONG)0)
#define MAX_LX_MODE_T MAXULONG


//
// Various modes definitions.
//

#define LX_MODE_INVALID ((LX_MODE_T)-1)
#define LX_MODE_RW_USER (LX_S_IRUSR | LX_S_IWUSR)
#define LX_MODE_RW_GROUP (LX_S_IRGRP | LX_S_IWGRP)
#define LX_MODE_RW_OTHER (LX_S_IROTH | LX_S_IWOTH)
#define LX_MODE_RW_ALL (LX_MODE_RW_USER | LX_MODE_RW_GROUP | LX_MODE_RW_OTHER)
#define LX_MODE_VALID_BITS (LX_S_IFMT | 07777)

//
// LX_FILE_ATTRIBUTES_EA.
//

#define LX_FILE_DEV_T_MINOR_BITS   20

typedef union _LX_FILE_DEV_T {
    struct {
        UINT MinorNumber : LX_FILE_DEV_T_MINOR_BITS;
        UINT MajorNumber : (32 - LX_FILE_DEV_T_MINOR_BITS);
    } Number;
    UINT Id;
} LX_FILE_DEV_T, *PLX_FILE_DEV_T;

typedef struct _LX_FILE_ATTRIBUTES {
    union {
        struct {
            ULONG Reserved : 16;
            ULONG Version : 16;
        } Flags;

        ULONG AllFlags;
    } u;
    ULONG Mode;
    ULONG Uid;
    ULONG Gid;
    LX_FILE_DEV_T DeviceId;
    ULONG AccessedTimeNanoSeconds;
    ULONG ModifiedTimeNanoSeconds;
    ULONG ChangedTimeNanoSeconds;
    ULONG64 AccessedTimeSeconds;
    ULONG64 ModifiedTimeSeconds;
    ULONG64 ChangedTimeSeconds;
} LX_FILE_ATTRIBUTES, *PLX_FILE_ATTRIBUTES;

//
// On disk extended attribute stored for VolumeFs inodes.
//
// N.B. The FILE_FULL_EA_INFORMATION structure is documented externally and
//      requires using the padding after the structure for the name.
//

#define LX_FILE_ATTRIBUTES_NAME "LXATTRB"

#define LX_FILE_ATTRIBUTES_NAME_LENGTH (RTL_NUMBER_OF(LX_FILE_ATTRIBUTES_NAME) - 1)
#define LX_FILE_ATTRIBUTES_CURRENT_VERSION 1

typedef struct _LX_FILE_ATTRIBUTES_EA {
    union {
        FILE_FULL_EA_INFORMATION EaInformation;
        CHAR EaBuffer[FIELD_OFFSET(FILE_FULL_EA_INFORMATION, EaName) + RTL_NUMBER_OF(LX_FILE_ATTRIBUTES_NAME)];
    } u;

    LX_FILE_ATTRIBUTES Attributes;
} LX_FILE_ATTRIBUTES_EA, *PLX_FILE_ATTRIBUTES_EA;


// TODO: Move to lifted WSL
#define LX_FILE_ATTRIBUTES_EA_INITIALIZE(_Ea)                                                               \
{                                                                                                           \
    RtlZeroMemory((_Ea), sizeof(*_Ea));                                                                     \
    (_Ea)->u.EaInformation.EaNameLength = LX_FILE_ATTRIBUTES_NAME_LENGTH;                                   \
    RtlCopyMemory(&(_Ea)->u.EaInformation.EaName, LX_FILE_ATTRIBUTES_NAME, LX_FILE_ATTRIBUTES_NAME_LENGTH); \
    (_Ea)->u.EaInformation.EaValueLength = sizeof((_Ea)->Attributes);                                       \
    (_Ea)->Attributes.u.Flags.Version = LX_FILE_ATTRIBUTES_CURRENT_VERSION;                                 \
}

//
// Name for the LX control device interface root.
//

#define LX_CONTROL_DEVICE_ROOT L"\\Device\\lxss"

//
// The error codes below are negative, but user mode will invert them back to
// positive when storing it in the thread-local errno.
//

#define LX_EPERM           -1
#define LX_ENOENT          -2
#define LX_ESRCH           -3
#define LX_EINTR           -4
#define LX_EIO             -5
#define LX_ENXIO           -6
#define LX_ENOEXEC         -8
#define LX_E2BIG           -7
#define LX_EBADF           -9
#define LX_ECHILD          -10
#define LX_EAGAIN          -11
#define LX_EWOULDBLOCK     LX_EAGAIN
#define LX_ENOMEM          -12
#define LX_EACCES          -13
#define LX_EFAULT          -14
#define LX_EBUSY           -16
#define LX_EEXIST          -17
#define LX_EXDEV           -18
#define LX_ENODEV          -19
#define LX_ENOTDIR         -20
#define LX_EISDIR          -21
#define LX_EINVAL          -22
#define LX_ENFILE          -23
#define LX_EMFILE          -24
#define LX_ENOTTY          -25
#define LX_EFBIG           -27
#define LX_ENOSPC          -28
#define LX_ESPIPE          -29
#define LX_EROFS           -30
#define LX_EMLINK          -31
#define LX_EPIPE           -32
#define LX_ERANGE          -34
#define LX_EDEADLK         -35
#define LX_ENAMETOOLONG    -36
#define LX_ENOLCK          -37
#define LX_ENOSYS          -38
#define LX_ENOTEMPTY       -39
#define LX_ELOOP           -40
#define LX_EIDRM           -43
#define LX_ENODATA         -61
#define LX_ENOATTR         LX_ENODATA
#define LX_EPROTO          -71
#define LX_EOVERFLOW       -75
#define LX_EUSERS          -87
#define LX_ENOTSOCK        -88
#define LX_EDESTADDRREQ    -89
#define LX_EMSGSIZE        -90
#define LX_EPROTOTYPE      -91
#define LX_ENOPROTOOPT     -92
#define LX_EPROTONOSUPPORT -93
#define LX_ESOCKTNOSUPPORT -94
#define LX_EOPNOTSUPP      -95
#define LX_ENOTSUP         LX_EOPNOTSUPP
#define LX_EAFNOSUPPORT    -97
#define LX_EADDRINUSE      -98
#define LX_EADDRNOTAVAIL   -99
#define LX_ENETUNREACH     -101
#define LX_ECONNABORTED    -103
#define LX_ECONNRESET      -104
#define LX_ENOBUFS         -105
#define LX_EISCONN         -106
#define LX_ENOTCONN        -107
#define LX_ETIMEDOUT       -110
#define LX_ECONNREFUSED    -111
#define LX_EHOSTDOWN       -112
#define LX_EHOSTUNREACH    -113
#define LX_EALREADY        -114
#define LX_EINPROGRESS     -115
#define LX_ENOMEDIUM       -123
#define LX_EMEDIUMTYPE     -124
#define LX_ENOKEY          -126

//
// Mount flags.
//

#define LX_MS_RDONLY (0x1)
#define LX_MS_NOSUID (0x2)
#define LX_MS_NODEV (0x4)
#define LX_MS_NOEXEC (0x8)
#define LX_MS_SYNCHRONOUS (0x10)
#define LX_MS_REMOUNT (0x20)
#define LX_MS_MANDLOCK (0x40)
#define LX_MS_DIRSYNC (0x80)
#define LX_MS_NOATIME (0x400)
#define LX_MS_NODIRATIME (0x800)
#define LX_MS_BIND (0x1000)
#define LX_MS_MOVE (0x2000)
#define LX_MS_REC (0x4000)
#define LX_MS_SILENT (0x8000)
#define LX_MS_POSIXACL (0x10000)
#define LX_MS_UNBINDABLE (0x20000)
#define LX_MS_PRIVATE (0x40000)
#define LX_MS_SLAVE (0x80000)
#define LX_MS_SHARED (0x100000)
#define LX_MS_RELATIME (0x200000)
#define LX_MS_KERNMOUNT (0x400000)
#define LX_MS_I_VERSION (0x800000)
#define LX_MS_STRICTATIME (0x1000000)
#define LX_MS_ACTIVE (0x40000000)
#define LX_MS_NOUSER (0x80000000)
#define LX_MS_RMT_MASK (LX_MS_RDONLY | LX_MS_SYNCHRONOUS | LX_MS_MANDLOCK | LX_MS_I_VERSION)
#define LX_MS_MGC_VAL (0xc0ed0000)
#define LX_MS_MGC_MSK (0xffff0000)

//
// Permissions.
//

#define LX_S_IFIFO  0x1000
#define LX_S_IFCHR  0x2000
#define LX_S_IFDIR  0x4000
#define LX_S_IFBLK  0x6000
#define LX_S_IFREG  0x8000
#define LX_S_IFLNK  0xa000
#define LX_S_IFSOCK 0xc000
#define LX_S_IFMT   0xf000
#define LX_S_ISUID  04000
#define LX_S_ISGID  02000
#define LX_S_ISVTX  01000
#define LX_S_IRUSR  0400
#define LX_S_IWUSR  0200
#define LX_S_IXUSR  0100
#define LX_S_IRWXU  (LX_S_IRUSR | LX_S_IWUSR | LX_S_IXUSR)
#define LX_S_IRGRP  0040
#define LX_S_IWGRP  0020
#define LX_S_IXGRP  0010
#define LX_S_IRWXG  (LX_S_IRGRP | LX_S_IWGRP | LX_S_IXGRP)
#define LX_S_IROTH  0004
#define LX_S_IWOTH  0002
#define LX_S_IXOTH  0001
#define LX_S_IRWXO  (LX_S_IROTH | LX_S_IWOTH | LX_S_IXOTH)

//
// O_NOACCESS means that the file object cannot be used for reading or writing,
// but can be used for other operations like ioctl.
//

#define LX_O_RDONLY    0x000000
#define LX_O_WRONLY    0x000001
#define LX_O_RDWR      0x000002
#define LX_O_NOACCESS  0x000003
#define LX_O_CREAT     0x000040
#define LX_O_EXCL      0x000080
#define LX_O_NOCTTY    0x000100
#define LX_O_TRUNC     0x000200
#define LX_O_APPEND    0x000400
#define LX_O_NONBLOCK  0x000800
#define LX_O_NDELAY    LX_O_NONBLOCK
#define LX_O_ASYNC     0x002000
#define LX_FD_CLOEXEC  0x1


//
// Define maximum hostname and domain name length.
//

#define LX_DOMAIN_NAME_MAX  64
#define LX_HOST_NAME_MAX    64

//
// TODO_LX: move the error level out of the public linux type header
//

typedef enum _LXP_ERROR_LEVEL {
    LxErrorLevel_Info = 4,
    LxErrorLevel_Warning = 3,
    LxErrorLevel_Error = 2,
    LxErrorLevel_Critical = 1,
    LxErrorLevel_Off = 0
} LXP_ERROR_LEVEL, *PLXP_ERROR_LEVEL;

//
// Constants for querying registry.
//

#define LX_QUERY_REGISTRY_PATH L"lxss"
#define LX_QUERY_REGISTRY_ERROR_LEVEL_SUBKEY L"KdBreakPointErrorLevel"
#define LX_QUERY_REGISTRY_TRACELOGGING_LEVEL_SUBKEY L"TraceloggingLevel"
#define LX_QUERY_REGISTRY_BREAK_ON_SYSCALL_FAILURE_SUBKEY \
    L"KdBreakOnSyscallFailures"

#define LX_QUERY_REGISTRY_ROOT_LXBUS_ACCESS L"RootLxBusAccess"
#define LX_QUERY_REGISTRY_DRVFS_FALLBACK_MODE L"DrvFsFallback"
#define LX_QUERY_REGISTRY_DRVFS_ALLOW_FORCE_CASE_SENSITIVITY \
    L"DrvFsAllowForceCaseSensitivity"

#define LX_QUERY_REGISTRY_DRVFS_ALLOW_FORCE_CASE_SENSITIVITY_DEFAULT (0)
#define LX_QUERY_REGISTRY_OVFS_UNSTABLE_INODE L"OvFsUnstableInode"

//
// LX socket address families.
//

#define LX_AF_UNSPEC      0
#define LX_AF_UNIX        1
#define LX_AF_INET        2
#define LX_AF_INET6       10
#define LX_AF_NETLINK     16

typedef struct _LX_KMAPPATHS_ADDMOUNT {
    HANDLE WindowsDataRoot;
    LPCSTR Source;
    LPCSTR Target;
    LPCSTR FsType;
    ULONG MountFlags;
    ULONG Uid;
    ULONG Gid;
    ULONG Mode;
} LX_KMAPPATHS_ADDMOUNT, *PLX_KMAPPATHS_ADDMOUNT;

typedef struct _LX_KINIT_FILE_DESCRIPTOR {
    HANDLE Handle;
    LONG FileObjectFlags;
    LONG FileDescriptorFlags;
} LX_KINIT_FILE_DESCRIPTOR, *PLX_KINIT_FILE_DESCRIPTOR;

#define LX_KINSTANCECREATESTART_FLAG_DISABLE_SERIAL         (0x00000001)
#define LX_KINSTANCECREATESTART_FLAG_DISABLE_DRIVE_MOUNTING (0x00000002)

#define LX_KINSTANCECREATESTART_VALID_FLAGS \
     (LX_KINSTANCECREATESTART_FLAG_DISABLE_SERIAL | \
      LX_KINSTANCECREATESTART_FLAG_DISABLE_DRIVE_MOUNTING)

typedef struct _LX_KINSTANCECREATESTART {
    GUID InstanceId;
    LPCSTR RootFsType;
    ULONG RootDirectoryHandle;
    ULONG TempDirectoryHandle;
    ULONG JobHandle;
    ULONG TokenHandle;
    LPCSTR KernelCommandLine;
    ULONG Flags;
    ULONG NumPathsToMap;
    PLX_KMAPPATHS_ADDMOUNT PathsToMap;
    ULONG NumInitFileDescriptors;
    PLX_KINIT_FILE_DESCRIPTOR InitFileDescriptors;
    ULONG InstanceTerminatedEventHandle;
} LX_KINSTANCECREATESTART, *PLX_KINSTANCECREATESTART;

typedef enum _LX_KINSTANCESETSTATE_TYPE {
    LxKInstanceSetStateTypeStart,
    LxKInstanceSetStateTypeStop,
    LxKInstanceSetStateTypeDestroy
} LX_KINSTANCESETSTATE_TYPE, *PLX_KINSTANCESETSTATE_TYPE;

typedef struct _LX_KINSTANCESETSTATE {
    LX_KINSTANCESETSTATE_TYPE Type;
    union {
        ULONG StartParentProcessHandle;
    } TypeData;
} LX_KINSTANCESETSTATE, *PLX_KINSTANCESETSTATE;

typedef struct _LX_KWINDOWSIZE {
    SHORT Rows;
    SHORT Columns;
} LX_KWINDOWSIZE, *PLX_KWINDOWSIZE;


//
// Network definitions.
//

#define LX_NETWORK_INTERFACE_NAME_LENGTH (16)
#define LX_NETWORK_MAX_HARDWARE_ADDRESS_LENGTH (16)

typedef enum _LX_NETWORK_INTERFACE_FLAGS {
    LxNetworkInterfaceUp = 0x1,
    LxNetworkInterfaceBroadcast = 0x2,
    LxNetworkInterfaceDebug = 0x4,
    LxNetworkInterfaceLoopback = 0x8,
    LxNetworkInterfacePointToPoint = 0x10,
    LxNetworkInterfaceNoTrailers = 0x20,
    LxNetworkInterfaceRunning = 0x40,
    LxNetworkInterfaceNoArp = 0x80,
    LxNetworkInterfacePromisc = 0x100,
    LxNetworkInterfaceAllMulti = 0x200,
    LxNetworkInterfaceMaster = 0x400,
    LxNetworkInterfaceSlave = 0x800,
    LxNetworkInterfaceMulticast = 0x1000,
    LxNetworkInterfacePortSel = 0x2000,
    LxNetworkInterfaceAutoMedia = 0x4000,
    LxNetworkInterfaceDynamic = 0x8000,
    LxNetworkInterfaceLowerUp = 0x10000,
    LxNetworkInterfaceDormant = 0x20000,
    LxNetworkInterfaceEcho = 0x40000
} LX_NETWORK_INTERFACE_FLAGS;

typedef enum _LX_NETWORK_INTERFACE_ADDRESS_FLAGS {
    LxNetworkInterfaceAddressSecondary = 0x1,
    LxNetworkInterfaceAddressNoDad = 0x2,
    LxNetworkInterfaceAddressOptimistic = 0x4,
    LxNetworkInterfaceAddressDadFailed = 0x8,
    LxNetworkInterfaceAddressHomeAddress = 0x10,
    LxNetworkInterfaceAddressDeprecated = 0x20,
    LxNetworkInterfaceAddressTentative = 0x40,
    LxNetworkInterfaceAddressPermanent = 0x80
} LX_NETWORK_INTERFACE_ADDRESS_FLAGS;

typedef enum _LXBUS_USER_CALLBACK_NETWORK_BRIDGE_CONFIG_TYPE {
    LxBusUserCallbackNetworkBridgeConfigTypeUnspecified,
    LxBusUserCallbackNetworkBridgeConfigTypeAddDevice,
    LxBusUserCallbackNetworkBridgeConfigTypeRemoveDevice
} LXBUS_USER_CALLBACK_NETWORK_BRIDGE_CONFIG_TYPE;

typedef struct _LXBUS_USER_CALLBACK_NETWORK_BRIDGE_CONFIG_DATA {
    LXBUS_USER_CALLBACK_NETWORK_BRIDGE_CONFIG_TYPE BridgeConfigType;
    char AddInterfaceName[LX_NETWORK_INTERFACE_NAME_LENGTH];
    GUID AddInterfaceId;
    GUID AlternateConnectingInterfaceId;
    BOOLEAN IsInternalInterface;
} LXBUS_USER_CALLBACK_NETWORK_BRIDGE_CONFIG_DATA,
  *PLXBUS_USER_CALLBACK_NETWORK_BRIDGE_CONFIG_DATA;

typedef enum _LXBUS_USER_CALLBACK_NETWORK_VETH_CONFIG_TYPE {
    LxBusUserCallbackNetworkVethConfigTypeUnspecified,
    LxBusUserCallbackNetworkVethConfigTypeJoinCompartment
} LXBUS_USER_CALLBACK_NETWORK_VETH_CONFIG_TYPE;

typedef struct _LXBUS_USER_CALLBACK_NETWORK_VETH_CONFIG_DATA {
    LXBUS_USER_CALLBACK_NETWORK_VETH_CONFIG_TYPE VethConfigType;
    GUID CompartmentGuid;
} LXBUS_USER_CALLBACK_NETWORK_VETH_CONFIG_DATA,
  *PLXBUS_USER_CALLBACK_NETWORK_VETH_CONFIG_DATA;

typedef enum _LXBUS_USER_CALLBACK_NETWORK_DATA_TYPE {
    LxBusUserCallbackNetworkDataTypeUnspecified,
    LxBusUserCallbackNetworkDataTypeCreateBridgeDevice,
    LxBusUserCallbackNetworkDataTypeCreateEthernetDevice,
    LxBusUserCallbackNetworkDataTypeDeleteDevice,
    LxBusUserCallbackNetworkDataTypeConfigureDevice,
} LXBUS_USER_CALLBACK_NETWORK_DATA_TYPE;

typedef struct _LXBUS_USER_CALLBACK_NETWORK_DATA {
    LXBUS_USER_CALLBACK_DATA Header;
    LXBUS_USER_CALLBACK_NETWORK_DATA_TYPE NetworkDataType;
    union {
        struct {
            char Name[LX_NETWORK_INTERFACE_NAME_LENGTH];
            GUID CompartmentGuid;
            ULONG HardwareAddressLength;
            BYTE HardwareAddress[LX_NETWORK_MAX_HARDWARE_ADDRESS_LENGTH];
        } CreateBridgeDevice;

        struct {
            char Name[LX_NETWORK_INTERFACE_NAME_LENGTH];
            GUID CompartmentGuid;
            ULONG HardwareAddressLength;
            BYTE HardwareAddress[LX_NETWORK_MAX_HARDWARE_ADDRESS_LENGTH];
            GUID PairedInterfaceId;
        } CreateEthernetDevice;

        struct {
            GUID InterfaceId;
        } DeleteDevice;

        struct {
            GUID InterfaceId;
            char Name[LX_NETWORK_INTERFACE_NAME_LENGTH];
            union {
                LXBUS_USER_CALLBACK_NETWORK_BRIDGE_CONFIG_DATA Bridge;
                LXBUS_USER_CALLBACK_NETWORK_VETH_CONFIG_DATA Veth;
            } Config;
        } ConfigureDevice;
    } Data;
} LXBUS_USER_CALLBACK_NETWORK_DATA, *PLXBUS_USER_CALLBACK_NETWORK_DATA;
typedef const LXBUS_USER_CALLBACK_NETWORK_DATA *PCLXBUS_USER_CALLBACK_NETWORK_DATA;

typedef enum _LXBUS_USER_CALLBACK_IPTABLES_DATA_TYPE {
    LxBusUserCallbackIptablesDataTypeUnspecified,
    LxBusUserCallbackIptablesDataTypeMasquerade,
    LxBusUserCallbackIptablesDataTypePort
} LXBUS_USER_CALLBACK_IPTABLES_DATA_TYPE;

typedef struct _LXBUS_USER_CALLBACK_IPTABLES_DATA {
    LXBUS_USER_CALLBACK_DATA Header;
    LXBUS_USER_CALLBACK_IPTABLES_DATA_TYPE IptablesDataType;
    union {
        struct {
            IP_ADDRESS_PREFIX InputPrefix;
            BOOLEAN Enable;
        } Masquerade;

        struct {
            IP_ADDRESS_PREFIX InputPrefix;
            BOOLEAN Enable;
        } Port;
    } Data;

} LXBUS_USER_CALLBACK_IPTABLES_DATA, *PLXBUS_USER_CALLBACK_IPTABLES_DATA;