cmake_minimum_required(VERSION 3.6)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES
        GUIBarTest.cpp
        mainTest.cpp
        FileManageTest.cpp
        RiorseTest.cpp)

add_executable(ProgressBarTests ${TEST_SOURCE_FILES})
target_link_libraries(ProgressBarTests gtest gtest_main core)