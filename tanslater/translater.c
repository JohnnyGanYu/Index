#include <stdio.h>

int main()
{
    printf("请输入大写字母");
    char capital ;
    scanf("%c", &capital);
    char lowercase ;
    const int caseOffset = 32;
    lowercase = capital + caseOffset ;
    printf("大写字母%c 的小写为%c\n",capital,lowercase);
    return 0;
}