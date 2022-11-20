#include <stdio.h>
#define ABS(a) (a) < 0 ? -(a) : (a)
#define MAX_NUM 1000000

void coinExchange(int coins[], int numDiffCoins, int change, int coinsUsed[], int lastCoin[]);
void reconstruct(int change, int lastCoin[], int* cnt);

int main(void) {
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++) {
        int n, a, b, tmp;
        scanf("%d %d %d", &n, &a, &b);
        for (int i = 0; i < n - 2; i++) {
            scanf("%d", &tmp);
            if (a <= b) a += tmp;
            else b += tmp;
        }
        
        a = ABS(a-b);
        tmp = 0;
        int coins[] = {1, 2, 5, 10, 20, 50, 100};
        int C[MAX_NUM], L[MAX_NUM];
        coinExchange(coins, 7, a, C, L);
        reconstruct(a, L, &tmp);
        printf("%d\n", tmp);
    }
    return 0;
}

void coinExchange(int coins[], int numDiffCoins, int change, int coinsUsed[], int lastCoin[]) {
    coinsUsed[0] = lastCoin[0] = 0;

    for(int cents = 1; cents <= change; cents++) {
        int minCoins, newCoin;

        minCoins = cents;
        newCoin = 1;
        for(int j = 0; j < numDiffCoins; j++) {
            if (coins[j] > cents)
                continue;
            if (coinsUsed[cents-coins[j]] + 1 < minCoins) {
                minCoins = coinsUsed[cents-coins[j]] + 1;
                newCoin = coins[j];
            }
        }

        coinsUsed[cents] = minCoins;
        lastCoin[cents] = newCoin;
    }
}

void reconstruct(int change, int lastCoin[], int* cnt) {
    if (change > 0) {
        reconstruct(change-lastCoin[change], lastCoin, cnt);
        (*cnt)++;
    }
    return;
}