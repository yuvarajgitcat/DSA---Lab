#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the number of luggage: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the luggage weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("Heaviest piece weight: %d\n", max);
    printf("Lightest piece weight: %d\n", min);
    printf("Weight difference: %d\n", max - min);

    free(arr);
    return 0;
}/*
Enter the number of luggage: 4
Enter the luggage weights: 4
2
3
5
Heaviest piece weight: 5
Lightest piece weight: 2
Weight difference: 3*/