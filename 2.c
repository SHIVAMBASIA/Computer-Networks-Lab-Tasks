//Extract first and last byte of an unsigned integer//


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	unsigned int value;
	scanf("%x",&value);
	unsigned char a,d;
	
		
	a=(value&0xFF);
	d=((value>>24)&0xFF);
	printf("a=%02X\n",a);
	printf("d=%02X\n",d);
	return 0;
}
