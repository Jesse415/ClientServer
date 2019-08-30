#include "common.h"

void listDirectory(char *filename, char *bufferadder){

    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(filename);

    // Unable to open directory stream
    if (!dir) {
        return;
    }
    while ((dp = readdir(dir)) != NULL){
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
            printf("%s\n", dp->d_name);

            // Construct new path from our base path
            strcpy(path, filename);
            strcat(path, "/");
            strcat(path, dp->d_name);
            listDirectory(path, bufferadder);
        }
    }
    closedir(dir);
}