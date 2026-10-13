#include <stdio.h>

#define MAX 100
#define INF 999999

int main() {
    int n, m;
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX], parent[MAX];
    int i, j;

    // Initialize graph
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            graph[i][j] = -1;
        }
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (u v weight):\n");

    for (i = 0; i < m; i++) {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;   // Undirected graph
    }

    int s, d;

    printf("Enter the source vertex: ");
    scanf("%d", &s);

    printf("Enter the destination vertex: ");
    scanf("%d", &d);

    // Initialize Dijkstra arrays
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    // Distance from source to itself is 0
    dist[s] = 0;

    // Dijkstra's algorithm
    for (i = 0; i < n; i++) {

        int u = -1;

        // Find the unvisited vertex with minimum distance
        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        // No reachable vertex remains
        if (u == -1 || dist[u] == INF)
            break;

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (j = 0; j < n; j++) {
            if (graph[u][j] != -1 && !visited[j]) {

                if (dist[u] + graph[u][j] < dist[j]) {
                    dist[j] = dist[u] + graph[u][j];
                    parent[j] = u;
                }
            }
        }
    }

    // Check if destination is unreachable
    if (dist[d] == INF) {
        printf("No path found");
    }
    else {
        int path[MAX];
        int count = 0;
        int current = d;

        // Store path backwards
        while (current != -1) {
            path[count++] = current;
            current = parent[current];
        }

        printf("Shortest path: ");

        // Print path in correct order
        for (i = count - 1; i >= 0; i--) {
            printf("%d", path[i]);

            if (i != 0)
                printf(" -> ");
        }

        printf("\n");
        printf("Shortest distance: %d", dist[d]);
    }

    return 0;
}
