cmake_minimum_required(VERSION 3.3)
project(c_collections)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ConsoleApplication1/linked_list.c ConsoleApplication1/linked_list.h ConsoleApplication1/heap.c ConsoleApplication1/heap.h ConsoleApplication1/collection.h ConsoleApplication1/main.c.c)
add_executable(c_collections ${SOURCE_FILES} ConsoleApplication1/main.c.c)