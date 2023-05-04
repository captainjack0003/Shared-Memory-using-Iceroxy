project(myPubProject)

cmake_minimum_required(VERSION 3.0)

find_package(iceoryx_posh CONFIG REQUIRED)
find_package(iceoryx_hoofs CONFIG REQUIRED)
get_target_property(ICEORYX_CXX_STANDARD iceoryx_posh::iceoryx_posh CXX_STANDARD)

include(IceoryxPlatform)
include(IceoryxPackageHelper)

add_executable(myPub pub.cpp)

target_link_libraries(myPub PUBLIC iceoryx_posh::iceoryx_posh) 

