//EuclideanAlogrithm.c 
#include <stdio.h>

int main(void)
{
    int m, n, r;
    scanf("%d %d", &m, &n);



    do 
    {
        r = m % n;
        m = n;
        n = r;
    }
    while (r != 0); 

    printf("%d", m);

    return 0;
}