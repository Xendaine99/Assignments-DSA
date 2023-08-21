#include <stdio.h>

void inputArray(int *arr, int n) {
    printf("Input the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int countOccurrences(int *arr, int n, int *a) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == *a) {
            c++;
        }
    }
    return c;
}

int main() {
    int n, a, c = 0;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the number: ");
    scanf("%d", &a);

    int arr[n];
    inputArray(arr, n);

    c = countOccurrences(arr, n, &a);

    if (c > 0) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    return 0;
}
