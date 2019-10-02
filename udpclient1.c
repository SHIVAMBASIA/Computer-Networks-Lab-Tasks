#include<netinet/in.h>
#include<netinet/ip.h>
#include<stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int clientsock;
	int status;
	char buf[100],buf1[100];
	struct sockaddr_in cs,ss;
	clientsock=socket(AF_INET,SOCK_DGRAM,0);
	if(clientsock == -1)
	{
	    printf("Not Created");
	    return;
	}
	printf("socket id = %d\n",clientsock);
	cs.sin_family=AF_INET;
	cs.sin_addr.s_addr=inet_addr("127.0.0.1");
	cs.sin_port=6043;
	status = bind(clientsock, (struct sockaddr*)&cs,sizeof(cs));
	if(status == -1)
	{
	    printf("Binding Failure");
	    return;
	}

	    printf("Binding Sucessfull");
	    ss.sin_family=AF_INET;
	    ss.sin_addr.s_addr=inet_addr("127.0.0.1");
	    ss.sin_port=6049;
	    printf("Enter the message\t");
	    gets(buf);
	    sendto(clientsock,buf,strlen(buf),0,(struct sockaddr *)&ss,sizeof(ss));
	    
	    int s=sizeof(ss);
	    printf("Binding Sucessfull");
	    int n = recvfrom(clientsock,buf1,100,0,(struct sockaddr *)&ss,&s);
	    printf("%s",buf1);
	    printf("%d",n);
	
	close(clientsock);
	
	return 0;
}
