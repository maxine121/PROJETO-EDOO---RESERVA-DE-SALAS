cmake_minimum_required(VERSION 4.0)
project(PROJETO-EDOO---RESERVA-DE-SALAS)

set(CMAKE_CXX_STANDARD 20)

add_executable(PROJETO-EDOO---RESERVA-DE-SALAS main.cpp
        src/sala.cpp
        headers/sala.h
        src/reserva.cpp
        headers/reserva.h
        src/admSalas.cpp
        headers/admSalas.h
        src/usuario.cpp
        headers/usuario.h
        src/admUsuario.cpp
        headers/admUsuario.h
        src/comumUsuario.cpp
        headers/comumUsuario.h
        src/gerenciadorUsuariosComuns.cpp
        headers/gerenciadorUsuariosComuns.h)