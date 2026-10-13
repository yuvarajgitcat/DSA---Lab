#include <stdio.h>

#define MAX 10
#define INF 9999

void dijkstra(int graph[MAX][MAX], int n, int source)
{
    int distance[MAX], visited[MAX];

    /* Initialize distances and visited array */
    for (int i = 0; i < n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }
    distance[source] = 0;
    visited[source] = 1;

    for (int count = 1; count < n; count++) {
        int min = INF;
        int next = -1;

        /* Find the unvisited vertex with minimum distance */
        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                next = i;
            }
        }

        if (next == -1)     /* remaining vertices are unreachable */
            break;

        visited[next] = 1;

        /* Update distances of adjacent vertices */
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[next][i] != INF &&
                distance[next] + graph[next][i] < distance[i])
                distance[i] = distance[next] + graph[next][i];
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);
    for (int i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("Vertex %d = unreachable\n", i);
        else
            printf("Vertex %d = %d\n", i, distance[i]);
    }
}

int main(void)
{
    int graph[MAX][MAX];
    int n, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Number of vertices must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter the adjacency matrix:\n");
    printf("(Enter %d if there is no edge)\n", INF);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Source must be between 0 and %d.\n", n - 1);
        return 1;
    }

    dijkstra(graph, n, source);
    return 0;
}
