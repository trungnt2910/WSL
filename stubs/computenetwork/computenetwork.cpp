#include <cstdlib>
#include <iostream>

#pragma comment(linker, "/EXPORT:HcnEnumerateNetworks@12=stub")
#pragma comment(linker, "/EXPORT:HcnCreateNetwork@16=stub")
#pragma comment(linker, "/EXPORT:HcnOpenNetwork@12=stub")
#pragma comment(linker, "/EXPORT:HcnQueryNetworkProperties@16=stub")
#pragma comment(linker, "/EXPORT:HcnCloseNetwork@4=stub")

#pragma comment(linker, "/EXPORT:HcnEnumerateEndpoints@12=stub")
#pragma comment(linker, "/EXPORT:HcnCreateEndpoint@20=stub")
#pragma comment(linker, "/EXPORT:HcnOpenEndpoint@12=stub")
#pragma comment(linker, "/EXPORT:HcnModifyEndpoint@12=stub")
#pragma comment(linker, "/EXPORT:HcnQueryEndpointProperties@16=stub")
#pragma comment(linker, "/EXPORT:HcnDeleteEndpoint@8=stub")
#pragma comment(linker, "/EXPORT:HcnCloseEndpoint@4=stub")

#pragma comment(linker, "/EXPORT:HcnRegisterServiceCallback@12=stub")
#pragma comment(linker, "/EXPORT:HcnUnregisterServiceCallback@4=stub")

#pragma comment(linker, "/EXPORT:HcnRegisterGuestNetworkServiceCallback@16=stub")
#pragma comment(linker, "/EXPORT:HcnUnregisterGuestNetworkServiceCallback@4=stub")
#pragma comment(linker, "/EXPORT:HcnCreateGuestNetworkService@16=stub")
#pragma comment(linker, "/EXPORT:HcnCloseGuestNetworkService@4=stub")
#pragma comment(linker, "/EXPORT:HcnModifyGuestNetworkService@12=stub")
#pragma comment(linker, "/EXPORT:HcnDeleteGuestNetworkService@8=stub")

extern "C" void stub()
{
    std::cerr << "Hyper-V is not supported on this platform." << std::endl;
    abort();
}
