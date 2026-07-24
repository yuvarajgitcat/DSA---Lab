#include <stdio.h>
#include <stdlib.h>

int main() {

    int size;

    // Read size of array
    printf("Enter number of ride IDs: ");
    scanf("%d", &size);

    int *rideIDs = (int *)malloc(size * sizeof(int));

    // Read sorted ride IDs
    printf("Enter the sorted ride IDs:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &rideIDs[i]);

    int targetID;

    // Read target ride ID
    printf("Enter target ride ID: ");
    scanf("%d", &targetID);

    int low = 0;
    int high = size - 1;

    // Binary Search
    while (low <= high) {

        int mid = (low + high) / 2;

        if (rideIDs[mid] == targetID) {
            printf("Insert Position = %d\n", mid);
            free(rideIDs);
            return 0;
        }

        if (rideIDs[mid] < targetID)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // Target not found
    // 'low' is the correct insertion position
    printf("Insert Position = %d\n", low);

    free(rideIDs);

    return 0;
}