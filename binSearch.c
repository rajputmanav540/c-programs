#include <stdio.h>

int binarySearch(int arr[], int L, int R, int x) {
    if (R >= L) {
        int mid = L + (R - L) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearch(arr, L, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, R, x);
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {1, 3, 5, 10, 15, 16, 21, 33, 563};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    for (int i = 0; i < 10; i++) {
        printf("Enter an element from the array: ");
        scanf("%d", &x);

        int result = binarySearch(arr, 0, n - 1, x);

        if (result == -1) {
            printf("Element not found!!!\n");
        } else {
            printf("Element is present at index %d\n", result);
        }
    }

    return 0;
}
