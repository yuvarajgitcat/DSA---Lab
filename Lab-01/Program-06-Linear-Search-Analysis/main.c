#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x;
    printf("Enter the number of interactions: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    int sum = 0;
    printf("Enter the interaction IDs: ");
    // Read array and calculate sum
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Enter the interaction ID to search: ");
    scanf("%d", &x);

    int comparisons = 0;
    int index = -1;

    // Linear Search
    for (int i = 0; i < n; i++) {
        comparisons++;

        if (arr[i] == x) {
            index = i;
            break;
        }
    }

    if (index != -1)
        printf("Interaction ID %d is present at index %d\n", x, index);
    else
        printf("Interaction ID %d is not present\n", x);

    printf("Total comparisons made: %d\n", comparisons);
    printf("Sum of all interaction: %d\n", sum);
    printf("Average of all interaction: %.2f\n", (double)sum / n);

    free(arr);

    return 0;
}
/*
Enter the number of interactions: 5
Enter the interaction IDs: 10
30
40
20
10
Enter the interaction ID to search: 10
Interaction ID 10 is present at index 0
Total comparisons made: 1
Sum of all interaction: 110
Average of all interaction: 22.00
*/