# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.10)

# 项目信息
project (test_gs)

# 指定生成目标
add_executable(gs_test gs_test.cpp acutest.h)
