#include<stdio.h>
int main()
{
    int n;
    char ch;
    printf("Enter the size of the arrays");
    scanf("%d",&n);
    int arr[n];
    int brr[n];
    printf("Enter the elements of the first array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the elements of the second array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&brr[i]);
    }
    printf("Enter the operation you want to perform");
    scanf(" %c",&ch);
    switch (ch)
    {
    case '+':
    for(int i=0;i<n;i++)
    {
        printf("%d\n",(arr[i]+brr[i]));
    }
        break;

    case '-':
    for(int i=0;i<n;i++)
    {
        printf("%d\n",(arr[i]-brr[i]));
    }
        break;

    case '*':
    for(int i=0;i<n;i++)
    {
        printf("%d\n",(arr[i]*brr[i]));
    }
        break;
    
    default:
    printf("INVALID CHOICE");
        break;
    }
    return 0;
}