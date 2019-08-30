//
// Created by one on 8/29/19.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <sys/utsname.h>

#define sendrecvflag 0
#define BUFFER_SIZE 1024
#define PORT 8080
#ifndef SERVER_MISC_H
#define SERVER_MISC_H
#endif //SERVER_MISC_H
void listDirectory(char *filename, char *bufferaddr);
void receiveFrom(FILE *fp, char *buffer_file); // struct sockaddr_in address, socklen_t *addrlen);
void runFile(char *filename);
void sendFile(int sockfd, char *filename);
void systemInfo(char *bufferaddr);
