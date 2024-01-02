#include <stdio.h>
#include<stdlib.h>

// Returns the maximum number of activities that can be selected
int activitySelection(int start[], int finish[], int n) {
   int i, j;
   int* A = (int*)malloc(n * sizeof(int));
   int size = 0;

   // Initialize A[]
   for (i = 0; i < n; i++) {
      A[i] = start[i];
   }

   // Sort the activities according to their finish time in increasing order
   for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
         if (finish[j] < finish[i]) {
            int t = finish[i];
            finish[i] = finish[j];
            finish[j] = t;

            t = start[i];
            start[i] = start[j];
            start[j] = t;
         }
      }
   }

   // Add the first activity to the result
   size = 1;
   A[0] = 1;

   // Traverse through the sorted activities and add activities to the result
   for (i = 1; i < n; i++) {
      if (start[i] >= finish[i - 1]) {
         size++;
         A[i] = size;
      }
   }

   printf("The maximum number of activities that can be selected is %d\n", size);
   printf("The selected activities are:\n");

   for (i = 0; i < n; i++) {
      printf("%d ", A[i]);
   }

   return size;
}

int main() {
   int start[] = {1, 3, 0, 5, 8, 5};
   int finish[] = {2, 4, 6, 7, 9, 9};
   int n = sizeof(start) / sizeof(start[0]);

   activitySelection(start, finish, n);

   return 0;
}