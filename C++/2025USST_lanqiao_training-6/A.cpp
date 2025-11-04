#include <stdio.h>
#define N (3)
using namespace std;

int main(void)
{
    int a[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        printf("%8d", a[i]);
    }
    printf("%c", '\n');


    return 0;
}