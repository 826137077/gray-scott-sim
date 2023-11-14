# CMake Minimum Version Number Requirements
cmake_minimum_required(VERSION 3.10)

# Project information
project (test_gs)

# Specify the generation target
add_executable(gs_test gs_test.cpp acutest.h)
