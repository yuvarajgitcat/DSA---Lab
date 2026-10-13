#include <stdio.h>

int n, m;
char a[5][5];

/* 8 directions: N, NE, E, SE, S, SW, W, NW */
int row[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int col[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dfs(int r, int c)
{
    int i, nr, nc;
    int max = 1;

    for (i = 0; i < 8; i++)
    {
        nr = r + row[i];
        nc = c + col[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m)
        {
            if (a[nr][nc] == a[r][c] + 1)
            {
                int length = 1 + dfs(nr, nc);

                if (length > max)
                    max = length;
            }
        }
    }

    return max;
}

int main()
{
    int i, j;
    char ch;
    int answer = 0;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("Enter number of columns: ");
    scanf("%d", &m);

    printf("Enter the characters of the matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf(" %c", &a[i][j]);
        }
    }

    printf("Enter the starting character: ");
    scanf(" %c", &ch);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == ch)
            {
                int length = dfs(i, j);

                if (length > answer)
                    answer = length;
            }
        }
    }

    printf("\nThe length of the longest path with consecutive characters ");
    printf("starting from character %c is %d\n", ch, answer);

    return 0;
}
