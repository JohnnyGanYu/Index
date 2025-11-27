#include <stdio.h>

int main(void)
{
    double x, ans = 0, temp = 1;
    int n, i;
    scanf("%lf %d", &x, &n);
    for ( i = 0; i <= n; i++ )
    {
        ans += temp;   
        temp *= x / (i+1.0);
    }
    printf("%.6lf\n", ans);
    return 0; 
}