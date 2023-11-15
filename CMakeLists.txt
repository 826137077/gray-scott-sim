# CMake Minimum Version Number Requirements
cmake_minimum_required(VERSION 3.10)

# Project information
project (gray_scott_sim)
message(STATUS "Configuring Project: ${PROJECT_NAME}")
message(WARNING "This is a custom warning: Make sure to check dependencies.")

# Specifying the compiler
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Specify the generation target
add_executable(gs_test gs_test.cpp acutest.h)

# Enabling Testing
enable_testing()

# Add Test
add_test(NAME GS_Test COMMAND gs_test)
