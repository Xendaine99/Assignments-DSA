#include<stdio.h>
int main()
{
    int p=0,ne=0,z=0;
    int n;
    printf("Enter the size of array \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            p++;
        }
        if(arr[i]<0)
        {
            ne++;
        }
        if(arr[i]==0)
        {
            z++;
        }
    }
    printf("Postive=%d\n",p);
    printf("Negative=%d\n",ne);
    printf("Zeroes=%d\n",z);
}
