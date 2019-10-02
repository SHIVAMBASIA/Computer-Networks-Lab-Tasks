#include<stdio.h>
#include<sys/types.h>          
#include<sys/socket.h>
//#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>
#include<unistd.h>
int main()
{
int clientsock;
char buf[100];
struct sockaddr_in sa;
clientsock=socket(AF_INET,SOCK_DGRAM,0);
printf("Socket Id=%d\n",clientsock);
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=6041;
printf("Enter the message\t");
gets(buf);
sendto(clientsock,buf,strlen(buf),0,(struct sockaddr *)&sa,sizeof(sa));
close(clientsock);
return 0;
}


