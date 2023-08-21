#include<stdio.h>
int main()
{
    int a=-1,b=1,c=0;
    for(int i=1;i<=10;i++)
    {
        c=a+b;
        a=b;
        b=c;
        printf("%d\n",c);
    }
    return 0;
}