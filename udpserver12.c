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
	int status;
	char buf[100],buf1[100],x[]="1";
	struct sockaddr_in ss,cs;
	serversock=socket(AF_INET,SOCK_DGRAM,0);
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
	    int s=sizeof(cs);
	    printf("Binding Sucessfull");
	    while(1)//strcmp("1",x)==0)
	    {
	    int n = recvfrom(serversock,buf,100,0,(struct sockaddr *)&cs,&s);
	    buf[n]='\0';
	    printf("Received: %s\n",buf);
	    //printf("%d",n);
	   
	    printf("Enter the message\n");
	    gets(buf1);
	    sendto(serversock,buf1,strlen(buf1),0,(struct sockaddr *)&cs,sizeof(cs));
	    
	    //recvfrom(serversock,x,100,0,(struct sockaddr *)&cs,&s);
	    }
	    
	
	close(serversock);
	
	return 0;
}
