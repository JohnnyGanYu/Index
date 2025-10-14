#include <stdio.h>
#include <stdlib.h>

// 函数声明
void write_to_file(const char *filename, int value);
int read_from_file(const char *filename);

int main()
{
    int input_value;

    // 从键盘读取数字
    printf("请输入一个整数: ");
    scanf("%d", &input_value);

    // 保存到t1.txt
    write_to_file("t1.txt", input_value);

    // 从t1.txt读取数字
    int read_value = read_from_file("t1.txt");

    // 加100后保存到t2.txt
    write_to_file("t2.txt", read_value + 100);

    printf("处理完成！\n");
    printf("流程：键盘输入(%d) -> t1.txt(%d) -> t2.txt(%d)\n",
           input_value, read_value, read_value + 100);

    return 0;
}

// 函数：写入数字到文件
void write_to_file(const char *filename, int value)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("%s文件打开失败\n", filename);
        exit(1);
    }
    fprintf(fp, "%d", value);
    fclose(fp);
}

// 函数：从文件读取数字
int read_from_file(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s文件打开失败\n", filename);
        exit(1);
    }
    int value;
    fscanf(fp, "%d", &value);
    fclose(fp);
    return value;
}
