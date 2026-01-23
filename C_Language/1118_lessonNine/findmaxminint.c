#include <stdio.h>

int main(void)
{
    int num, max, min, i;
    scanf("%d", &num);
    int arr[num];
    scanf("%d", &arr[0]);
    max = min = arr[0];
    for ( i = 1; i < num; i++ )
    {
        scanf("%d", &arr[i]);
        if ( max < arr[i] )
        {
            max = arr[i];
        }
        else if ( min > arr[i] )
        {
            min = arr[i];
        }
    }
    printf("%d %d\n", max, min);
    return 0;
}