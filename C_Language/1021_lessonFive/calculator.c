#include <stdio.h>
#include <math.h>

float getAnswer(int num1, char a, int num2)
{
    float ans = NAN;
    switch (a)
    {
        case '+': ans = num1 + num2; break;
        case '-': ans = num1 - num2; break;
        case '*': ans = num1 * num2; break;
        case '/':
        {
            if (num2 != 0)
            {
                ans = (float)num1 / num2;
                break;
            }
        }
        case '%':
            if (num2 != 0)
            {
                ans = num1 % num2;
                break;
            }
        default: break;
    }
    return ans;
}

int main(void)
{
    int num1, num2;
    char a;
    printf("请输入运算式: ");
    scanf("%d%c%d", &num1, &a, &num2);
    float ans = getAnswer(num1, a, num2);
    if (!isnan(ans))
    {
        printf("%.2f", ans);
    }
    else
    {
        printf("出错！");
    }
}
