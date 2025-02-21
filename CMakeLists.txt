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

if(TARGET GTest::gtest_main)
  message("Target was found")
endif()

enable_testing()
include(GoogleTest)

add_executable(fizzBuzz fizzBuzz.cpp)
target_link_libraries(fizzBuzz
  GTest::gtest_main
  GTest::gtest
)
gtest_discover_tests(fizzBuzz)

add_executable(reverseString reverseString.cpp)
target_link_libraries(reverseString
  GTest::gtest_main
  GTest::gtest
)
gtest_discover_tests(reverseString)
