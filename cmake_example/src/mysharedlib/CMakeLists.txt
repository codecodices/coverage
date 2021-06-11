cmake_minimum_required(VERSION 2.8)

project(mysharedlib)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
add_library(mysharedlib mysharedlib.cpp)

# target_include_directories(mystaticlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(helloDemo LINK_PUBLIC Hello)
