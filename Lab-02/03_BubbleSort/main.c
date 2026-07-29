#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[20];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((a[j] % 2 != 0) && (a[j + 1] % 2 == 0)) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}