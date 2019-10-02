/**	WAP to extract the first and last byte of an unsigned integer,input with keyboard. If first and last byte are same ,
	then it will ask the user to enter an integer again.This process will continue until both bytes are same. If both 
	are not the same then it will print the message as "Succeded with 2 attempts" where 2 is the number of entering the
	unsigned number through keyboard **/



#include<stdio.h>
int main()
{
        unsigned int val;
        int i,c=1,b=0;
        unsigned char a[100];
        while(c=1)
        {
        printf("Enter the Value: ");
        scanf("%x", &val);
        for(i=0;i<4;i++)
        {
                a[i]=((val>>(i*8))&0xFF);
        }
         for(i=0;i<4;i++)
        {
                printf("a[%d] =%02X \n", i, a[i]);
        }
        if(a[3]==a[0])
        {
                printf("Enter the no. again");
                b=b+1;
                c=1;
                printf("Enter the Value: ");
                scanf("%x", &val);
                for(i=0;i<4;i++)
                {
                        a[i]=((val>>(i*8))&0xFF);
                }
                 for(i=0;i<4;i++)
                        {
                printf("a[%d] =%02X \n", i, a[i]);
                }
                break;
        }
        else
        {       
                c=0;
                printf("Succeded in %d attempts", b);
        }
        }
        
        return 0;
}
