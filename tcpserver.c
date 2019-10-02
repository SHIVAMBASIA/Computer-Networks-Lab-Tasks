//TCP programming(server)
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
	int serversock,status,fd1;
	char buf[100];
	struct sockaddr_in ss,cs;
	serversock = socket(AF_INET,SOCK_STREAM,0);
	printf("Socket Id = %d",serversock);
	if (serversock == -1)
		{
		printf("Not created");
		return -1;
		}
	
	ss.sin_family =AF_INET;
	ss.sin_addr.s_addr =inet_addr("127.0.0.1");
	ss.sin_port =7000;
	
	status = bind(serversock,(struct sockaddr *)&ss, sizeof(ss));
	if (status == -1)
		{
			printf("Binding not successful");
			return 0;
		}
	int s =sizeof(cs);
	printf("\nBinding successful\n"); 
	listen(serversock,5);
	fd1=accept(serversock,(struct sockaddr *)&cs,&s);
	recv(fd1,buf,100,0);
	printf("%s",buf);	
	
	close(serversock);
	return 0;
}
