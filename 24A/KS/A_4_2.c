/* A_4_2.c, 10/15/2025, ɾ���ַ��� str �е���ĸ�������ַ�֮��������ַ���
    �����д�д��ĸת��ΪСд��ĸ���ж�ת������ַ����Ƿ��ǻ�5�Ĵ���
    ����ǻ��Ĵ������� 1�����򷵻� 0��*/
#include <stdio.h>
#include <ctype.h>

int isPalindrome(char str[])
{
    int j = 0, left = 0, right, ret;
    printf("ɾ����: ");
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalnum(str[i]))
        {
            printf("%c",str[i]);
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
    right = j - 1;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return 0;
        }
        left ++;
        right --;
    }
    return 1;
}

int main(void)
{
    char str[100];
    int rt;

    printf("�������ַ���:");
    gets(str);

    rt = isPalindrome(str);
    printf("\nת����: %s\n", str);
    if ( !rt )
    {
        printf("��");
    }
    printf("�ǻ��Ĵ�\n");
}
