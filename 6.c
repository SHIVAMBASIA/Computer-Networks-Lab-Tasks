/** WAP to find out if the underlying architecture/machine is little endian or big endian **/


#include<stdio.h>
int main()
{
	unsigned int value;
	scanf("%x",&value);
	unsigned char a,b,c,d;
	
	a=(value&0xFF);
	b=((value>>8)&0xFF);
	c=((value>>16)&0xFF);	
	d=((value>>24)&0xFF);
	
	char *cx=(char*)&a;
	if(*cx==a)
		printf("Little Endian");	
	else
		printf("Big Endian");
	return 0;
}
