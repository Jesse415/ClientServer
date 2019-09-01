// Server side C/C++ program to demonstrate Socket programming
<<<<<<< HEAD
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(){

    struct sockaddr_in address;
	int server_fd, new_socket, valread, opt = 1;
	int addrlen = sizeof(address);
	char buffer[BUFFER_SIZE] = {0};
    char *p_buffer = buffer;
=======
#include "common.h"

int main(){

    pid_t childpid; //Data type stands for process id.
    socklen_t addr_size; //Socklen_t is an unsigned opaque integral type length of at least 32 bits.
    ssize_t total=0;

    struct sockaddr_in address;
    int server_fd, new_socket, valread, opt = 1, length, i;
	int addrlen = sizeof(address);
	char home[2] = ".";
	char buffer[BUFFER_SIZE] = {0};
>>>>>>> develope
    char *token[BUFFER_SIZE];


	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
	    perror("[-]Socket failed");
	    exit(EXIT_FAILURE);
	}

	printf("[+]Server Socket is created.\n");

	// Forcefully attaching socket to the port 8080
<<<<<<< HEAD
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))){
=======
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
>>>>>>> develope
	    perror("[-]Setsockopt");
	    exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );

	// Forcefully attaching socket to the port 8080
	valread = bind(server_fd, (struct sockaddr *)&address, sizeof(address));
	if(valread < 0){
	    perror("[-]Bind failed");
	    exit(EXIT_FAILURE);
	}
	printf("[+]Bind to port %d\n", PORT);

	if(listen(server_fd, 10) == 0){
		printf("[+]Listening....\n");
	} else {
		perror("[-]Listen");
		exit(EXIT_FAILURE);
	}

	/* After connection jump into this while loop, fork
	 * off and run args from the clients.
	 */
<<<<<<< HEAD
	while(1){
		new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen);
 		if(new_socket < 0){
			exit(1);
		}

		/* inet_ntoa() converts the internet host address in to
		 * a string in IPv4 dotted-decimal notation.
		 * ntohs() Converts the unsigned short integer netshort
		 * from network byte order to host byte order.
		 */
		printf("Connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

//		if((childpid = fork()) == 0){
//			close(server_fd);

			//Read in args from client and run services.
			while(1){
				read(new_socket, buffer, BUFFER_SIZE);

				printf(buffer);

				//Break down buffer to passable args
                for (int i = 0; i < strlen(buffer); i++) {
                    token[i] = strtok_r(p_buffer, " ", &p_buffer);
                    int length = strlen(token[i]);
=======
	while(1) {
        new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
        if (new_socket < 0) {
            exit(1);
        }

        /* inet_ntoa() converts the internet host address in to
         * a string in IPv4 dotted-decimal notation.
         * ntohs() Converts the unsigned short integer netshort
         * from network byte order to host byte order.
         */
        printf("Connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        if ((childpid = fork()) == 0) {
            close(server_fd);
            break;
        }
    }

			//Read in args from client and run services.
			while(1){
			    printf("Waiting for command....\n");
				valread = read(new_socket, buffer, BUFFER_SIZE);
                char *p_buffer = buffer;

                if (valread < 0) {
                    perror("Error reading from socket");
                } else {
                    printf("Client: %s\n", buffer);

				//Break down buffer to passable args
                for (i = 0; i < strlen(buffer); i++) {
                    if(strcmp(p_buffer, "\000") == 0){
                        break;
                    }
                    token[i] = strtok_r(p_buffer, " ", &p_buffer);
                    length = strlen(token[i]);
>>>>>>> develope
                    if (token[i][length - 1] == '\n' || token[i][length - 1] == '\t') {
                        token[i][length - 1] = '\0';
                    }
                }

                if(strcmp(buffer, ":exit") == 0){
					printf("Disconnected from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
<<<<<<< HEAD
					break;
				}

                if (strcmp(token[0], "put") == 0 ){
                    printf("PUT FOUND\n");
                    //recvfrom();
                } else if (strcmp(token[0], "get") == 0 ){
                    //sendto();
                } else if (strcmp(token[0], "run") == 0) {
                    printf("Run was found");
                } else if (strcmp(token[0], "list") == 0) {
                    printf("List was found");
                }
                printf("Client: %s\n", buffer);
                bzero(buffer, sizeof(buffer));
                strcpy(buffer, "DONE!");
                send(new_socket, buffer, strlen(buffer), 0);
			}
		}
	}
//}
=======
                    exit(1);
				}

                //recieve file from client
                if (strcmp(token[0], "put") == 0 ){
                    FILE *fp = fopen(token[2], "wb");
                    if (fp == NULL){
                        bzero(buffer, sizeof(buffer));
                        strcpy(buffer, strerror(errno));
                        strcat(buffer, "\n");
                        send(new_socket, buffer, strlen(buffer), 0);
                        bzero(buffer, sizeof(buffer));
                        strcpy(buffer, "DONE!");
                        send(new_socket, buffer, strlen(buffer), 0);
                        continue;
                    }
                    printf("Start receive file: %s \n", token[1]);
                    read(new_socket, buffer, BUFFER_SIZE);
                    receiveFrom(fp, buffer);
                    printf("Receive Success, NumBytes = %ld\n", total);
                    bzero(buffer, sizeof(buffer));
                    strcpy(buffer, "DONE!");
                    send(new_socket, buffer, strlen(buffer), 0);
                }
                //Send files to client
                else if (strcmp(token[0], "get") == 0 ){
                    FILE *fp = fopen(token[1], "rb");
                    if (fp == NULL){
                        bzero(buffer, sizeof(buffer));
                        strcpy(buffer, strerror(errno));
                        strcat(buffer, "\n");
                        send(new_socket, buffer, strlen(buffer), 0);
                        bzero(buffer, sizeof(buffer));
                        strcpy(buffer, "DONE!");
                        send(new_socket, buffer, strlen(buffer), 0);
                        continue;
                    }
                    printf("Start sending file: %s \n", token[1]);
                    sendFile(new_socket, token[1]);
                    printf("Sending Successful, NumBytes = %ld\n", total);
                    bzero(buffer, sizeof(buffer));
                    strcpy(buffer, "DONE!");
                    send(new_socket, buffer, strlen(buffer), 0);
                }
                // Run files located on the server side
                else if (strcmp(token[0], "run") == 0) {
                    printf("File %s is starting.\n", token[1]);
                    runFile(token[1], token[2]);
                    bzero(buffer, sizeof(buffer));
                    strcpy(buffer, "DONE!");
                    send(new_socket, buffer, strlen(buffer), 0);
                }
                // List files within the directory
                else if (strcmp(token[0], "list") == 0){
                    if(token[1] == NULL){
                        token[1] = home;
                    }
                    listDirectory(token[1], buffer);
                    send(new_socket, buffer, strlen(buffer), 0);
                }
                else if (strcmp(token[0], "sys") == 0){
                    bzero(buffer, sizeof(buffer));
                    systemInfo(buffer);
                    send(new_socket, buffer, strlen(buffer), 0);
                    bzero(buffer, sizeof(buffer));
                    strcpy(buffer, "DONE!");
                    send(new_socket, buffer, strlen(buffer), 0);
                }
                else{
                    bzero(buffer, sizeof(buffer));
                    strcpy(buffer, "Invalid input, Try again!");
                    send(new_socket, buffer, strlen(buffer), 0);
                }

                //Clear buffers
                bzero(token, sizeof(token));
                bzero(p_buffer, sizeof(*p_buffer));
                bzero(buffer, sizeof(buffer));
                }
			}
}
>>>>>>> develope
