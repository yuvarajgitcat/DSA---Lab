#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    int a[20][20];
    int index[20] = {0};

    // Read the k x k matrix
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            scanf("%d", &a[i][j]);

    printf("Merged and Sorted Array: ");

    // Merge k sorted arrays
    for (int count = 0; count < k * k; count++) {
        int min = 101, row = -1;

        for (int i = 0; i < k; i++) {
            if (index[i] < k && a[i][index[i]] < min) {
                min = a[i][index[i]];
                row = i;
            }
        }

        printf("%d ", min);
        index[row]++;
    }

    return 0;
}