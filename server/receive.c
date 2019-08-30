//
// Created by one on 8/29/19.
//
#include "common.h"

int recvFile(char *buf, int s){
    int i;
    char ch;
    for (i = 0; i < s; i++) {
        ch = buf[i];
        if (ch == EOF)
            return 1;
        else
            printf("%c", ch);
    }
    return 0;
}

void receiveFrom(int server_fd, FILE *fp, struct sockaddr_in address, socklen_t *addrlen){ //, char *fromaddr){
    int b, total = 0, confd = 0;
    char buffer[BUFFER_SIZE];


    printf("\n---------Data Received---------\n");

    while (1) {
        // receive
//        nBytes = recvfrom(sockfd, net_buf, NET_BUF_SIZE,
//                          sendrecvflag, (struct sockaddr*)&addr_con,
//                          &addrlen);
        b = recvfrom(server_fd, buffer, BUFFER_SIZE, sendrecvflag, (struct sockaddr*)&address, addrlen);
        printf("%d", b);

        if (fwrite(buffer, sizeof(char), b, fp) != b) {
            perror("Write File Error");
            break;
        }

        // process
//        if (recvFile(buffer, BUFFER_SIZE)) {
//            break;
//        }
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
