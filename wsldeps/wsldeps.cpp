#pragma comment(linker, "/EXPORT:_NtCreateNamedPipeFile=ntdll.NtCreateNamedPipeFile")
#pragma comment(linker, "/EXPORT:_NtQueryInformationFile=ntdll.NtQueryInformationFile")
#pragma comment(linker, "/EXPORT:_NtSetInformationFile=ntdll.NtSetInformationFile")
#pragma comment(linker, "/EXPORT:_NtQueryVolumeInformationFile=ntdll.NtQueryVolumeInformationFile")
#pragma comment(linker, "/EXPORT:_NtQueryDirectoryFile=ntdll.NtQueryDirectoryFile")
#pragma comment(linker, "/EXPORT:_NtReadFile=ntdll.NtReadFile")
#pragma comment(linker, "/EXPORT:_NtWriteFile=ntdll.NtWriteFile")
#pragma comment(linker, "/EXPORT:_ZwCreateDirectoryObject=ntdll.ZwCreateDirectoryObject")
#pragma comment(linker, "/EXPORT:_ZwCreateEvent=ntdll.ZwCreateEvent")
#pragma comment(linker, "/EXPORT:_ZwQueryEaFile=ntdll.ZwQueryEaFile")
#pragma comment(linker, "/EXPORT:_ZwSetEaFile=ntdll.ZwSetEaFile")
#pragma comment(linker, "/EXPORT:_ZwQueryKey=ntdll.ZwQueryKey")
#pragma comment(linker, "/EXPORT:_RtlDosPathNameToNtPathName_U_WithStatus=ntdll.RtlDosPathNameToNtPathName_U_WithStatus")

#include <Windows.h>

extern "C"
__declspec(dllexport) HRESULT WINAPI
WslDepsRegisterGnsRpcServer(void* SecurityDescriptor, UUID* EndpointId)
{
    return E_NOTIMPL;
}

extern "C"
__declspec(dllexport) HRESULT WINAPI
WslDepsUnregisterGnsRpcServer(UUID* EndpointId)
{
    return E_NOTIMPL;
}
