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
	char buf[100],buf1[100];
	struct sockaddr_in ss,cs;
	serversock=socket(AF_INET,SOCK_DGRAM,0);
	if(serversock == -1)
	{
	    printf("Not Created");
	    return;
	}
	printf("socket id = %d\n",serversock);
	ss.sin_family=AF_INET;
	ss.sin_addr.s_addr=inet_addr("10.0.88.69");
	ss.sin_port=6049;
	
	status = bind(serversock, (struct sockaddr*)&ss,sizeof(ss));
	if(status == -1)
	{
	    printf("Binding Failure");
	    return;
	}
	
	    printf("Binding Sucessfull");
	    while(1)
	    {
	    int s=sizeof(cs);
	    int n = recvfrom(serversock,buf,100,0,(struct sockaddr *)&cs,&s);
	    printf("%s",buf);
	    printf("%d",n);
	    
	    cs.sin_family=AF_INET;
	    cs.sin_addr.s_addr=inet_addr("10.0.89.235");
	    cs.sin_port=6043;
	    printf("Enter the message\t");
	    gets(buf1);
	    sendto(serversock,buf1,strlen(buf1),0,(struct sockaddr *)&cs,sizeof(cs));
	    if(strcmp("Bye",buf)==0||strcmp("Bye",buf1)==0)
	    {
	    break;
	    }
	    }
	
	close(serversock);
	
	return 0;
}
