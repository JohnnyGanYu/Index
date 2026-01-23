#include <stdio.h>

int main(void)
{
    int n;
    int size;
    int i, j;
    int top, bottom, left, right;
    int min_distance;
    scanf("%d", &n);
    size = 2 * n - 1;

    for( i = 0; i < size; i++ )
    {
        for ( j = 0; j < size; j++ )
        {
            top = i;
            bottom = size - 1 - i;
            left = j;
            right = size - 1 - j;

            min_distance = top;
            if (bottom < min_distance) min_distance = bottom;
            if (left < min_distance) min_distance = left;
            if (right < min_distance) min_distance = right;

            printf("%d", min_distance + 1);
        }
        printf("\n");
    }
    return 0;
}