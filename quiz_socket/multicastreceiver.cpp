
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
     int fd, nbytes, addrlen;
     struct ip_mreq mreq;
     char msgbuf[1024];

     u_int yes=1;           

     // make a socket
     if ((fd=socket(AF_INET,SOCK_DGRAM,0)) < 0) {
	  printf("socket error");
	  return 0;
     }


    if (setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes)) < 0) {
       printf("Reusing ADDR failed");
       return 1;
      }

     memset(&addr, 0, sizeof(addr));
     addr.sin_family = AF_INET;
     addr.sin_addr.s_addr = htonl(INADDR_ANY); 
     addr.sin_port=htons(PORT);
     
     
     if (bind(fd,(struct sockaddr *) &addr,sizeof(addr)) < 0) {
	  printf("bind error");
	  return 0;
     }
     
     mreq.imr_multiaddr.s_addr = inet_addr(GROUP);
     mreq.imr_interface.s_addr = htonl(INADDR_ANY);
     if (setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) < 0) {
	  printf("setsockopt error");
	  return 0;
     }

     while (true) {
	  addrlen = sizeof(addr);
	  if ((nbytes=recvfrom(fd, msgbuf, 1024, 0, (struct sockaddr *) &addr,(socklen_t *)&addrlen)) < 0) {
	    printf("recvfrom error");
	       return 0;
	  }
	  printf("%s\n", msgbuf);
     }
     return 0;
}
