// 第三题：字符ASCII码查询
// 输入任意字符，输出其ASCII码
#include <stdio.h>      // 标准输入输出库

void display_ascii_code(char input_char)
{   // 函数display_ascii_code：显示字符的ASCII码
    int ascii_value;    // ASCII码数值

    ascii_value = (int)input_char;  // 字符转换为ASCII码

    printf("字符 '%c' 的ASCII码信息:\n", input_char);
    printf("十进制: %d\n", ascii_value);
    printf("八进制: %o\n", ascii_value);
    printf("十六进制: %X\n", ascii_value);
}   // 函数display_ascii_code

int main(void)
{   // 主函数
    char input_character;   // 存储输入的字符

    // 从键盘读取字符
    printf("请输入一个字符: ");
    scanf("%c", &input_character);

    // 调用ASCII码显示函数
    display_ascii_code(input_character);

    return 0;
}   // 主函数

//请输入一个字符: A
//字符 'A' 的ASCII码信息:
//十进制: 65
//八进制: 101
//十六进制: 41
