#include<stdio.h>
int main()
{
    int n,rev=0,num;
    printf("Enter the number");
    scanf("%d",&n);
    num=n;
    while(num!=0)
    {
        rev=rev*10+num%10;
        num=num/10;
    }
    if(rev==n)
    {
        printf("Pallindrome");
    }
    else
    printf("Not Pallindrome");
}