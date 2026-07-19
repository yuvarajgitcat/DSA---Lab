#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int search, i, n;
    scanf("%d", &n);
    
    int *a = malloc(n * sizeof *a);
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &search);
    
    for (i = 0; i < n; i++) {
        if (a[i] == search) {
            printf("Congratulations! Ticket number %d found at position %d!\n" , search, i + 1);
            break;
        }
    }
    
    if (i >= n) {
        printf("Better luck next time! Ticket number %d not found!\n", search);
    } 
    free(a);
    return 0;
}
