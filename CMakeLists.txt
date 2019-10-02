cmake_minimum_required(VERSION 2.8.4)
project(avm)

include_directories(includes)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_custom_target(mytest COMMAND make -C ${avm_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

add_executable(includes srcs/main.cpp)
