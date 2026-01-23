#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100000010
#define MAX_PRIME 6000000

bool isPrime[MAX_N];
int Prime[MAX_PRIME];
int cnt = 0;

void GetPrime(int n) {
    memset(isPrime, 1, (n + 1) * sizeof(bool));
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            Prime[cnt++] = i;
        }

        for (int j = 0; j < cnt; j++) {
            long long num = (long long)i * Prime[j];
            if (num > n) break;

            isPrime[num] = false;

            if (i % Prime[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    GetPrime(n);

    for (int i = 0; i < q; i++) {
        int k;
        scanf("%d", &k);
        printf("%d\n", Prime[k - 1]);
    }

    return 0;
}
