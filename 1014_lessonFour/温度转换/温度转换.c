// 第一题：温度转换
// 输入摄氏温度，求对应的华氏温度
#include <stdio.h>      // 标准输入输出库

double celsius_to_fahrenheit(double celsius_temp)
{   // 函数celsius_to_fahrenheit：将摄氏温度转换为华氏温度
    double fahrenheit_temp;

    fahrenheit_temp = (9.0 / 5.0) * celsius_temp + 32;

    return fahrenheit_temp;
}   // 函数celsius_to_fahrenheit

int main(void)
{   // 主函数
    double input_celsius;      // 存储输入的摄氏温度
    double result_fahrenheit;  // 存储转换后的华氏温度

    // 从键盘读取摄氏温度
    printf("请输入摄氏温度: ");
    scanf("%lf", &input_celsius);

    // 调用温度转换函数
    result_fahrenheit = celsius_to_fahrenheit(input_celsius);

    // 输出转换结果
    printf("温度转换完成！\n");
    printf("摄氏温度: %.2f°C\n", input_celsius);
    printf("华氏温度: %.2f°F\n", result_fahrenheit);
    printf("转换公式: F = (9/5) × %.2f + 32 = %.2f\n",
           input_celsius, result_fahrenheit);

    return 0;
}   // 主函数

//请输入摄氏温度: 25
//温度转换完成！
//摄氏温度: 25.00°C
//华氏温度: 77.00°F
//转换公式: F = (9/5) × 25.00 + 32 = 77.00
