#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the number of part IDs: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the part IDs: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int approved = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            approved = 0;
            break;
        }
    }

    if (approved)
        printf("All parts in the batch are approved.\n");
    else
        printf("The batch is not approved.\n");

    free(arr);
    return 0;
}/*
Enter the number of part IDs: 3
Enter the part IDs: 12
14
15
The batch is not approved.*/