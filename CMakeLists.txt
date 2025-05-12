cmake_minimum_required(VERSION 3.29)
set(CMAKE_GENERATOR "Unix Makefiles")
project(Progetto_lab C)

set(CMAKE_C_STANDARD 11)

add_executable(Progetto_lab main.c
        Data_set.h
        Data_set.c
        info_Programma.h
        info_Programma.c
        Scena_menager.h
        Scena_menager.c
)