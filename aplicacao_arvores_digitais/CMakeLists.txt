cmake_minimum_required(VERSION 3.13)
project(aplicacao_arvores_digitais C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(aplicacao_arvores_digitais
        lista_encadeada.c
        lista_encadeada.h
        main.c
        patricia.c
        patricia.h
        pilha.c
        pilha.h
        tst.c
        tst.h)
