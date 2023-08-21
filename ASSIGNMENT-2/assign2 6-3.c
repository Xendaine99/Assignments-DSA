#include <stdio.h>

void insertElement(int *arr, int *n, int *a, int *pos) {
    for (int i = (*n); i >= (*pos); i--) {
        arr[i + 1] = arr[i];
    }
    arr[*pos] = *a;
    (*n)++;
}

int main() {
    int n, a, pos;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the element to be inserted: ");
    scanf("%d", &a);

    int arr[n + 1];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position at which you want the element to be inserted: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position.\n");
        return 1;
    }

    for (int i = n; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = a;
    n++;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
