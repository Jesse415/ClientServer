//
// Created by one on 8/29/19.
//
#include "common.h"

void receiveFrom(FILE *fp, char *buffer_file){


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

