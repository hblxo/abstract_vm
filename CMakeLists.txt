                                      cmake_minimum_required(VERSION 2.8.4)
                                      project(avm)

                                      include_directories(srcs)
                                      include_directories(includes)
                                      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

                                      add_custom_target(avm COMMAND make -C ${avm_SOURCE_DIR}
                                              CLION_EXE_DIR=${PROJECT_BINARY_DIR})

                                      add_executable(includes srcs/main.cpp srcs/LogClass.cpp includes/LogClass.hpp includes/eVerboseLevel.hpp includes/GlobalVariables.hpp srcs/ErrorHandlerClass.cpp includes/ErrorHandlerClass.hpp)