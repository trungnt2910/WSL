#include <cstdlib>
#include <iostream>

#define STUB_INTERNAL(name) \
    __pragma(comment(linker, "/EXPORT:" #name "=stub"))

#if _I386_
#define STUB(name, bytes) STUB_INTERNAL(name@##bytes)
#else
#define STUB(name, _) STUB_INTERNAL(name)
#endif

STUB(HcsCreateOperation, 8)
STUB(HcsCloseOperation, 4)
STUB(HcsWaitForOperationResult, 12)

STUB(HcsCreateComputeSystem, 20)
STUB(HcsOpenComputeSystem, 12)
STUB(HcsCloseComputeSystem, 4)
STUB(HcsStartComputeSystem, 12)
STUB(HcsTerminateComputeSystem, 12)
STUB(HcsGetComputeSystemProperties, 12)
STUB(HcsModifyComputeSystem, 16)
STUB(HcsSetComputeSystemCallback, 16)

STUB(HcsGetServiceProperties, 8)

STUB(HcsGrantVmAccess, 8)
STUB(HcsRevokeVmAccess, 8)

extern "C" void stub()
{
    std::cerr << "Hyper-V is not supported on this platform." << std::endl;
    abort();
}
