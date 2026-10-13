#include <stdio.h>

#define MAX 10

struct Edge {
    int u;
    int v;
    int w;
};

int parent[MAX];

int find(int x) {
    if (parent[x] == x)
        return x;

    return find(parent[x]);
}

void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    parent[rootA] = rootB;
}

int main() {
    int N, M;
    struct Edge edges[MAX * MAX];

    int i, j;
    int count = 0;
    int totalCost = 0;

    printf("Enter the number of cities: ");
    scanf("%d", &N);

    printf("Enter the number of track segments: ");
    scanf("%d", &M);

    printf("Enter the track segments (source destination cost):\n");

    for (i = 0; i < M; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    // Initialize each city as its own set
    for (i = 0; i < N; i++) {
        parent[i] = i;
    }

    // Sort edges by weight
    for (i = 0; i < M - 1; i++) {
        for (j = 0; j < M - i - 1; j++) {

            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Kruskal's Algorithm
    for (i = 0; i < M; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        // Check whether adding this edge creates a cycle
        if (find(u) != find(v)) {

            unionSet(u, v);

            totalCost += edges[i].w;
            count++;

            // MST needs N-1 edges
            if (count == N - 1)
                break;
        }
    }

    // Check whether all cities are connected
    if (count == N - 1) {
        printf("%d", totalCost);
    }
    else {
        printf("It is not possible to connect all cities.");
    }

    return 0;
}
