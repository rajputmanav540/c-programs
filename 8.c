#include <stdio.h>
#include <string.h>

void countSort(int array[], int n) {
    int output[n];
    int max = array[0];

    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int count[max + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

int main() {
    int array[] = {1, 4, 1, 2, 7, 5, 2};
    int n = sizeof(array) / sizeof(array[0]);

    countSort(array, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}