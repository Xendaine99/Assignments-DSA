#include <stdio.h>
 
int main(void)
{
    int i, n, j, k,temp=0;
    printf("Enter the size of the first array: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter the elements of the first array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of the second array: ");
    scanf("%d", &k);
    int arr2[k];
    printf("Enter the elements of the second array: \n");
    for (j = 0; j < k; j++)
    {
        scanf("%d", &arr2[j]);
    }
    for(int d=0;d<n;d++)
    {
        for(int e=d+1;e<n;e++)
        {
            if(arr1[d]>arr1[e])
            {
                temp=arr1[d];
                arr1[d]=arr1[e];
                arr1[e]=temp;
            }
        }
    }
    for(int d=0;d<n;d++)
    {
        for(int e=d+1;e<n;e++)
        {
            if(arr2[d]>arr2[e])
            {
                temp=arr2[d];
                arr2[d]=arr2[e];
                arr2[e]=temp;
            }
        }
    }
    int arr3[n + k];
    i = j = 0;
    int in;
    for (in = 0; in < n + k; in ++)
    {
        if (i < n && j < k)
        {
            if (arr1[i] < arr2[j])
            {
                arr3[in] = arr1[i];
                i++;
            }
            else
            {
                arr3[in] = arr2[j];
                j++;
            }
        }
        else if (i < n)
        {
            arr3[in] = arr1[i];
            i++;
        }
        else
        {
            arr3[in] = arr2[j];
            j++;
        }
    }
    printf("The merged array is: \n");
    for (in = 0; in < n + k; in++)
    {
        printf("%d ", arr3[in]);
    }
    printf("\n");
    return 0;
}