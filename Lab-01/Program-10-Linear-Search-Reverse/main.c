#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the data points: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the data point to search: ");
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
        printf("Data point isn't present in the dataset\n");
    else
        printf("Data point is present in the dataset at position %d\n", index);

    // Reverse the array (in-place)
    int left = 0, right = n - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    // Print reversed array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}/*
Enter the number of data points: 4
Enter the data points: 45
56
25
36
Enter the data point to search: 25
Data point is present in the dataset at position 2
36 25 56 45 */