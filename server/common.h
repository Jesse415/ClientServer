//
// Created by one on 8/29/19.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#ifdef _WIN32
    #include <winsock2.h>
    #include <winsock.h>
    #include <ws2tcpip.h>
    #define SO_REUSEPORT SO_EXCLUSIVEADDRUSE

#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <sys/utsname.h>
    #include <arpa/inet.h>
#endif

#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)
//#define socket socklen_t
#define BUFFER_SIZE 100000
#define PORT 8080
#ifndef SERVER_MISC_H
#define SERVER_MISC_H
#endif //SERVER_MISC_H
void listDirectory(char *filename, char *bufferaddr);
void receiveFrom(FILE *fp, char *buffer_file); // struct sockaddr_in address, socklen_t *addrlen);
void runFile(char *command, char *filename);
void sendFile(int sockfd, char *filename);
void systemInfo(char *bufferaddr);
