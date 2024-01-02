#include <stdio.h>
#include <limits.h>

void floydWarshall(int graph[][3], int n) {
    int i, j, k;
    int dp[3][3];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dp[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    printf("Shortest distances are as follows:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dp[i][j] == INT_MAX) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dp[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[][3] = {{0, 3, 6},
                      {3, 0, 4},
                      {6, 4, 0}};
    int n = sizeof(graph) / sizeof(graph[0]);
    floydWarshall(graph, n);
    return 0;
}