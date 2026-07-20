#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the size of the inventory: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the inventory elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x, m;

    printf("Enter the product code to search: ");
    scanf("%d", &x);

    printf("Enter the new quantity/value: ");
    scanf("%d", &m);

    // Linear Search and Update
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            arr[i] = m;
            break;      // Remove break to replace all occurrences
        }
    }

    printf("Updated Inventory:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);
    return 0;
}/*
Enter the size of the inventory: 4
Enter the inventory elements: 10
40
30
40
Enter the product code to search: 40
Enter the new quantity/value: 20
Updated Inventory:
10 20 30 40 */