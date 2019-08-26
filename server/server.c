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

/* This function allows for the transfer of
 * files to the server from the client.
 */
//void send_recieve_file(){
//	while (1) {
//		printf("\nWaiting for file name...\n");
//
//		// receive file name
//		bzero(buffer, sizeof(buffer)); //Clear buffer
//        	read(new_socket, buffer, 1024);
//
//		nBytes = recvfrom(sockfd, net_buf, NET_BUF_SIZE, sendrecvflag,
//				(struct sockaddr*)&addr_con, &addrlen);
//
//        	fp = fopen(net_buf, "r");
//        	printf("\nFile Name Received: %s\n", net_buf);
//        	if (fp == NULL)
//            	printf("\nFile open failed!\n");
//        els
//            	printf("\nFile Successfully opened!\n");
//
//        	while(1){
//
//            		// process
//            		if (sendFile(fp, net_buf, NET_BUF_SIZE)) {
//                		sendto(sockfd, net_buf,
//					NET_BUF_SIZE, sendrecvflag,
//					(struct sockaddr*)&addr_con, addrlen);
//                	break;
//            	}
//
//            	// send
//            	sendto(sockfd, net_buf, NET_BUF_SIZE, sendrecvflag,
//				(struct sockaddr*)&addr_con, addrlen);
//            	clearBuf(net_buf);
//        	}
//        	if (fp != NULL)
//            	fclose(fp);
//    	}
//}
//

int main(){

 	struct sockaddr_in address;
	int server_fd, new_socket, valread, opt = 1;
 	int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char break_down[1024] = {0};
	char *p_buffer = buffer;
	char *token;

	pid_t childpid; //Data type stands for process id.
	socklen_t addr_size; //Socklen_t is an unsigned opaque integral type length of at least 32 bits.

    	// Creating socket file descriptor
    	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        	perror("[-]Socket failed");
        	exit(EXIT_FAILURE);
    	}

	printf("[+]Server Socket is created.\n");

    	// Forcefully attaching socket to the port 8080
    	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))){
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

	while(1){
		//int newsockfd = accept(server_fd,(struct sockaddr *) &address, &addr_size);
		new_socket = accept(server_fd, (struct sockaddr *)&address,
        				               	(socklen_t*)&addrlen);
 		if(new_socket < 0){
			exit(1);
		}

		/* inet_ntoa() converts the internet host address in to
		 * a string in IPv4 dotted-decimal notation.
		 * ntohs() Converts the unsigned short integer netshort
		 * from network byte order to host byte order.
		 */
		printf("Connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));


		if((childpid = fork()) == 0){
			close(server_fd);

			while(1){
				read(new_socket, buffer, 1024);

				if(strcmp(buffer, ":exit") == 0){
					printf("Disconnected from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
					break;
				}
        else{

					while((token = strtok_r(p_buffer, " ", &p_buffer))){
						printf("P_buffer %s\n", token);

            for(int i =0; i<strlen(break_down); i++){
              break_down[i] = token;
              printf("This is breakdown: %s : Len %d \n", break_down, strlen(break_down));
            }
          }
					if(strcmp(token, "put") == 0){
						printf("Put was found");
					}

					if(strcmp(token, "get") == 0){
						printf("Get was found");
					}

					if(strcmp(token, "run") == 0){
						printf("Run was found");
					}

					if(strcmp(token, "list") == 0){
						printf("List was found");
					}
        }
			printf("Client: %s\n", buffer);
			bzero(buffer, sizeof(buffer));
			send(new_socket, buffer, strlen(buffer), 0);
      }
		}
	}
	close(new_socket);

  return 0;
}
