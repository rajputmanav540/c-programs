#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n) {
   for (int i = 1; i < n; i++) {
      int key = arr[i];
      int j = i - 1;

      while (j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }

      arr[j + 1] = key;
   }
}

void benchmark(int n, int arr[]) {
   clock_t start;
   double elapsed_time;

   start = clock();
   insertion_sort(arr, n);
   elapsed_time = (double)(clock() - start) / CLOCKS_PER_SEC;
   printf("Insertion sort took %f seconds\n", elapsed_time);
}

int main() {
   int arr[] = {10, 20, 30, 40, 50};
   int n = sizeof(arr) / sizeof(arr[0]);

   benchmark(n, arr);

   return 0;
}