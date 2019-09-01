#include "common.h"

void listDirectory(char *filename, char *bufferadder){

    DIR *dir_ptr;
    struct dirent *direntp;
    char strbuffer[BUFFER_SIZE] = {0};

    if((dir_ptr = opendir(filename)) == NULL){
        fprintf(stderr, "ls: can't open %s\n", filename);
    }
    else {
        bzero(bufferadder, sizeof(bufferadder));
        while ((direntp = readdir(dir_ptr)) != NULL){
            sprintf(strbuffer, "%s\n", direntp->d_name);
            strcat(bufferadder, strbuffer);
        }
    }
    closedir(dir_ptr);
}
