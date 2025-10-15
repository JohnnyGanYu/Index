// A_4_1.c, 2025/10/15, 根据分数评判企业等级
#include <stdio.h>  // 标准输入输出库

int main(void)
{// 主函数：无输入, 根据分数评判企业等级
    double score;   // 存储键盘输入的企业成绩
    const char *output; // 存储将要输出的企业等级

    // 从键盘输入的企业成绩
    printf("请输入企业得分:\n");
    scanf("%lf", &score);

    //分支评判企业等级
    if (score < 0 || score > 100)
        {
            output = "输入错误";
        }
    else if (score < 70)
        {
            output = "*";
        }
    else if (score < 80)
        {
            output = "**\n";
        }
    else if (score < 90)
        {
            output = "***";
        }
    else
        {
            output = "****";
        }

    //输出企业等级
    printf("%s\n", output);

    return 0;
}   // 主函数
