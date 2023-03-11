cmake_minimum_required (VERSION 3.2)

set(MODULE_NAME "dsimlog")

include_directories(include)

set(CXX_SOURCES
    Test.cpp
    UdpReceiver.cpp
)

add_executable(${MODULE_NAME} ${CXX_SOURCES})

install(TARGETS ${MODULE_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)