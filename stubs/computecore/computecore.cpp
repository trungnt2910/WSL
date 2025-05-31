#include <cstdlib>
#include <iostream>

#pragma comment(linker, "/EXPORT:HcsCreateOperation@8=stub")
#pragma comment(linker, "/EXPORT:HcsCloseOperation@4=stub")
#pragma comment(linker, "/EXPORT:HcsWaitForOperationResult@12=stub")

#pragma comment(linker, "/EXPORT:HcsCreateComputeSystem@20=stub")
#pragma comment(linker, "/EXPORT:HcsOpenComputeSystem@12=stub")
#pragma comment(linker, "/EXPORT:HcsCloseComputeSystem@4=stub")
#pragma comment(linker, "/EXPORT:HcsStartComputeSystem@12=stub")
#pragma comment(linker, "/EXPORT:HcsTerminateComputeSystem@12=stub")
#pragma comment(linker, "/EXPORT:HcsGetComputeSystemProperties@12=stub")
#pragma comment(linker, "/EXPORT:HcsModifyComputeSystem@16=stub")
#pragma comment(linker, "/EXPORT:HcsSetComputeSystemCallback@16=stub")

#pragma comment(linker, "/EXPORT:HcsGetServiceProperties@8=stub")

#pragma comment(linker, "/EXPORT:HcsGrantVmAccess@8=stub")
#pragma comment(linker, "/EXPORT:HcsRevokeVmAccess@8=stub")

extern "C" void stub()
{
    std::cerr << "Hyper-V is not supported on this platform." << std::endl;
    abort();
}
