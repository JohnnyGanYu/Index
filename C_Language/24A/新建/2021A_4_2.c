#include <stdio.h>

void sortArray(float *a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i -1; j++)
            if (a[j] > a[j+1])
            {
                float temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    return;
}

int main(void)
{
    int n;
    float a[10000];
    printf("请输入学生的人数: ");
    scanf("%d", &n);
    while (getchar() != '\n');
    printf("请输入%d个学生的分数: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
    }
    sortArray(a, n);
    if (n%2 == 0)
    {
        printf("中位数为: %.2f", (a[n/2] + a[n/2-1])/2.0);
        return 0;
    }
    printf("中位数为: %.2f", a[n/2]);
    return 0;
}
