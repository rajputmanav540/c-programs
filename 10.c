#include <stdio.h>
#include <limits.h>

typedef struct Item {
    int weight;
    int value;
} Item;

typedef struct Node {
    int level;
    int profit;
    int weight;
} Node;

int bound(Node* u, int W, Item items[], int n) {
    int total = 0;
    for (int i = u->level; i < n; i++) {
        if (u->weight + items[i].weight <= W) {
            total += items[i].value;
        } else {
            total += (W - u->weight) * items[i].value / items[i].weight;
            break;
        }
    }
    return total;
}

int knapSack(Item items[], int n, int W) {
    int profit = 0;
    Node t1, t2;
    int ub = INT_MAX;
    t1.level = t2.level = 0;

    while (t1.level != n && ub > 0) {
        if (t1.profit + items[t1.level].value > t2.profit + (W - t2.weight) * items[t1.level].value / items[t1.level].weight) {
            t2.level = t1.level;
            t2.profit = t1.profit + items[t1.level].value;
            t2.weight = t1.weight + items[t1.level].weight;
        } else {
            t2.level = t1.level + 1;
            t2.profit = t1.profit + (W - t1.weight) * items[t1.level].value / items[t1.level].weight;
            t2.weight = W;
        }
        if (t2.weight <= W) {
            profit = t2.profit;
        }
        ub = bound(&t1, W, items, n) - profit;
        if (ub > 0) {
            t1.level = t2.level;
            t1.profit = t2.profit;
            t1.weight = t2.weight;
        }
    }
    return profit;
}

int main() {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    int W = 50;

    printf("Maximum profit is %d\n", knapSack(items, n, W));
    return 0;
}