#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    char max = 0;
    printf("�����볤��С��100���ַ�����\n");
    gets(str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] > max)
        {
            max = str[i];
        }
    }
    printf("%s%c", str, max);
    return 0;
}
