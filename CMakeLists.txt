cmake_minimum_required(VERSION 3.14)

# set (CMAKE_C_COMPILER "/usr/bin/clang-12")
# set (CMAKE_CXX_COMPILER "/usr/bin/clang++-12")
set (CMAKE_C_COMPILER "/usr/bin/gcc-10")
set (CMAKE_CXX_COMPILER "/usr/bin/g++-10")

set(CMAKE_CXX_STANDARD 17)              # Compile as C++17.
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # Require C++17 support.

# set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES /usr/include /usr/local/include /usr/lib/gcc/x86_64-linux-gnu/10/include)
# link_directories(/usr/include /usr/local/include /usr/lib/gcc/x86_64-linux-gnu/10/include)

# if(NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
# endif()
# message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
# message(STATUS "C flags, Debug configuration: ${CMAKE_C_FLAGS_DEBUG}")
# message(STATUS "C flags, Release configuration: ${CMAKE_C_FLAGS_RELEASE}")
# message(STATUS "C flags, Release configuration with Debug info: ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
# message(STATUS "C flags, minimal Release configuration: ${CMAKE_C_FLAGS_MINSIZEREL}")
# message(STATUS "C++ flags, Debug configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
# message(STATUS "C++ flags, Release configuration: ${CMAKE_CXX_FLAGS_RELEASE}")
# message(STATUS "C++ flags, Release configuration with Debug info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
# message(STATUS "C++ flags, minimal Release configuration: ${CMAKE_CXX_FLAGS_MINSIZEREL}")

list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

project(MetaNN)

include_directories(${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/Tests)

add_subdirectory(MyTests)
add_subdirectory(Tests)

get_property(include_dirs DIRECTORY PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${include_dirs})
    message("Included directory: ${dir}")
endforeach()
