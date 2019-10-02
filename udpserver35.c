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
	int status,start=0,end,i,j=0;
	char buf[100],buf1[100],temp;
	struct sockaddr_in ss,cs;
	serversock=socket(AF_INET,SOCK_DGRAM,0);
	if(serversock == -1)
	{
	    printf("Not Created");
	    return;
	}
	printf("socket id = %d\n",serversock);
	ss.sin_family=AF_INET;
	ss.sin_addr.s_addr=inet_addr("10.0.89.180");
	ss.sin_port=6049;
	
	status = bind(serversock, (struct sockaddr*)&ss,sizeof(ss));
	if(status == -1)
	{
	    printf("Binding Failure");
	    return;
	}
	    int s=sizeof(cs);
	    printf("Binding Sucessfull");
	    int n = recvfrom(serversock,buf,100,0,(struct sockaddr *)&cs,&s);
	    printf("%s",buf);
	    printf("%d",n);
	    printf("%s",buf);
	    end=strlen(buf);
	    /*while(start<end)
	    {
	        temp=buf[start];
	        buf[start]=buf[end];
	        buf[end]= temp;
	        start++;
	        end--;
	    }*/
	    for(i=n-1;i>=0;i--)
	    {
	            buf1[j]=buf[i];
	            j++;
	    }
	    printf("\n %s",buf1);
    close(serversock);
	
	return 0;
}
