#include <stdio.h>

int isTriangle(int a, int b, int c)
{
    int i = 0;
    if ((a+b) > c && (b+c) > a && (a+c) > b)
    {
        i = 1;
    }
    return i;
}

const char* triangleCategory(int a, int b, int c)
{
    const char* category = "一般三角形"; // 默认值

    // 判断三角形类型
    if (a == b && b == c)
    {
        category = "等边三角形";
    }
    else if (a == b || b == c || c == a)
    {
        category = "等腰三角形";
    }
    else if (a*a + b*b == c*c || a*a + c*c == b*b || c*c + b*b == a*a)
    {
        category = "直角三角形";
    }

    return category;
}


int main(void)
{
    int  a, b, c;
    printf("请输入三个数: ");
    scanf("%d %d %d", &a, &b, &c);

    if (isTriangle(a, b, c))
    {
        printf("三角形的周长是: %d\n", a+b+c);
        printf("三角形的类型是: %s\n", triangleCategory(a, b, c));
    }
    else
    {
        printf("不能构成三角形\n");
    }

    return 0;
}
