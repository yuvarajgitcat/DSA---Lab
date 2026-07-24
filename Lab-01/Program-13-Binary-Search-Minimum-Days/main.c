#include <stdio.h>
#include <stdlib.h>

// Check whether m meals can be prepared on the given day
int canPrepareMeals(int availabilityDay[], int size, int day, int meals, int boxesNeeded) {

    int consecutiveBoxes = 0;
    int mealsPrepared = 0;

    for (int i = 0; i < size; i++) {

        // Box is available
        if (availabilityDay[i] <= day) {
            consecutiveBoxes++;

            // Enough adjacent boxes for one meal
            if (consecutiveBoxes == boxesNeeded) {
                mealsPrepared++;
                consecutiveBoxes = 0;
            }
        }
        else {
            consecutiveBoxes = 0;
        }
    }

    return mealsPrepared >= meals;
}

// Recursive Binary Search
int recursiveBinarySearch(int availabilityDay[], int size,
                          int low, int high,
                          int meals, int boxesNeeded) {

    if (low > high)
        return low;

    int mid = (low + high) / 2;

    if (canPrepareMeals(availabilityDay, size, mid, meals, boxesNeeded))
        return recursiveBinarySearch(availabilityDay, size,
                                     low, mid - 1,
                                     meals, boxesNeeded);
    else
        return recursiveBinarySearch(availabilityDay, size,
                                     mid + 1, high,
                                     meals, boxesNeeded);
}

int main() {

    int size;

    printf("Enter number of ingredient boxes: ");
    scanf("%d", &size);

    int *availabilityDay = (int *)malloc(size * sizeof(int));

    printf("Enter availability days:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &availabilityDay[i]);

    int meals, boxesNeeded;

    printf("Enter number of meals: ");
    scanf("%d", &meals);

    printf("Enter boxes needed per meal: ");
    scanf("%d", &boxesNeeded);

    // Impossible case
    if (meals * boxesNeeded > size) {
        printf("-1\n");
        free(availabilityDay);
        return 0;
    }

    // Find maximum day
    int maxDay = availabilityDay[0];

    for (int i = 1; i < size; i++) {
        if (availabilityDay[i] > maxDay)
            maxDay = availabilityDay[i];
    }

    int answer = recursiveBinarySearch(
        availabilityDay,
        size,
        1,
        maxDay,
        meals,
        boxesNeeded
    );

    printf("Minimum number of days = %d\n", answer);

    free(availabilityDay);

    return 0;
}