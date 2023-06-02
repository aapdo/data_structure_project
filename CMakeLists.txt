cmake_minimum_required(VERSION 3.25)
project(data_structure_project C)

set(CMAKE_C_STANDARD 11)

add_executable(data_structure_project main.c reader/fileControl.h reader/fileControl.c utils.h data.h data.c search/hash.c)
#add_executable(data_structure_project search/search.h reader/fileControl.h reader/fileControl.c)
