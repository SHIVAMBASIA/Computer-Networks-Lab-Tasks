#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prevsav= 0;
struct society
{
	char members[100][40];
	int paid[100];
	int flat[100];
	int type[100];
};

struct exp
{
	int contact[100];
	int amount[100];
	int billno[100];
	char desc[100][30];
	char date[100][20];
};

void balsheet(struct society s ,struct exp e, int n,int m)
{
	int i,collected=0,expend =0,savings;
	for(i=0;i<n;i++)
	{
		collected += s.paid[i];
	}
	for(i=0;i<m;i++)
	{
		expend += e.amount[i];
	}
	
	savings = collected - expend;
	printf("Total amount collected =%d\n",collected);
	printf("Total expenditure =%d\n",expend);
	printf("Total savings of the society =%d\n",savings);
	prevsav += savings;
}

int main()
{
	int i,n,m;
	struct society s;
	struct exp e;
	printf("Enter No of members\n");
	scanf("%d",&n);
	
	//s.members[0]="qqqqq";
	
	for (i=0;i<n;i++)
	{
		char a[50];
		printf("Enter the member's name\n");
		scanf("%s",a);
		strcpy(s.members[i],a);
		printf("Enter amount paid, flat_no , flat_type\n");
		scanf("%d%d%d",&s.paid[i],&s.flat[i],&s.type[i]);
	}
	
	printf("Enter No of bills\n");
	scanf("%d",&m);
	
	for (i=0;i<m;i++)
	{
		char b[50],c[50];
		printf("Enter contact, bill amount , bill number, description and date\n");
		scanf("%d%d%d",&e.contact[i],&e.amount[i],&e.billno[i]);
		scanf("%s",b);
		strcpy(e.desc[i],b);
		scanf("%s",c);
		strcpy(e.date[i],c);
		
	}
	
	balsheet(s,e,n,m);
	int choice=1,x;
	while(choice!=0)
	{
	printf("Do you want new member?(0/1)");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1 : 
			
			printf("How many members do you want?");
			scanf("%d",&x);
			for(i =n; i<(n+x);i++)
			{
				char a[50];
				printf("Enter the member's name\n");
				scanf("%s",a);
				strcpy(s.members[i],a);
				printf("Enter amount paid, flat_no , flat_type\n");
				scanf("%d%d%d",&s.paid[i],&s.flat[i],&s.type[i]);
			}
			n= n+x;
			balsheet(s,e,n,m);
			break;
		case 0:
			exit(1);
	}
	}
		
			
			
	
	
	
	//printf("%s  %d  %d  %d ",s.members[0],s.paid[0],s.flat[0],s.type[0]);
	//printf("%d  %d  %d  %s %s ",e.contact[0],e.amount[0],e.billno[0],e.desc[0],e.date[0]);
	//printf("%s",s.members[0]);
	
	
	return 0;
	
}	


	
	
