#include<stdio.h>
int main()
{
    int x,y;
    printf("Enter the values of x and y");
    scanf("%d %d",&x,&y);
    for(int i=x;i<=y;i++)
    {
        for(int j=1;j<=10;j++)
        {
            printf("%d * %d = %d\n",i,j,(i*j));
        }
    }
    return 0;
}