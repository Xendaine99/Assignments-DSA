#include<stdio.h>
int main()
{
    int n,m;
    printf("Enter the number of rows and columns");
    scanf("%d %d",&n,&m);
    int arr[n][m];
    printf("Enter the array");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d",arr[i][j]);
        }
    }
    printf("The array has a fixed size");
    return 0;
}