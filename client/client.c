// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(){

	int client_sock = 0, valread ;
	struct sockaddr_in serv_addr;
	char buffer[BUFFER_SIZE] = {0};
    char *p_buffer = buffer;
    char *token[BUFFER_SIZE];

	//If there is an error creating the socket
	if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
	    printf("\n [-]Socket creation error \n");
	    return -1;
	}

	printf("[+] Client Socket is made.\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
	    printf("\nInvalid address/ Address not supported \n");
	    return -1;
	}

	if(connect(client_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
	    printf("\n[-]Connection Failed \n");
	    return -1;
	}

	printf("[+] Client connected to Server.\n");

	//This is to keep the connection messages between client and server going
	while(1) {
        printf("Please enter the message: \t");
        bzero(buffer, sizeof(buffer));
        fgets(buffer, BUFFER_SIZE, stdin);

        /*This sends a message to the server.
         */
        valread = write(client_sock, buffer, strlen(buffer));

        /* This is where the code to open a file and send it
         * to the server should go.
         */
        for (int i = 0; i < strlen(buffer); i++) {
            token[i] = strtok_r(p_buffer, " ", &p_buffer);
            int length = strlen(token[i]);
            if (token[i][length - 1] == '\n' || token[i][length - 1] == '\t') {
                token[i][length - 1] = '\0';
            }
        }

        if (strcmp(token[0], ":exit") == 0) {
            close(client_sock);
            printf("[-] Disconnected from server.\n");
            exit(1);
        }


        if (valread < 0) {
            perror("Error taking in writing");
        }
        if (strcmp(token[0], "put") == 0 ){
            //sendto();
        } else if (strcmp(token[0], "get") == 0 ){
            //recvfrom();
        } else if (strcmp(token[0], "run") == 0) {
            printf("Run was found");
        } else if (strcmp(token[0], "list") == 0) {
            printf("List was found");
        }

        //send(sock, buffer, strlen(buffer), 0);
        bzero(buffer, sizeof(buffer));
        valread = read(client_sock, buffer, BUFFER_SIZE);

        if (valread < 0) {
            perror("Error reading from socket");
        }
        printf("Server: %s\n", buffer);
    }
}
