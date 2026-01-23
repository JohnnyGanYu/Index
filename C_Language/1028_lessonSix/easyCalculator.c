#include <stdio.h>
#include <math.h>

void menu(void)
{
    printf("\t简单运算器\n"
           "***************************\n"
           "\t加法运算---1\n"
           "\t减法运算---2\n"
           "\t乘法运算---3\n"
           "\t除法运算---4\n"
           "***************************\n"
           "请输入你的选项:\n");
}

float easyCalculator(void)
{
    int n, num1, num2;
    float ans;

    menu();
    scanf("%d", &n);

    if (n < 1 || n > 4)
    {
        printf("输入错了, 只能1~4\n");
        return NAN;
    }

    printf("请输入两个整数: ");
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
            printf("除数不能为零\n");
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
