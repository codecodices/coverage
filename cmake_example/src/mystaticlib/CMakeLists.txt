cmake_minimum_required(VERSION 2.8)

project(mystaticlib)
add_library(mystaticlib mystaticlib.cpp)

# target_include_directories(mystaticlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(helloDemo LINK_PUBLIC Hello)
