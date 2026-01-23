#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long long a, b, g, l;
    scanf("%lld %lld", &a, &b);
    
    g = gcd(a, b);
    l = (a / g) * b;
    
    printf("%lld %lld\n", g, l);
    return 0;
}