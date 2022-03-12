cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(YZlib_Test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g -O3 -mavx -mfma")

set (GTEST_INCLUDE_DIRS ../3rd_Party/Google_Test/Linux/include)
set (GTEST_LIBS_DIR ../3rd_Party/Google_Test/Linux/lib)
set (GTEST_LIBRARIES gmock gmock_main gtest gtest_main)

add_subdirectory(../YZlib YZlib_build)
include_directories(${GTEST_INCLUDE_DIRS})
link_directories(${GTEST_LIBS_DIR})
macro(add_test name)
add_executable(${name} ${name}.cpp)
target_link_libraries(${name} ${GTEST_LIBRARIES} pthread)
endmacro()


macro(add_test_all name)
add_executable(${name}_all ${name}.cpp)
target_link_libraries(${name}_all YZlib ${GTEST_LIBRARIES} pthread)
endmacro()

add_test_all(All)