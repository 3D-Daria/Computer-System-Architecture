cmake_minimum_required(VERSION 3.20)
project(hw_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw_1 main.cpp vehicle.cpp vehicle.h lorry.cpp lorry.h autobus.cpp autobus.h motorcar.cpp motorcar.h container.cpp container.h rnd.h)
