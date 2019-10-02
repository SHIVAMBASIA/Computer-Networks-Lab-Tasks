#include<stdio.h>
int main()
{
	unsigned int k=0x16ABC138;
	unsigned char *p;
	p=(unsigned char)&k;
	printf("%d",&p);
	
}
