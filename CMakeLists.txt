# 指定运行此配置文件所需的 CMake 的最低版本
cmake_minimum_required (VERSION 2.8.11)

#命令表示项目的名称是 Demo1
project (ConcurrencyTest)

#添加-std=c++11选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 设置源码根路径，即 cpp 目录
set(SRC_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
message(${SRC_ROOT_PATH})

# 定义要编译的文件列表变量
file(GLOB CPP_FILES_IN_UTILS "${SRC_ROOT_PATH}/test/*.cpp")

# 设置要编译的源文件
set(SOURCE_FILES ${CPP_FILES_IN_UTILS})

# include 头文件目录
include_directories(${SRC_ROOT_PATH}/)

#命令表示生成项目的名称是 test
add_executable(test ${SOURCE_FILES})