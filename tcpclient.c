//TCP programming
#include<stdio.h>
#include<string.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<fcntl.h>

int main()
{
	int clientsock,status;
	char buf[100],buf1[100];
	struct sockaddr_in ss,cs;
	cs.sin_family = AF_INET;
	cs.sin_port =6083;
	cs.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientsock = socket(AF_INET,SOCK_STREAM,0);
	//printf("Socket Id = %d",clientsock);
	if (clientsock == -1)
		return -1;
	printf("Socket Id = %d",clientsock);
	status = bind(clientsock,(struct sockaddr *) &cs, sizeof(cs));
	if (status == -1)
		{
			printf("Binding not successful");
		}

		
	printf("Binding successful"); 
	ss.sin_family =AF_INET;
	ss.sin_addr.s_addr =inet_addr("127.0.0.1");
	ss.sin_port =7000;
	printf("\nEnter the message\n");
	
	gets(buf);
	connect(clientsock,(struct sock_addr *)&ss,sizeof(ss));
	send(clientsock,buf,strlen(buf),0);
	
	
	close(clientsock);
	return 0;
}
