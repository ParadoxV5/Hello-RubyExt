cmake_minimum_required(VERSION 3.25)
project(ext C)
set(CMAKE_C_STANDARD 99)

add_library(ext SHARED ext.c)
