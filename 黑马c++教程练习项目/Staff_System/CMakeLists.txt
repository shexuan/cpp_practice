cmake_minimum_required(VERSION 3.15)
project(Staff_System)

set(CMAKE_CXX_STANDARD 11)

add_executable(Staff_System main.cpp WorkerManager.cpp WorkerManager.h workers.cpp workers.h boss.cpp boss.h manager.cpp manager.h employee.cpp employee.h)