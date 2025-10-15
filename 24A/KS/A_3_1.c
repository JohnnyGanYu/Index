#include <stdio.h>
float fun (int n)
{
    float  A=0;
    int i;
    for (i=1; i<n; i++)
        A = 1.0/(1+A);
    return A ;
}

int main(void)
{
    int n ;
    printf("input n: ") ;
    scanf("%d", n ) ;
    printf("A%d=%f\n", n, fun(int n) );
    return 0;
}

