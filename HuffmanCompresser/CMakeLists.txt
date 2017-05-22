cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_LIB HuffmanCompresser.cpp)

add_library(HuffmanCompresser STATIC ${SOURCE_LIB})
