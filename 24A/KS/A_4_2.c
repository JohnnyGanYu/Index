/* A_4_2.c, 10/15/2025, 删除字符串 str 中的字母和数字字符之外的所有字符；
    将所有大写字母转换为小写字母；判断转换后的字符串是否是回5文串。
    如果是回文串，返回 1；否则返回 0。*/
#include <stdio.h>
#include <ctype.h>

int isPalindrome(char str[])
{
    int j = 0, left = 0, right, ret;
    printf("删除后: ");
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

    printf("请输入字符串:");
    gets(str);

    rt = isPalindrome(str);
    printf("\n转换后: %s\n", str);
    if ( !rt )
    {
        printf("不");
    }
    printf("是回文串\n");
}
