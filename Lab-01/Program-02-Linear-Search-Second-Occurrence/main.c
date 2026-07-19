#include<stdio.h>
#include<stdlib.h>

int main() {
    int count  = 0;
    int search, i ,n;
    printf("Enter the number of feedback entries: ");
    scanf("%d", &n);
    int *a = malloc(n *sizeof *a);
    if (a ==NULL){
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the feedback points: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the feedback point to evaluate: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) {
        if (a[i] == search) {
            count++;
            if (count == 2) {
                printf("The second occurrence of feedback point %d is at position %d.\n", search, i + 1);
                break;
            }
        }
    }
    if (count == 1) {
        printf("The feedback point %d found only Once.\n", search);
    } else if (count == 0) {
        printf("The feedback point %d not found.\n", search);
    }

}