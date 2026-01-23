#include <stdio.h>
#define N 5

int main(void)
{
    int a[N];
    int min;
    for ( int i = 0; i < N; i++ )
    {
        scanf("%d",&a[i]);
    }
    min = a[0];
    for ( int i = 1; i < N; i++ )
    {
        if ( a[i] < min )
        {
            min = a[i];
        }
    } 
    printf("%d", min);
    return 0;
}
