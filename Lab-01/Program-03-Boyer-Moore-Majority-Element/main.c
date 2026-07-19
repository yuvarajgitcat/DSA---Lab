#include<stdio.h>
#include<stdlib.h>

int main() {

    int n, i, j, count;

    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++) {

        count = 0;

        for(j = 0; j < n; j++) {

            if(a[i] == a[j])
                count++;
        }

        if(count > n - 2) {
            printf("%d", a[i]);
            free(a);
            return 0;
        }
    }

    printf("No majority candidate found.");

    free(a);

    return 0;
}