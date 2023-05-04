project(mySubProject)
find_package(iceoryx_posh CONFIG REQUIRED)
find_package(iceoryx_hoofs CONFIG REQUIRED)

add_executable(mySub sub.cpp)
target_link_libraries(mySub iceoryx_posh::iceoryx_posh)
