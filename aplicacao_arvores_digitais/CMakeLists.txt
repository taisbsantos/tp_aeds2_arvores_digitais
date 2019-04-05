cmake_minimum_required(VERSION 3.13)
project(aplicacao_arvores_digitais C)

set(CMAKE_C_STANDARD 99)

add_executable(aplicacao_arvores_digitais main.c tst.c tst.h pilha.c pilha.h patricia.c patricia.h)