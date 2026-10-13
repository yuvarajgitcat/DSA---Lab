#include <stdio.h>

#define MAX 6

int main() {
    int n;
    int G[MAX][MAX];
    int color[MAX];
    int queue[MAX];
    int front = 0, rear = 0;
    int src, i, j;
    int bipartite = 1;

    printf("Enter the number of computers: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Enter the source computer: ");
    scanf("%d", &src);

    // Initialize all vertices as uncolored
    for (i = 0; i < n; i++) {
        color[i] = -1;
    }

    // Start BFS from source
    color[src] = 0;
    queue[rear++] = src;

    while (front < rear && bipartite) {
        int u = queue[front++];

        for (j = 0; j < n; j++) {
            if (G[u][j] == 1) {

                // If vertex is not colored
                if (color[j] == -1) {
                    color[j] = 1 - color[u];
                    queue[rear++] = j;
                }

                // If adjacent vertices have same color
                else if (color[j] == color[u]) {
                    bipartite = 0;
                    break;
                }
            }
        }
    }

    if (bipartite)
        printf("Yes, the given graph is Bipartite");
    else
        printf("No, the given graph is not Bipartite");

    return 0;
}
