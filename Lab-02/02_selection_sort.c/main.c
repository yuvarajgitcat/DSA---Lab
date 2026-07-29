#include <stdio.h>

struct Date {
    int day, month, year;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Date d[20], temp;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &d[i].day, &d[i].month, &d[i].year);
    }

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (d[j].year < d[min].year ||
               (d[j].year == d[min].year && d[j].month < d[min].month) ||
               (d[j].year == d[min].year && d[j].month == d[min].month && d[j].day < d[min].day)) {
                min = j;
            }
        }

        if (min != i) {
            temp = d[i];
            d[i] = d[min];
            d[min] = temp;
        }
    }

    // Output
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", d[i].day, d[i].month, d[i].year);
    }

    return 0;
}