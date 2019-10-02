#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>

int main(int argc,char **argv)
{
	int clen,slen,n,sockfd,clientfd[15];
	char buff[256],fname[256];
	struct sockaddr_in server,client;
	int i=0;
	
	if(argc<2)
	{
		printf("Please enter IP address and port number.\n");
		return;
	}
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("Socket could not be created\n");
	}
	clen=sizeof(client);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(atoi(argv[1]));
	if(bind(sockfd,(struct sockaddr*)&server,sizeof(server))<0)
	{
		printf("Binding failed\n");
	}
	listen(sockfd,5);
	int maxfd=sockfd+1;
	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(sockfd,&readfds);
	while(1)
	{
		int s=select(maxfd,&readfds,NULL,NULL,NULL);
		if(FD_ISSET(sockfd,&readfds)
		{
			clientfd[i]=accept(sockfd,(struct sockaddr*)&client,&clen);
			FDSET(clientfd[i],&readfds);
			if(clientfd[i]>=maxfd)
				maxfd=clientfd[i];
			i++;
		}
		for(int j=0;j<i;j++)
		{
			if(FD_ISSET(clientfd[j],&readfds)
			{
				int r=recv(clientfd[j],fname,256,0);)
				if(r==0)
				{
					close(clientfd[j]);
					FD_CLR(clientfd[j],&readfds);
				}
				else
				{
					fname[n]='\0';
					printf("\nFile name is:%s",fname);
					FILE *fp=fopen(fname,"r");
					if(fp==NULL)
					{
						strcpy(buff,"File not found");
					}
					else
					{
						fread(buff,1,sizeof(buff),fp);
					}
					send(newsockfd,buff,256,0);
				}
			}
		}
	}
	return 0;
