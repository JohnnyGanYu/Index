#include <stdio.h>

int main() {
    double x;
    int n, i;
    scanf("%lf %d", &x, &n);
    
    double term = x;
    double sum = term;
    
    for ( i = 1; i < n; i++) {
        term *= -x * x / ((2 * i) * (2 * i + 1));
        sum += term;
    }
    
    printf("%.8f\n", sum);
    return 0;
}