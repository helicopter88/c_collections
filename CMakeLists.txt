cmake_minimum_required(VERSION 3.2)
project(c_collections)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    collections/collection.h
    collections/heap.c
    collections/heap.h
    collections/linked_list.c
    collections/linked_list.h main.c)

add_executable(c_collections ${SOURCE_FILES} main.c)
