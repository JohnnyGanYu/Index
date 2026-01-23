#include <stdio.h>

int main(void)
{
    int n, a, b;
    scanf("%d", &n);
    for ( a = 1; a < 9; a++ )
    {
        for ( b = a + 1; b < 10; b++ )
        {
            if ( a*a*10 + b*b*10 + 101*a*b == n )
            {
                printf("%d%d\n", a, b);
                return 0;
            }
        }

    }
    printf("No Answer\n");
    return 0;
}