#include "common.h"

ssize_t total=0;
void sendFiles(int sockfd, char *filename){
    int b;
    char sendbuffer[BUFFER_SIZE] = {0};
    FILE *fp;
    fp = fopen(filename, "rb");
    if(fp == NULL){
        perror("File");
    }
    while ((b = fread(sendbuffer, sizeof(char), BUFFER_SIZE, fp)) > 0){
        total+=b;
        if (b != BUFFER_SIZE && ferror(fp)){
            perror("Read File Error");
            exit(1);
        }

        if (send(sockfd, sendbuffer, b, 0) == -1){
            perror("Can't send file");
            exit(1);
        }
        memset(sendbuffer, 0, BUFFER_SIZE);
    }
    printf("Send Success, NumBytes = %ld\n", total);
    fclose(fp);
}
