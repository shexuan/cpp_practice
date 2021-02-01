cmake_minimum_required(VERSION 3.15)
project(Speech_competition)

set(CMAKE_CXX_STANDARD 11)

add_executable(Speech_competition main.cpp speech_manager.cpp speech_manager.h speaker.cpp speaker.h)