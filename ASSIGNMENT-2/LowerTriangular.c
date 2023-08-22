#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elemnts of the array");
    for(int i=0;i<n;i++)
    {
       scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=j)
            {
                printf("%d ",arr[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}