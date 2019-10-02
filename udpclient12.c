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
	int status,x;
	char buf[100],buf1[100],result[2];
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
	    //printf("\nDo you Want to send a message? Press 1 if Yes ,0 to Quit\n");
	    //scanf("%d",&x);
	     int s=sizeof(ss);
	    while(1)
	    {
	    printf("Enter the message\n");
	    gets(buf);
	    sendto(clientsock,buf,strlen(buf),0,(struct sockaddr *)&ss,sizeof(ss));
	    
	   
	   // printf("Binding Sucessfull");
	    int n = recvfrom(clientsock,buf1,100,0,(struct sockaddr *)&ss,&s);
	    buf1[n]='\0';
	    printf("Received: %s\n",buf1);
	    //printf("%d",n);
	    
	   // printf("\nDo you Want to send another message? Press 1 if Yes ,0 to Quit\n");
	    //scanf("%d",&x);
	    
	    //sprintf(result, "%d", x);
	    //sendto(clientsock,result,strlen(result),0,(struct sockaddr *)&ss,sizeof(ss));
	    }
	
	close(clientsock);
	
	return 0;
}
