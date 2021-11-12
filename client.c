#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUF 1024

int main(int argc, char * argv[]) {
    int sfd;
    struct sockaddr_in address;
    int portn;
    char buff[BUF];
  


    if (argc < 2) {
        portn = 12345;
    } else {
        portn = atoi(argv[1]);
    }
    

    sfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sfd == -1) {
        perror("sfd");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(portn);
    
    inet_aton("127.0.0.1", &address.sin_addr);

    if(connect(sfd,(struct sockaddr *) &address, sizeof(address)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
     }

    while(1) {
        printf("Enter some text:\n>");

        if (fgets(buff, BUF, stdin) == NULL) {
            break;
        }

       if ( write(sfd, buff, strlen(buff)) == -1) {
           perror("write");
           break;
       }

       memset(buff, 0, BUF);

       while(read(sfd, buff, BUF) > 1) {
        printf("server: %s" , buff); fflush(stdout);
       }
    }

    close(sfd);
    exit(EXIT_FAILURE);
}
