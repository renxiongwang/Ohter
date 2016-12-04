#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <stdio.h>


#define PORT 24000
#define GROUP "221.121.10.10"

int main() {
     struct sockaddr_in addr;
     int fd, cnt;
     struct ip_mreq mreq;
     char *message="Welcome to my Group";

     //make a socket
     if ((fd=socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
	  printf("socket error");
	  return 0;
     }

     // setup destination address 
     memset(&addr, 0, sizeof(addr));
     addr.sin_family = AF_INET;
     addr.sin_addr.s_addr = inet_addr(GROUP);
     addr.sin_port = htons(PORT);
     
     // send the message
     while (true) {
       if (sendto(fd, message, sizeof(message), 0, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
	       printf("send error");
	       return 0;
	  }
     }
     return 0;
}

