// 第五题：文件编辑
// 文件编辑.c， 2025年10月14日，从键盘读取数字，保存到t1.txt，读取后加100存到t2.txt，并输出结果。
#include <stdio.h>      // 标准输入输出库
#include <stdlib.h>     // 标准库函数

void write_to_file(const char *filename, int value)
{   // 函数write_to_file：写入数字到文件
    FILE *file_pointer = fopen(filename, "w");

    if (file_pointer == NULL)
    {
        printf("错误：%s文件打开失败\n", filename);
        exit(1);
    }

    fprintf(file_pointer, "%d", value);
    fclose(file_pointer);
}   // 函数write_to_file

int read_from_file(const char *filename)
{   // 函数read_from_file：从文件读取数字，返回读取到的整数值
    FILE *file_pointer = fopen(filename, "r");
    int read_value;

    if (file_pointer == NULL)
    {
        printf("错误：%s文件打开失败\n", filename);
        exit(1);
    }

    fscanf(file_pointer, "%d", &read_value);
    fclose(file_pointer);

    return read_value;
}   // 函数read_from_file

int main(void)
{   // 主函数
    int input_value;    // 存储键盘输入值
    int read_value;     // 存储从文件读取的值
    int result_value;   // 存储最终结果值

    // 从键盘读取数字
    printf("请输入一个整数: ");
    scanf("%d", &input_value);

    // 保存到t1.txt
    write_to_file("t1.txt", input_value);

    // 从t1.txt读取数字
    read_value = read_from_file("t1.txt");

    // 计算加100后的结果
    result_value = read_value + 100;

    // 保存结果到t2.txt
    write_to_file("t2.txt", result_value);

    // 从t2.txt读取并输出结果
    result_value = read_from_file("t2.txt");

    printf("处理完成！\n");
    printf("最终结果（t2.txt内容）: %d\n", result_value);
    printf("处理流程：键盘输入(%d) → t1.txt(%d) → t2.txt(%d)\n",
           input_value, read_value, result_value);

    return 0;
}   // 主函数

//运行示例：
//请输入一个整数: 50
//处理完成！
//最终结果（t2.txt内容）: 150
//数据流程：键盘输入(50) -> t1.txt(50) -> t2.txt(150)
