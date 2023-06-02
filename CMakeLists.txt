cmake_minimum_required(VERSION 3.25)
project(data_structure_project C)

set(CMAKE_C_STANDARD 11)

add_executable(data_structure_project main.c search/search.h reader/fileControl.h reader/fileControl.c reader/reader.c reader/hashDataStructure.c reader/hashDataStructure.h utils.h)
#add_executable(data_structure_project search/search.h reader/fileControl.h reader/fileControl.c)
