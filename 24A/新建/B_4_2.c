#include <stdio.h>

int main(void)
{
    printf("������0��1��ɵ��ַ�����\n");
    char str[101];
    int cnt = 0, i = 0;
    for (i = 0; i < 100; i++)
    {
        scanf("%c", &str[i]);
        if (str[i] == '\n')
        {
            break;
        }
        if (str[i] == '1')
        {
            cnt = !cnt;
        }
    }
    str[i] = cnt + '0';
    printf("%s", str);
    return 0;
}
