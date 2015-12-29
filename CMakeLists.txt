cmake_minimum_required(VERSION 3.2)
project(c_collections)

set(CMAKE_C_FLAGS "${CFLAGS} -std=c11 -pedantic -Wall -Wextra -Werror")

set(SOURCE_FILES main.c collections/linked_list.c collections/linked_list.h collections/heap.c collections/heap.h collections/collection.h)
add_executable(c_collections SHARED ${SOURCE_FILES})
add_library(c_collections SHARED ${SOURCE_FILES})