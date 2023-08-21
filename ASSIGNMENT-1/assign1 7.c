#include<stdio.h>
int main()
{
    int n,f=1;
    printf("Enter the number");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        f=f*i;
    }
    printf("%d",f);
    return 0;
}