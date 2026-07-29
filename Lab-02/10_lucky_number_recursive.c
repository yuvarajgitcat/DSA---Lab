#include <stdio.h>

int sumDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int n;
    scanf("%d", &n);

    int square = n * n;

    if (sumDigits(square) == n)
        printf("Yes, %d is a lucky number", n);
    else
        printf("No, %d is not a lucky number", n);

    return 0;
}