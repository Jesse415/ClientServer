#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#ifdef _WIN32
    #include <winsock2.h>
    #include <winsock.h>
    #include <ws2tcpip.h>
    #define SO_REUSEPORT SO_EXCLUSIVEADDRUSE

#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <sys/utsname.h>
    #include <arpa/inet.h>
#endif

#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)
#define BUFFER_SIZE 100000
#define PORT 8080
void sendFiles(int sockfd, char *filename);