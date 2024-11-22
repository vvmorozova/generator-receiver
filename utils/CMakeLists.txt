cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
project(utils)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
add_library(utils STATIC 
    src/utils.cpp
)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)