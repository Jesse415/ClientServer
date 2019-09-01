cmake_minimum_required(VERSION 3.15)
project(client C)

set(CMAKE_C_STANDARD 11)

<<<<<<< HEAD
add_executable(client
        client.c)
=======
include_directories(.)

add_executable(client
        client.c
        common.h
        receive.c
        sendFile.c)
>>>>>>> develope
