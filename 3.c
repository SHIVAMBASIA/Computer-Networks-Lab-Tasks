//Extract each byte from a given number and print them using separate variables//


#include<stdio.h>
int main()
{
        unsigned int val;
        int i;
        printf("Enter the Value: ");
        scanf("%x", &val);
        unsigned char a[100];
        for(i=0;i<4;i++)
        {
                a[i]=((val>>(i*8))&0xFF);
        }
        for(i=0;i<4;i++)
        {
                printf("a[i] =%02X \n", a[i]);
        }
        return 0;
}
