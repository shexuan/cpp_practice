cmake_minimum_required(VERSION 3.15)
project(Reservation_System)

set(CMAKE_CXX_STANDARD 11)

add_executable(Reservation_System main.cpp identity.cpp identity.h student.cpp student.h teacher.cpp teacher.h manager.cpp manager.h globalFile.h computer_room.cpp computer_room.h order_file.cpp order_file.h)