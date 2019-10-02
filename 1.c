//Swap through command line using function and pointer//


#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int *c;
	c=a;
	a=b;
	b=c;
	
	printf("%d %d",*a,*b);
}
int main(int argc, char *argv[])
{
	int a,b;
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	swap(&a,&b);
	return 0;
}

