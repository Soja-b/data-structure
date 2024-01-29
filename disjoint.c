#include <stdio.h>
#include <stdlib.h>

int* parent;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

int main() {
    int n, m;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    parent = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    printf("Enter the number of unions: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        printf("Enter two elements to union: ");
        scanf("%d %d", &x, &y);
        unionSet(x, y);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", find(i));
    }
    free(parent);
    return 0;
}