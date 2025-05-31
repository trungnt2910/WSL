set(HEADERS
    include/lxcore/lxbusapi.h
    include/lxcore/lxcoreapi.h
    include/windows/p9rdr.h
    include/Windows/wslsupport.h
    include/wsldeps.h)

add_custom_target(wsldepslib ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/wsldeps.lib)
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/wsldeps.lib
    COMMAND ${CMAKE_AR}
            /def:${CMAKE_CURRENT_SOURCE_DIR}/wsldeps.def
            /out:${CMAKE_CURRENT_BINARY_DIR}/wsldeps.lib
            ${CMAKE_STATIC_LINKER_FLAGS}
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/wsldeps.def
    COMMENT "Building wsldeps.lib"
)

add_library(wsldeps SHARED IMPORTED ${HEADERS})
set_property(TARGET wsldeps PROPERTY IMPORTED_IMPLIB ${CMAKE_CURRENT_BINARY_DIR}/wsldeps.lib)
add_dependencies(wsldeps wsldepslib)
