/** WAP to extract each byte as character from the representation of multibyte data types on your machine 
	and store and display the extracted bytes. **/


#include<stdio.h>
struct endian
{
	char ch1;
	char ch2[2];
	char ch3;
};
int main()
{
	unsigned int value;
	scanf("%x",&value);
	unsigned char a,b,c,d;
	struct endian e;
	e.ch1=(value&0xFF);
	e.ch2[0]=((value>>8)&0xFF);
	e.ch2[1]=((value>>16)&0xFF);	
	e.ch3=((value>>24)&0xFF);
	
	printf("a%02x",e.ch1);
	/*if(*cx==a)
		printf("Little Endian");	
	else
		printf("Big Endian");
	return 0;*/
}
