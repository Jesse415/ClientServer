// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
#define BUFF_SIZE 1024



/* This function allows for the transfer of
 * files to the server from the client.
 */
//void send_file(char *prog_name, char *location, int sockfd){
//    printf("This function is working %s %s \n", prog_name, location);
//    if (send(sockfd, prog_name, BUFF_SIZE, 0) == -1)
//    {
//        perror("Can't send filename");
//        exit(1);
//    }
//
//    FILE *fp = fopen(argv[1], "rb");
//    if (fp == NULL)
//    {
//        perror("Can't open file");
//        exit(1);
//    }
//
//    sendfile(fp, sockfd);
//    //puts("Send Success");
//    printf("Send Success, NumBytes = %ld\n", total);
//    fclose(fp);
//    close(sockfd);
//}
void writefile(int sockfd, FILE *fp){
    ssize_t n;
    int total = 0;
    char buff[BUFF_SIZE] = {0};

    while ((n = recv(sockfd, buff, BUFF_SIZE, 0)) > 0){
        total+=n;
        if (n == -1){
            perror("Receive File Error");
            exit(1);
        }

        if (fwrite(buff, sizeof(char), n, fp) != n){
            perror("Write File Error");
            exit(1);
        }
        memset(buff, 0, BUFF_SIZE);
    }
}

void receive_file(char *prog_name, char *location, int sockfd, char *sin_addr){
    ssize_t total = 0;

    if (recv(sockfd, prog_name, BUFF_SIZE, 0) == -1){
        perror("Can't receive filename");
        exit(1);
    }

    FILE *fp = fopen(prog_name, "w");
    if (fp == NULL){
        perror("Can't open file");
        exit(1);
    }

    char addr[INET_ADDRSTRLEN];
    printf("Start receive file: %s from %s\n", prog_name, sin_addr);
    writefile(sockfd, fp);
    printf("Receive Success, NumBytes = %ld\n", total);


    fclose(fp);
}



int main(){

 	struct sockaddr_in address;
	int server_fd, new_socket, valread, opt = 1;
 	int addrlen = sizeof(address);
    char buffer[BUFF_SIZE] = {0};
	char *p_buffer = buffer;
	char *token[BUFF_SIZE];

	pid_t childpid; //Data type stands for process id.
	socklen_t addr_size; //Socklen_t is an unsigned opaque integral type length of at least 32 bits.

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        	perror("[-]Socket failed");
        	exit(EXIT_FAILURE);
	}

	printf("[+]Server Socket is created.\n");

	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
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
	}

	else {
		perror("[-]Listen");
		exit(EXIT_FAILURE);
	}

	while(1){
		//int newsockfd = accept(server_fd,(struct sockaddr *) &address, &addr_size);
		new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
 		if(new_socket < 0){
			exit(1);
		}

		/* inet_ntoa() converts the internet host address in to
		 * a string in IPv4 dotted-decimal notation.
		 * ntohs() Converts the unsigned short integer netshort
		 * from network byte order to host byte order.
		 */
		printf("Connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

		//if((childpid = fork()) == 0){
		//	close(server_fd);

			while(1){
				read(new_socket, buffer, BUFF_SIZE);

				if(strcmp(buffer, ":exit") == 0){
					printf("Disconnected from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
					break;
				}

				else{
				    //Split the intake args and make sure none have newline char or tab
				    for(int i = 0; i < strlen(p_buffer); i++) {
                        token[i] = strtok_r(p_buffer, " ", &p_buffer);
                        int length = strlen(token[i]);
                        if (token[i][length-1] == '\n' || token[i][length-1] == '\t')
                            token[i][length-1]  = '\0';
                    }

					if (strcmp(token[0], "put") == 0) {
					    receive_file(token[1], token[2], new_socket, inet_ntoa(address.sin_addr));
					}

					if (strcmp(token[0], "get") == 0) {
					    printf("Get was found");
					}

					if (strcmp(token[0], "run") == 0) {
					    printf("Run was found");
					}

					if (strcmp(token[0], "list") == 0) {
					    printf("List was found");
					}
				}
//			    printf("Client: %s\n", buffer);
			    bzero(buffer, sizeof(buffer));
			    send(new_socket, buffer, strlen(buffer), 0);
            }
		//}
	}
}
