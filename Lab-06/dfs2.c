#include <stdio.h>
#include <string.h>

#define MAX 100

int M, N;
char grid[MAX][MAX];
int visited[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int isValid(int r, int c) {
    return r >= 0 && r < M &&
           c >= 0 && c < N &&
           !visited[r][c];
}

int dfs(int r, int c, char startType) {
    int i;
    int maxLength = 1;

    visited[r][c] = 1;

    for (i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (isValid(nr, nc)) {
            int currentLength;

            /*
             * We can continue the path through any cell.
             * The final cell must have a different type
             * from the starting cell.
             */
            currentLength = dfs(nr, nc, startType) + 1;

            if (currentLength > maxLength)
                maxLength = currentLength;
        }
    }

    visited[r][c] = 0;

    return maxLength;
}

int findLongestPath() {
    int i, j;
    int longest = 0;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            int length;

            memset(visited, 0, sizeof(visited));

            length = dfs(i, j, grid[i][j]);

            if (length > longest)
                longest = length;
        }
    }

    return longest;
}

int main() {
    int i;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &M, &N);

    printf("Enter the grid:\n");
    for (i = 0; i < M; i++) {
        scanf("%s", grid[i]);
    }

    printf("Longest path length: %d\n", findLongestPath());

    return 0;
}
