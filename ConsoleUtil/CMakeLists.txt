cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_EXE main.cpp FileWorker.cpp FileWorker.h)

add_executable(ConsoleUtil ${SOURCE_EXE})

target_link_libraries(ConsoleUtil HuffmanCompresser)



