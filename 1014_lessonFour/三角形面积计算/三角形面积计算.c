// 第二题：三角形面积计算
// 输入三角形的3条边，计算三角形的面积
#include <stdio.h>      // 标准输入输出库
#include <math.h>       // 数学函数库

double calculate_triangle_area(double side_a, double side_b, double side_c)
{   // 函数calculate_triangle_area：计算三角形面积
    double semi_perimeter;  // 半周长
    double triangle_area;   // 三角形面积

    // 计算半周长
    semi_perimeter = (side_a + side_b + side_c) / 2.0;

    // 使用海伦公式计算面积
    triangle_area = sqrt(semi_perimeter *
                        (semi_perimeter - side_a) *
                        (semi_perimeter - side_b) *
                        (semi_perimeter - side_c));

    return triangle_area;
}   // 函数calculate_triangle_area

int main(void)
{   // 主函数
    double side_length_a;   // 存储三角形边长a
    double side_length_b;   // 存储三角形边长b
    double side_length_c;   // 存储三角形边长c
    double area_result;     // 存储计算出的面积

    // 从键盘读取三条边长
    printf("请输入三角形的三条边长（用空格分隔）: ");
    scanf("%lf %lf %lf", &side_length_a, &side_length_b, &side_length_c);

    // 调用面积计算函数
    area_result = calculate_triangle_area(side_length_a, side_length_b, side_length_c);

    // 输出计算结果
    printf("三角形面积计算完成！\n");
    printf("三角形边长: a=%.2f, b=%.2f, c=%.2f\n",
           side_length_a, side_length_b, side_length_c);
    printf("三角形面积: %.2f\n", area_result);

    return 0;
}   // 主函数

//请输入三角形的三条边长（用空格分隔）: 3 4 5
//三角形面积计算完成！
//三角形边长: a=3.00, b=4.00, c=5.00
//三角形面积: 6.00
