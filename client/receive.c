//
// Created by one on 8/29/19.
//
#include "common.h"

void receiveFrom(int server_fd, FILE *fp, char *buffer_file){


    printf("\n---------Data Received---------\n");

    while (1) {
        // receive
        if(fprintf(fp, buffer_file)<0){
            perror("Write error");
        }
        fclose(fp);
        break;
    }
    printf("\n-------------------------------\n");

}

//if(fp != NULL) {
//        while ((b = recvfrom(server_fd, buffer, BUFFER_SIZE, sendrecvflag, (struct sockaddr*)&address, &addrlen)) > 0) {
//            total += b;
//            if (b == -1) {
//                perror("Receive File Error");
//                exit(1);
//            }
//
//            if (fwrite(buffer, sizeof(char), b, fp) != b) {
//                perror("Write File Error");
//                exit(1);
//            }
//            memset(buffer, 0, BUFFER_SIZE);
//        }
//    }
//    fclose(fp);
//    close(confd);
//}
