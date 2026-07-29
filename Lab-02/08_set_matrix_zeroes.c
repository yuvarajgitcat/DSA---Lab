#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int a[8][8];
    int row[8] = {0}, col[8] = {0};

    // Read matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Set rows and columns to zero
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (row[i] || col[j])
                a[i][j] = 0;
        }
    }

    // Print matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}