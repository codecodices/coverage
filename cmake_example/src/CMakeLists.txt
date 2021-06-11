cmake_minimum_required(VERSION 3.0)

project(example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

add_subdirectory(mysharedlib mystaticlib)
add_executable(example example.cpp)
target_include_directories(example PRIVATE ${PROJECT_SOURCE_DIR}/mystaticlib)
target_include_directories(example PRIVATE ${PROJECT_SOURCE_DIR}/mysharedlib)
target_link_directories(example PRIVATE ./mysharedlib/build)
target_link_directories(example PRIVATE ./mystaticlib/build)
target_link_libraries(example PUBLIC mysharedlib PRIVATE mystaticlib)
