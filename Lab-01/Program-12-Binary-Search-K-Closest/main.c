#include <stdio.h>
#include <stdlib.h>

// Function to find the crossover point
// Crossover point = largest element <= x
int findCrossOver(int arr[], int low, int high, int x) {

    // If every element is <= x
    if (arr[high] <= x)
        return high;

    // If every element is > x
    if (arr[low] > x)
        return low;

    // Binary Search
    while (low <= high) {

        int mid = (low + high) / 2;

        // Found crossover point
        if (arr[mid] <= x && arr[mid + 1] > x)
            return mid;

        // Move right
        if (arr[mid] < x)
            low = mid + 1;

        // Move left
        else
            high = mid - 1;
    }

    return high;
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter sorted array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int x, k;

    printf("Enter target value: ");
    scanf("%d", &x);

    printf("Enter K: ");
    scanf("%d", &k);

    // Find the crossover point
    int left = findCrossOver(arr, 0, n - 1, x);

    // Right pointer starts immediately after crossover
    int right = left + 1;

    // If x itself exists, ignore it
    if (left >= 0 && arr[left] == x)
        left--;

    printf("Closest %d elements are:\n", k);

    // Compare left and right elements
    while (left >= 0 && right < n && k > 0) {

        // Distance from target
        int leftDiff = x - arr[left];
        int rightDiff = arr[right] - x;

        // Left element is closer
        if (leftDiff < rightDiff) {
            printf("%d ", arr[left]);
            left--;
        }

        // Right element is closer
        else if (leftDiff > rightDiff) {
            printf("%d ", arr[right]);
            right++;
        }

        // Equal difference
        else {

            // Printing larger value
            // (Change to left if question wants smaller value)
            printf("%d ", arr[right]);
            right++;
        }

        k--;
    }

    // If left side still has elements
    while (k > 0 && left >= 0) {
        printf("%d ", arr[left]);
        left--;
        k--;
    }

    // If right side still has elements
    while (k > 0 && right < n) {
        printf("%d ", arr[right]);
        right++;
        k--;
    }

    printf("\n");

    free(arr);

    return 0;
}/*
Enter number of elements: 5
Enter sorted array: 2
4
7
8
10
Enter target value: 8
Enter K: 2
Closest 2 elements are:
7 10 */