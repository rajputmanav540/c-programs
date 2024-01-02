#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[], int n, int x) {
   int left = 0, right = n - 1;

   while (left <= right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] == x) {
         return mid;
      }

      if (arr[mid] < x) {
         left = mid + 1;
      } else {
         right = mid - 1;
      }
   }

   return -1;
}

int linear_search(int arr[], int n, int x) {
   for (int i = 0; i < n; i++) {
      if (arr[i] == x) {
         return i;
      }
   }
   return -1;
}

void benchmark(int n, int arr[], int x) {
   clock_t start;
   double elapsed_time;

   start = clock();
   binary_search(arr, n, x);
   elapsed_time = (double)(clock() - start) / CLOCKS_PER_SEC;
   printf("Binary search took %f seconds\n", elapsed_time);

   start = clock();
   linear_search(arr, n, x);
   elapsed_time = (double)(clock() - start) / CLOCKS_PER_SEC;
   printf("Linear search took %f seconds\n", elapsed_time);
}

int main() {
   int arr[] = {10, 20, 30, 40, 50};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 40;

   benchmark(n, arr, x);

   return 0;
}