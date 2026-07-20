#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter the number of transactions: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the sales amounts: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the sales amount to search: ");
    scanf("%d", &x);

    // Linear Search
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            index = i;
            break;
        }
    }

    if (index == -1)
        printf("Sales amount %d is not present\n", x);
    else
        printf("Sales amount %d is present at index %d\n", x, index);

    // Find largest and second largest
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {

        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN)
        printf("Second largest element does not exist\n");
    else
        printf("Second largest sales amount: %d\n", secondLargest);

    free(arr);
    return 0;
}/*
Enter the number of transactions: 5
Enter the sales amounts: 45
12
78
6
40
Enter the sales amount to search: 6
Sales amount 6 is present at index 3
Second largest sales amount: 45*/