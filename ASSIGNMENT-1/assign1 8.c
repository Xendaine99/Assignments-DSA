#include<stdio.h>
void swap(int *,int *);
int main()
{
    int a,b;
    printf("Enter the two numbers");
    scanf("%d %d",&a,&b);
    printf("Before:%d %d",a,b);
    swap(&a,&b);
    printf("After:%d %d",a,b);
}

void swap(int *ad,int *bd)
{
    int temp=0;
    temp=*ad;
    *ad=*bd;
    *bd=temp;
}