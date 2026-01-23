#include <stdio.h>
#include <math.h>


int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%d\n%ld", 100000 * n, (long)(pow(2, n) * 1)-1);

    return 0;
}