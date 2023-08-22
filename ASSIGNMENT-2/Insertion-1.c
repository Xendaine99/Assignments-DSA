#include<stdio.h>
int main()
{
    int n,a,pos=0;
    printf("Enter the size of the array");
    scanf("%d",&n);
    printf("Enter the element to be inserted" );
    scanf("%d",&a);
    int arr[n+1];
    printf("Enter the elements of the array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the position you want the element to be inserted");
    scanf("%d",&pos);
    for(int i=n;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=a;
    for(int i=0;i<n+1;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}