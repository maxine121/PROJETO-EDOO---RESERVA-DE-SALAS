cmake_minimum_required(VERSION 4.0)
project(tutoras)

set(CMAKE_CXX_STANDARD 20)

add_executable(tutoras main.cpp
        sala.cpp
        sala.h
        reserva.cpp
        reserva.h
        admSalas.cpp
        admSalas.h)