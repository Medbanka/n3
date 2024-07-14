#include <stdio.h>

int main() {
    int p;
    printf("Введіть кількість розрядів (p): ");
    scanf("%d", &p);

    if (p < 1 || p > 30) {
        printf("Кількість розрядів повинна бути в межах від 1 до 30.\n");
        return 1;
    }

    long long dp[p+1][2];

    dp[1][0] = 2; // 5, 9
    dp[1][1] = 0;

    if (p >= 2) {
        dp[2][0] = 2; // 59, 95
        dp[2][1] = 2; // 55, 99
    }

    for (int i = 3; i <= p; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    long long result = dp[p][0] + dp[p][1];
    printf("Кількість чисел із %d розрядів: %lld\n", p, result);

    return 0;
}
