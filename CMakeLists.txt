cmake_minimum_required(VERSION 3.28)

project(leetcode CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

file(GLOB SRC_FILES *.cpp)
foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(IT_TARGET ${SRC_FILE} NAME_WLE)
    add_executable(${IT_TARGET} ${SRC_FILE})
    target_link_libraries(${IT_TARGET} GTest::gtest_main)
    gtest_discover_tests(${IT_TARGET})
endforeach()
