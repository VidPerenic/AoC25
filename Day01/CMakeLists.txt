cmake_minimum_required(VERSION 3.10)
project(cpp_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use shared runtime library to match GoogleTest
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

# Add debug/release flags
if(MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG "/Zi /Od /W4 /MDd")
  set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG /MD")
else()
  set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
endif()

# Set default build type to Debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Main executable
add_executable(main main.cpp functions.cpp)
set_target_properties(main PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Testing
enable_testing()

# Test executable
add_executable(tests tests/test_main.cpp functions.cpp)
target_link_libraries(tests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
