#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int S[], int n, int d) {
    if (n == 0 && d == 0) {
        return true;
    }
    if (n == 0 && d != 0) {
        return false;
    }

    if (S[n - 1] > d) {
        return isSubsetSum(S, n - 1, d);
    }

    return isSubsetSum(S, n - 1, d) || isSubsetSum(S, n - 1, d - S[n - 1]);
}

int main() {
    int S[] = {1, 2, 5, 6, 8};
    int n = sizeof(S) / sizeof(S[0]);
    int d = 9;

    if (isSubsetSum(S, n, d)) {
        printf("Solution exists.\n");
    } else {
        printf("Solution does not exist.\n");
    }
    return 0;
}