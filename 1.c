#include <stdio.h>
#include <stdlib.h>

int linear_search(int arr[], int n, int x) {
   for (int i = 0; i < n; i++) {
      if (arr[i] == x) {
         return i;
      }
   }
   return -1;
}

int main() {
   int arr[] = {10, 20, 30, 40, 50};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 40;

   int result = linear_search(arr, n, x);
   if (result != -1) {
      printf("Element is present at index %d", result);
   } else {
      printf("Element is not present in the array");
   }

   return 0;
}