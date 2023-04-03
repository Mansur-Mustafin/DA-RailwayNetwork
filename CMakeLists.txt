cmake_minimum_required(VERSION 3.23)
project(DA_RailwayNetwork)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA_RailwayNetwork main.cpp Code/Station.cpp Code/Station.h Code/Railway.cpp Code/Railway.h Code/Graph.cpp Code/Graph.h)
