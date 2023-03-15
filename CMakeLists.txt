cmake_minimum_required(VERSION 3.23)
project(DA_RailwayNetwork)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA_RailwayNetwork main.cpp Station.cpp Station.h Railway.cpp Railway.h Graph.cpp Graph.h)
