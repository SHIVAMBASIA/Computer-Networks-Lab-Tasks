#include<stdio.h>
int main()
{
	unsigned int num = 0x12345678;
	unsigned int c0,c1,c2,c3,c4,c5,c6,c7;
	c0 = (num & 0xF)<<24;
	c1 = (num & 0xF0)<<16;
	c2 = (num & 0xF00)>>4
	//c2 = c0 | c1;
	printf ("%d\n",c2);
	
}
