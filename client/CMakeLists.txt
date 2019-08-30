cmake_minimum_required(VERSION 3.15)
project(client C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(client
        client.c
        common.h
        sendFile.c)
