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
	int serversock;
	int status,connectstatus;
	char buf[100],buf1[100];
	struct sockaddr_in ss,cs;
	serversock=socket(AF_INET,SOCK_STREAM,0);
	if(serversock == -1)
	{
	    printf("Not Created");
	    return;
	}
	printf("socket id = %d\n",serversock);
	ss.sin_family=AF_INET;
	ss.sin_addr.s_addr=inet_addr("127.0.0.1");
	ss.sin_port=6049;
	
	status = bind(serversock, (struct sockaddr*)&ss,sizeof(ss));
	if(status == -1)
	{
	    printf("Binding Failure");
	    return;
	}
	    printf("Binding Sucessfull");
	    listen(serversock,3);
	    while(1)
	    {
	    int s=sizeof(cs);
	    int fd1=accept(serversock,(struct sockaddr *)&cs,&s);
	    recv(fd1,buf,100,0);
	    printf("%s",buf);
	    cs.sin_family=AF_INET;
	    cs.sin_addr.s_addr=inet_addr("127.0.0.1");
	    cs.sin_port=6043;
	    connectstatus=connect(serversock,(struct sockaddr *)&ss,sizeof(ss));
	    if (connectstatus< 0)
 {
 printf("connect failed. Error");
 }
	    printf("Enter the message\t");
	    gets(buf1);
	    send(serversock,buf,strlen(buf1),0);	
	    if(strcmp("Bye",buf)==0||strcmp("Bye",buf1)==0)
	    {
	    break;
	    }
	    //buf="\0";
	    //buf1="\0";
	    }
	    
	close(serversock);
	
	return 0;
}
