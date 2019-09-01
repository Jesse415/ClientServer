// Client side C/C++ program to demonstrate Socket programming
#include "common.h"

int main() {

    int client_sock = 0, valread, length, i;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char *token[BUFFER_SIZE];

    //If there is an error creating the socket
    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n [-]Socket creation error \n");
        return -1;
    }

    printf("[+] Client Socket is made.\n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(client_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n[-]Connection Failed \n");
        return -1;
    }

    printf("[+] Client connected to Server.\n");
    printf("[+] Command list are:\n"
           "put <absolute directory>/<file name src> <absolute directory>/<file name dest>\n"
           "list <absolute directory>/<file name src>\n"
           "get <absolute directory>/<file name src>\n"
           "run <Command>\n"
           "sys\n");

    //This is to keep the connection messages between client and server going
    while (1) {
        printf("Please enter the message: \t");
        bzero(buffer, sizeof(buffer));
        fgets(buffer, BUFFER_SIZE, stdin);

        char *p_buffer = buffer;

        /*This sends a message to the server.
         */
        valread = write(client_sock, buffer, strlen(buffer));
        if (valread < 0) {
            perror("Error writing from socket");
        }

        /* This is where the code to open a file and send it
         * to the server should go.
         */
        for (i = 0; i < strlen(buffer); i++) {
            if (strcmp(p_buffer, "\000") == 0) {
                break;
            }
            token[i] = strtok_r(p_buffer, " ", &p_buffer);
            length = strlen(token[i]);
            if (token[i][length - 1] == '\n' || token[i][length - 1] == '\t') {
                token[i][length - 1] = '\0';
            }
        }

        if (strcmp(token[0], ":exit") == 0) {
            close(client_sock);
            printf("[-] Disconnected from server.\n");
            return 1;
        }


        if (strcmp(token[0], "put") == 0) {
            sendFiles(client_sock, token[1]);
        } else if (strcmp(token[0], "get") == 0) {
            bzero(buffer, sizeof(buffer));
            valread = read(client_sock, buffer, BUFFER_SIZE);

            if (valread < 0) {
                perror("Error reading from socket");
            } else {
                printf("Server: %s\n", buffer);
            }
        } else if (strcmp(token[0], "run") == 0) {
            printf("Running %s...\n", token[1]);
        } else if (strcmp(token[0], "list") == 0) {
            printf("Listing directory...\n");
        } else if (strcmp(token[0], "sys") == 0) {
            read(client_sock, buffer, BUFFER_SIZE);
            printf("Server: \n%s\n", buffer);
        }

        //send(sock, buffer, strlen(buffer), 0);
        bzero(buffer, sizeof(buffer));
        valread = read(client_sock, buffer, BUFFER_SIZE);

        if (valread < 0) {
            perror("Error reading from socket");
        } else {
            printf("Server: %s\n", buffer);
        }
        //Clear buffers
        bzero(token, sizeof(token));
        bzero(p_buffer, sizeof(*p_buffer));
        bzero(buffer, sizeof(buffer));
    }
}