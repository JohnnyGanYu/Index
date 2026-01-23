#include <stdio.h>
#include <math.h>

int main() {
    double m; // 本金（万元）
    int n;  // 月数
    double rate = 0.17 / 100;  // 月利率 0.17%
    double total;  // 本息总额

    // 输入本金和月数
    printf("请输入本金m，存入月数n:");
    scanf("%lf %d", &m, &n);

    // 计算复利本息总额
    total = m * pow(1 + rate, n);

    // 输出结果，保留2位小数
    printf("%d月后的利息和本金为: %.2f万元\n", n, total);

    return 0;

}
