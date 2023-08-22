#include<stdio.h>
int main()
{
    int n,a,pos=0;
    printf("Enter the size of the array");
    scanf("%d",&n);
    printf("Enter the element to be deleted" );
    scanf("%d",&a);
    int arr[n];
    printf("Enter the elements of the array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    // printf("Enter the position you want the element to be inserted");
    // scanf("%d",&pos);
    for(int i=0;i<=n;i++)
    {
        if(arr[i]==a)
        {
            pos=i;
        }
    }
    for(int i=pos;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    for(int i=0;i<n-1;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}