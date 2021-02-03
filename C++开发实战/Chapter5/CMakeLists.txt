cmake_minimum_required(VERSION 3.15)
project(Chapter5)

set(CMAKE_CXX_STANDARD 11)

add_executable(Chapter5 main.cpp atm.cpp atm.h account.cpp account.h globalFile.h)