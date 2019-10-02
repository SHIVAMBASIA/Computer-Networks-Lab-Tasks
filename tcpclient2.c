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
	int status,connectstatus;
	char buf[100],buf1[100];
	struct sockaddr_in cs,ss;
	clientsock=socket(AF_INET,SOCK_STREAM,0);
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
	    while(1)
	    {
	    ss.sin_family=AF_INET;
	    ss.sin_addr.s_addr=inet_addr("127.0.0.1");
	    ss.sin_port=6049;
	    connectstatus=connect(clientsock,(struct sockaddr *)&ss,sizeof(ss));
	    if (connectstatus< 0)
 {
 printf("connect failed. Error");
 }
	    printf("Enter the message\t");
	    gets(buf);
	    send(clientsock,buf,strlen(buf),0);	
	    int s=sizeof(cs);
	    int fd1=accept(clientsock,(struct sockaddr *)&cs,&s);
	    recv(fd1,buf1,100,0);
	    printf("%s",buf1);
	    }
	    
        close(clientsock);
	
	return 0;
}
