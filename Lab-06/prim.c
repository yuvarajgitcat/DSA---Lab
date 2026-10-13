#include <stdio.h>

#define MAX 10
#define INF 9999

int main() {
    int V;
    int graph[MAX][MAX];
    int selected[MAX];
    int i, j;
    int edges = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the weighted adjacency matrix:\n");

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initially, no vertex is selected
    for (i = 0; i < V; i++) {
        selected[i] = 0;
    }

    // Start from vertex 0
    selected[0] = 1;

    printf("Edge   Weight\n");

    while (edges < V - 1) {
        int min = INF;
        int x = -1;
        int y = -1;

        // Find the minimum weight edge
        // connecting selected and unselected vertices
        for (i = 0; i < V; i++) {
            if (selected[i]) {
                for (j = 0; j < V; j++) {
                    if (!selected[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min) {

                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        // If no edge is found, graph is disconnected
        if (x == -1 || y == -1) {
            break;
        }

        printf("%d - %d    %d\n", x, y, min);

        selected[y] = 1;
        edges++;
    }

    return 0;
}
