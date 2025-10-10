#include <stdio.h>

int main()
{
    float height, weight;
    
    // 输入身高
    printf("请输入您的身高(cm): ");
    scanf("%f", &height);
    
    // 计算标准体重
    weight = (height - 100) * 0.9;
    
    // 输出结果，保留两位小数
    printf("您的标准体重为: %.2f kg\n", weight);
    
    return 0;
}