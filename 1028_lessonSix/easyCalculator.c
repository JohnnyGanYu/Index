#include <stdio.h>
#include <math.h>

void menu(void)
{
    printf("\t��������\n"
           "***************************\n"
           "\t�ӷ�����---1\n"
           "\t��������---2\n"
           "\t�˷�����---3\n"
           "\t��������---4\n"
           "***************************\n"
           "���������ѡ��:\n");
}

float easyCalculator(void)
{
    int n, num1, num2;
    float ans;

    menu();
    scanf("%d", &n);

    if (n < 1 || n > 4)
    {
        printf("�������, ֻ��1~4\n");
        return NAN;
    }

    printf("��������������: ");
    scanf("%d %d", &num1, &num2);
    switch (n)
    {
    case 1:
        ans = (float)num1 + num2;
        break;
    case 2:
        ans = (float)num1 - num2;
        break;
    case 3:
        ans = (float)num1 * num2;
        break;
    case 4:
        if (num2 == 0)
        {
            printf("��������Ϊ��\n");
            return NAN;
        }
        ans = (float)num1 / num2;
        break;
    }

    printf("%.2f\n", ans);
    return ans;
}

int main(void)
{
    easyCalculator();

    return 0;
}
