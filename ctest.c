#include<stdio.h>
int main(int argc,char *argv[])
{
    FILE *fp1,*fp2;
    char ch;
    fp1=fopen(argv[1],"r");
    if(fp1==NULL)
    {
        printf("error: cannot open file");
        exit(0);
    }

    ch=getc(fp1);

    while(ch!=EOF)
    {
        putchar(ch);
        ch=getc(fp1);
    }
    return 0;
}