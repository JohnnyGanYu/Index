#include <stdio.h>

int main(void)
{
    printf("������һ������Ϊ2����������");
    char building = getchar();
    char category = getchar();
    char *out;
    switch (building)
    {
    case '1':
        switch (category)
        {
        case '1':
            out = "A¥������\n";
            break;
        case '2':
            out = "A¥ʪ����\n";
            break;
        case '3':
            out = "A¥�ɻ�������\n";
            break;
        case '4':
            out = "A¥�к�����\n";
            break;
        default:
            out = "���������������Ч��ǩ��\n";
        }
        break;
        case '2':
        switch (category)
        {
        case '1':
            out = "B¥������\n";
            break;
        case '2':
            out = "B¥ʪ����\n";
            break;
        case '3':
            out = "B¥�ɻ�������\n";
            break;
        case '4':
            out = "B¥�к�����\n";
            break;
        default:
            out = "���������������Ч��ǩ��\n";
        }
        break;
    default:
        out = "���������������Ч��ǩ��\n";
    }
    printf("%s", out);
    return 0;
}
