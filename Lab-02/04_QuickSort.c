#include <stdio.h>
#include <string.h>

struct Student {
    char name[20], major[20];
    float gpa;
    int age;
};

void swap(struct Student *a, struct Student *b) {
    struct Student t = *a;
    *a = *b;
    *b = t;
}

int partition(struct Student s[], int low, int high, char key[]) {
    int i = low - 1;

    for (int j = low; j < high; j++) {
        int cond = 0;

        if (strcmp(key, "gpa") == 0)
            cond = s[j].gpa < s[high].gpa;
        else if (strcmp(key, "age") == 0)
            cond = s[j].age < s[high].age;
        else
            cond = strcmp(s[j].major, s[high].major) < 0;

        if (cond) {
            i++;
            swap(&s[i], &s[j]);
        }
    }

    swap(&s[i + 1], &s[high]);
    return i + 1;
}

void quicksort(struct Student s[], int low, int high, char key[]) {
    if (low < high) {
        int p = partition(s, low, high, key);
        quicksort(s, low, p - 1, key);
        quicksort(s, p + 1, high, key);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Student s[10];

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i].name);
        scanf("%f", &s[i].gpa);
        scanf("%d", &s[i].age);
        scanf("%s", s[i].major);
    }

    char key[10];
    scanf("%s", key);

    quicksort(s, 0, n - 1, key);

    printf("Sorted Student Records:\n");
    printf("Name\t\tGPA\tAge\t\tMajor\n");

    for (int i = 0; i < n; i++) {
        printf("%-10s\t%.2f\t%d\t\t%s\n",
               s[i].name, s[i].gpa, s[i].age, s[i].major);
    }

    return 0;
}