#include "az_common.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

#define SERVER_IP "192.132.0.197"
#define PORT_NUM  10000
#define PACKET_SIZE 4096
 
int socket_open(int *fd)
{
	int sockfd, no_of_bytes, rval;
	struct sockaddr_in servaddr;

	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd <= 0){
		printf("Socket open error\n");
		return -1;
	}

	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(SERVER_IP);
	servaddr.sin_port=htons(PORT_NUM);
	
	*fd = sockfd;
	
	return 0;
}

int send_to_server(int sockfd, char *sendbuffer, int sendlen){	
	int rval;
	
	rval = sendto(sockfd,sendbuffer,sendlen,0,(struct sockaddr *)&servaddr,sizeof(servaddr));
	if(rval <= 0){
		printf("Send Failed\n");
		return -1;
	}

	return rval;
}


int recv_from_server(int sockfd, char **recvbuffer, int recvlen){
	int rval;
	char *buffer;

	buffer = malloc(MAX_PACKET * sizeof(char));
	if(buffer == NULL){
		printf("Malloc failed\n");
		return -1;
	}
	memset(buffer,0,rval);
	
	rval = recvfrom(sockfd,buffer,PACKET_SIZE,0, NULL, NULL);
	if(rval <= 0){
		printf("Send Failed\n");
		return -1;
	}
	
	recvlen = rval;
	*recvbuffer = buffer;
	return rval;
}

int socket_close(int fd)
{
	close(fd);
	return 0;
}
