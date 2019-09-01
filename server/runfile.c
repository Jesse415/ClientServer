#include "common.h"

void runFile(char *command, char *filename){

    char str[BUFFER_SIZE] = {0};

    strcpy(str, command);
    strcat(str, " ");
    if(filename != NULL) {
        strcat(str, filename);
    }

    if(filename == NULL){
        printf("No file name given \n");
    }
    system(str);
    printf("Compile and run file %s \n", filename);
}
