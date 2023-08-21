#include<stdio.h>
int main()
{
    int n,a,c=0;
    printf("Enter the size of array");
    scanf("%d",&n);
    printf("Enter the number");
    scanf("%d",&a);
    int arr[n];
    printf("Input the array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==a)
        {
            c++;
        }
    }
    if(c>0)
    {
        printf("Found");
    }
    else
        printf("Not found");
}