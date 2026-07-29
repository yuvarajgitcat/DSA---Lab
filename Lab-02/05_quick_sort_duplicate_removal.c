#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high, int *pass) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    printf("Pivot for pass %d: %d\n", (*pass)++, pivot);

    return i + 1;
}

void quicksort(int a[], int low, int high, int *pass) {
    if (low < high) {
        int p = partition(a, low, high, pass);
        quicksort(a, low, p - 1, pass);
        quicksort(a, p + 1, high, pass);
    }
}

int main() {
    int n, pass = 1;
    scanf("%d", &n);

    int a[50];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1, &pass);

    printf("Final array: ");
    printf("%d ", a[0]);

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1])
            printf("%d ", a[i]);
    }

    return 0;
}