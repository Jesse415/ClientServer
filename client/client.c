// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define PORT 8080

int main(){

	int client_sock = 0, valread ;
    	struct sockaddr_in serv_addr;
    	char buffer[1024] = {0};

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
	while(1){
		printf("Please enter the message: \t");
		bzero(buffer,sizeof(buffer));
	      	fgets(buffer, 1024, stdin);
	      	valread = write(client_sock, buffer, strlen(buffer));

	      	if(valread < 0){
	        	perror("Error taking in writing");
	      	}

		if(strcmp(buffer, ":exit") == 0){
			close(client_sock);
			printf("[-] Disconnected from server.\n");
			exit(1);
		}

	      	//send(sock, buffer, strlen(buffer), 0);
	      	bzero(buffer,sizeof(buffer));
	      	valread = read(client_sock, buffer, 1024);

	      	if(valread < 0){
	        	perror("Error reading from socket");
	      	}
	      	printf("Server: %s", buffer);
	}
	return 0;
}
