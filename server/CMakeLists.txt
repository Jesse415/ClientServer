cmake_minimum_required(VERSION 3.15)
project(server C)

set(CMAKE_C_STANDARD 11)

<<<<<<< HEAD
add_executable(server
        server.c)
=======
include_directories(.)

add_executable(server
        common.h
        listdir.c
        receive.c
        runfile.c
        sendFile.c
        server.c
        sysinfo.c)
>>>>>>> develope
