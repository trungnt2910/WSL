#include <cstdlib>
#include <iostream>

#define STUB_INTERNAL(name) \
    __pragma(comment(linker, "/EXPORT:" #name "=stub"))

#if _I386_
#define STUB(name, bytes) STUB_INTERNAL(name@##bytes)
#else
#define STUB(name, _) STUB_INTERNAL(name)
#endif

STUB(HcnEnumerateNetworks, 12)
STUB(HcnCreateNetwork, 16)
STUB(HcnOpenNetwork, 12)
STUB(HcnQueryNetworkProperties, 16)
STUB(HcnCloseNetwork, 4)

STUB(HcnEnumerateEndpoints, 12)
STUB(HcnCreateEndpoint, 20)
STUB(HcnOpenEndpoint, 12)
STUB(HcnModifyEndpoint, 12)
STUB(HcnQueryEndpointProperties, 16)
STUB(HcnDeleteEndpoint, 8)
STUB(HcnCloseEndpoint, 4)

STUB(HcnRegisterServiceCallback, 12)
STUB(HcnUnregisterServiceCallback, 4)

STUB(HcnRegisterGuestNetworkServiceCallback, 16)
STUB(HcnUnregisterGuestNetworkServiceCallback, 4)
STUB(HcnCreateGuestNetworkService, 16)
STUB(HcnCloseGuestNetworkService, 4)
STUB(HcnModifyGuestNetworkService, 12)
STUB(HcnDeleteGuestNetworkService, 8)

extern "C" void stub()
{
    std::cerr << "Hyper-V is not supported on this platform." << std::endl;
    abort();
}
