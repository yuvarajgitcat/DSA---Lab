#include <stdio.h>
#include <stdlib.h>

int main() {

    int size1, size2;

    // Read size of first array
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    int *firstArray = (int *)malloc(size1 * sizeof(int));

    // Read first sorted array
    printf("Enter the elements of the first sorted array:\n");
    for (int i = 0; i < size1; i++)
        scanf("%d", &firstArray[i]);

    // Read size of second array
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    int *secondArray = (int *)malloc(size2 * sizeof(int));

    // Read second sorted array
    printf("Enter the elements of the second sorted array:\n");
    for (int i = 0; i < size2; i++)
        scanf("%d", &secondArray[i]);

    // Allocate memory for merged array
    int *mergedArray = (int *)malloc((size1 + size2) * sizeof(int));

    // Indices for first array, second array, and merged array
    int firstIndex = 0;
    int secondIndex = 0;
    int mergedIndex = 0;

    // Merge both sorted arrays
    while (firstIndex < size1 && secondIndex < size2) {

        if (firstArray[firstIndex] < secondArray[secondIndex])
            mergedArray[mergedIndex++] = firstArray[firstIndex++];
        else
            mergedArray[mergedIndex++] = secondArray[secondIndex++];
    }

    // Copy remaining elements from first array
    while (firstIndex < size1)
        mergedArray[mergedIndex++] = firstArray[firstIndex++];

    // Copy remaining elements from second array
    while (secondIndex < size2)
        mergedArray[mergedIndex++] = secondArray[secondIndex++];

    // Total number of elements
    int totalElements = size1 + size2;

    float median;

    // Calculate median
    if (totalElements % 2 == 0)
        median = (mergedArray[totalElements / 2] +
                  mergedArray[totalElements / 2 - 1]) / 2.0;
    else
        median = mergedArray[totalElements / 2];

    // Display result
    printf("Median of the merged arrays = %.2f\n", median);

    // Free allocated memory
    free(firstArray);
    free(secondArray);
    free(mergedArray);

    return 0;
}
/*
PS A:\VIT Chennai\DSAA_01\DSA - Lab\Lab-01\
Program-15-Merge-Two-Sorted-Arrays-Median> 
& "A:\VIT Chennai\DSAA_01\DSA - Lab\Lab-01\
Program-15-Merge-Two-Sorted-Arrays-Median\
main.exe"
Enter the size of the first array: 3
Enter the elements of the first sorted array:
54
87
90
Enter the size of the second array: 1
Enter the elements of the second sorted array:
67
Median of the merged arrays = 77.00*/