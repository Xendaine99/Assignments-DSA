//QUESTION-3

#include<stdio.h>
int main()
{
    int n,a,pos;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the element to be inserted\n");
    scanf("%d",&a);
    int arr[n+1];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the position at which you want the element to be inserted\n");
    scanf("%d",&pos);
    for(int i=n;i>=pos;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=a;
    for(int i=0;i<=n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
