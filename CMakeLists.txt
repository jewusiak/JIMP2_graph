cmake_minimum_required(VERSION 3.16)
project(JIMP2_graph C)

set(CMAKE_C_STANDARD 90)

add_executable(JIMP2_graph main.c BFS.c BFS.h files.c files.h graph.c graph.h path_search.c path_search.h)
