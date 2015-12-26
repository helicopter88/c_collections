cmake_minimum_required(VERSION 3.2)
project(c_collections)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Werror")

set(SOURCE_FILES collections/linked_list.c collections/linked_list.h collections/heap.c collections/heap.h collections/collection.h)
add_library(c_collections SHARED ${SOURCE_FILES})
