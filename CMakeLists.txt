cmake_minimum_required(VERSION 4.0)
project(PROJETO-EDOO---RESERVA-DE-SALAS)

set(CMAKE_CXX_STANDARD 20)

add_executable(PROJETO-EDOO---RESERVA-DE-SALAS main.cpp
        sala.cpp
        sala.h
        reserva.cpp
        reserva.h
        admSalas.cpp
        admSalas.h)