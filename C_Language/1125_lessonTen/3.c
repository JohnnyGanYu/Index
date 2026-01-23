#include <stdio.h>

int main(void)
{
    int n, i, j;
    int triangle[13][13]; 

    scanf("%d", &n);

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j < (n - i) * 2; j++) {
            printf(" ");
        }

        for (j = 0; j <= i; j++) {
            printf("%4d", triangle[i][j]);
        }
        printf("\n");
    }
    return 0;
}