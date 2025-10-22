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
    printf("������ѧ��������: ");
    scanf("%d", &n);
    while (getchar() != '\n');
    printf("������%d��ѧ���ķ���: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
    }
    sortArray(a, n);
    if (n%2 == 0)
    {
        printf("��λ��Ϊ: %.2f", (a[n/2] + a[n/2-1])/2.0);
        return 0;
    }
    printf("��λ��Ϊ: %.2f", a[n/2]);
    return 0;
}
