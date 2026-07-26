#include <stdio.h>

void insertionSortAscending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int *odd= malloc(((n + 1) / 2) * sizeof(int));
    int *even =malloc((n / 2) * sizeof(int));

    int oi = 0, ei = 0;

    // Separate odd and even positions
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            odd[oi++] = arr[i];
        else
            even[ei++] = arr[i];
    }

    insertionSortDescending(odd, oi);
    insertionSortAscending(even, ei);

    oi = 0;
    ei = 0;

    // Merge back
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            arr[i] = odd[oi++];
        else
            arr[i] = even[ei++];
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}