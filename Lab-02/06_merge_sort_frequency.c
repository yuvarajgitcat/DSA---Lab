#include <stdio.h>

int freq[101];

void merge(int a[], int l, int m, int r) {
    int temp[30];
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (freq[a[i]] < freq[a[j]])
            temp[k++] = a[i++];
        else if (freq[a[i]] > freq[a[j]])
            temp[k++] = a[j++];
        else {
            if (a[i] > a[j])      // Same frequency -> larger value first
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main() {
    int n, a[30];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}