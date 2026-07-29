#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int coin[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    scanf("%d", &m);

    int dp[101] = {0};
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= m; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    printf("%d", dp[m]);

    return 0;
}