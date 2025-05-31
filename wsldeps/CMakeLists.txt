set(SOURCES
    wsldeps.cpp)

    set(HEADERS
    include/lxcore/lxbusapi.h
    include/lxcore/lxcoreapi.h
    include/windows/p9rdr.h
    include/Windows/wslsupport.h
    include/wsldeps.h)

add_library(wsldeps SHARED ${HEADERS} ${SOURCES})
target_link_options(wsldeps PRIVATE /IMPLIB:${BIN}/lib/wsldeps.lib)
target_link_libraries(wsldeps ntdll.lib)
