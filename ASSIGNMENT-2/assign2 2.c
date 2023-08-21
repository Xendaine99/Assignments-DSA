#include <stdio.h>

void findSecondMinMax(int arr[], int size, int *secondMin, int *secondMax) {
    int min, max;

    if (size < 2) {
        printf("Array size should be at least 2.\n");
        return;
    }

    if (arr[0] > arr[1]) {
        max = arr[0];
        min = arr[1];
    } else {
        max = arr[1];
        min = arr[0];
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            *secondMax = max;
            max = arr[i];
        } else if (arr[i] > *secondMax && arr[i] != max) {
            *secondMax = arr[i];
        }

        if (arr[i] < min) {
            *secondMin = min;
            min = arr[i];
        } else if (arr[i] < *secondMin && arr[i] != min) {
            *secondMin = arr[i];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Array size should be a positive integer.\n");
        return 1;
    }

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int secondMin, secondMax;
    findSecondMinMax(arr, size, &secondMin, &secondMax);
    printf("Second Minimum: %d\n", secondMin);
    printf("Second Maximum: %d\n", secondMax);

    return 0;
}
