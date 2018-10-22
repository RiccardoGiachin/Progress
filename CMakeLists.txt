cmake_minimum_required(VERSION 3.12)
project(ProgressBar)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProgressBar main.cpp Observer.h Subject.h Display.h ResourceFile.cpp ResourceFile.h Exception.h FileManager.cpp FileManager.h)