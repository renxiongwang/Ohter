#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
  //Set up the socket and readin
  int listenfd,connfd;
  struct sockaddr_in sockaddr;
  char buff[1024];
  int n;
  memset(&sockaddr, 0, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_addr.s_addr = inet_addr("123.121.10.10");
  sockaddr.sin_port = htons(2020);
  
  // make a scoket
  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  // bind 
  if (bind(listenfd, (struct sockaddr *) &sockaddr, sizeof(sockaddr)) < 0) {
    printf("bind error\n");
    return 0;
  }
  
  // listen
  listen(listenfd, 5);
  
  // accept
  while(true) {
    if((connfd = accept(listenfd, (struct sockaddr*) NULL, NULL)) == -1) {
      printf("accept error\n");
      continue;
    }
    n = recv(connfd, buff, 1024, 0);
    buff[n] = '\0';
    printf("recv msg from client:%s", buff);
    close(connfd);
  }
  close(listenfd);
}
