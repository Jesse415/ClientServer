// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <libgen.h>
#define BUFF_SIZE 1024
#define PORT 8080

void sendfile(FILE *fp, int sockfd){
    int n, total = 0;
    char sendline[BUFF_SIZE] = {0};
    while ((n = fread(sendline, sizeof(char), BUFF_SIZE, fp)) > 0)
    {
        total+=n;
        if (n != BUFF_SIZE && ferror(fp))
        {
            perror("Read File Error");
            exit(1);
        }

        if (send(sockfd, sendline, n, 0) == -1)
        {
            perror("Can't send file");
            exit(1);
        }
        memset(sendline, 0, BUFF_SIZE);
    }
}






int main(){

	int client_sock = 0, valread, total = 0 ;
	struct sockaddr_in serv_addr;
    char buffer[BUFF_SIZE] = {0};
    char filename[BUFF_SIZE] = {0};
    char *p_buffer = buffer;
    char *token[BUFF_SIZE];

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
		fgets(buffer, BUFF_SIZE, stdin);
		valread = write(client_sock, buffer, strlen(buffer));

		if(valread < 0){
		    perror("Error taking in writing");
		}

		if(strcmp(buffer, ":exit") == 0){
			close(client_sock);
			printf("[-] Disconnected from server.\n");
			exit(1);
		}

        for(int i = 0; i < strlen(p_buffer); i++) {
            token[i] = strtok_r(p_buffer, " ", &p_buffer);
            int length = strlen(token[i]);
            if (token[i][length-1] == '\n' || token[i][length-1] == '\t')
                token[i][length-1]  = '\0';
        }

//        char *filename = token[1];
//        if (filename == NULL){
//            perror("Can't get filename");
//            exit(1);
//        }

//        strncpy(filename, token[1], strlen(filename));
//        if (send(client_sock, filename, BUFF_SIZE, 0) == -1){
//            perror("Can't send filename");
//            exit(1);
//        }
//
        FILE *fp = fopen(token[1], "a");
        if (fp == NULL){
            perror("Can't open file");
            exit(1);
        }


        int ch = getc(fp); //Get initial input
        while(ch != EOF){
            putchar(ch);    //Process input
            ch = getc(fp);
        }

        sendfile(ch, client_sock);
        //puts("Send Success");
        printf("Send Success, NumBytes = %ld\n", total);
        fclose(fp);
        close(client_sock);

		//send(sock, buffer, strlen(buffer), 0);
		bzero(buffer,sizeof(buffer));
		valread = read(client_sock, buffer, BUFF_SIZE);

		if(valread < 0){
		    perror("Error reading from socket");
		}
		printf("Server: %s", buffer);
	}
	return 0;
}
