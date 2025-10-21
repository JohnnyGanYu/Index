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
    const char* category = "һ��������"; // Ĭ��ֵ

    // �ж�����������
    if (a == b && b == c)
    {
        category = "�ȱ�������";
    }
    else if (a == b || b == c || c == a)
    {
        category = "����������";
    }
    else if (a*a + b*b == c*c || a*a + c*c == b*b || c*c + b*b == a*a)
    {
        category = "ֱ��������";
    }

    return category;
}


int main(void)
{
    int  a, b, c;
    printf("������������: ");
    scanf("%d %d %d", &a, &b, &c);

    if (isTriangle(a, b, c))
    {
        printf("�����ε��ܳ���: %d\n", a+b+c);
        printf("�����ε�������: %s\n", triangleCategory(a, b, c));
    }
    else
    {
        printf("���ܹ���������\n");
    }

    return 0;
}
