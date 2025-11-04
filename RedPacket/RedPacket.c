#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void line(void)
{
        for (int i = 0; i < 20; i++)
    {
        putchar('-');
    }
    putchar('\n');
    return;
}

void menu(void)
{
    line();
    printf("发红包程序：\n"
        "1. 一般红包\n"
        "2. 拼手气红包\n"
        "3. 口令红包\n"
        "0. 退出\n");
    line();
    printf("请输入你的选择(0-3):");
    return;
}

void commonPacket(void)
{
    float amount;
    int number;
    printf("请输入总金额（元）和个数：");
    scanf("%f %d", &amount, &number);
    printf("每个红包为 %.2f 元, %d 个红包总金额共 %.2f 元\n", 
        amount/number, number, amount);
    return;
}

void fortunePacket(void)
{
    float amount;
    int number;
    printf("请输入总金额（元）和个数：");
    scanf("%f %d", &amount, &number);
    printf("%.2f 元分 %d 个红包, ", amount, number);

    srand((unsigned)time(NULL));
    
    float result[number];
    double total_weight = 0.0;
    double weights[number];
    
    // 生成权重
    for(int i = 0; i < number; i++) {
        weights[i] = (double)(rand() % 100 + 1);
        total_weight += weights[i];
    }
    
    // 按权重分配金额
    float distributed = 0.0;
    for(int i = 0; i < number - 1; i++) {
        result[i] = (weights[i] / total_weight) * amount;
        
        // 确保每个红包至少0.01元，且剩余金额足够分配
        if (result[i] < 0.01f) {
            result[i] = 0.01f;
        }
        if (distributed + result[i] > amount - 0.01f * (number - i - 1)) {
            result[i] = amount - distributed - 0.01f * (number - i - 1);
        }
        
        distributed += result[i];
        printf("第 %d 个红包 %.2f 元, ", i+1, result[i]);
    }
    
    // 最后一个红包
    result[number-1] = amount - distributed;
    if (result[number-1] < 0.01f) {
        // 如果最后一个红包太小，需要调整前面的红包
        result[number-1] = 0.01f;
        // 从前面最大的红包中扣除差额
        float diff = 0.01f - result[number-1];
        for(int i = 0; i < number - 1; i++) {
            if (result[i] > diff + 0.01f) {
                result[i] -= diff;
                break;
            }
        }
    }
    printf("第 %d 个红包 %.2f 元\n", number, result[number-1]);

    // 验证总和
    float check_sum = 0.0;
    for(int i = 0; i < number; i++) {
        check_sum += result[i];
    }
    printf("验证总和: %.2f 元\n", check_sum);

    return;
}

void wordPacket(void)
{
    float amount;
    char words[100];
    printf("请输入总金额（元）：");
    scanf("%f", &amount);
    printf("请输入口令：");
    scanf("%s", words);
    printf("红包金额为 %.2f 元, 口令是%s\n", amount, words);
    return;
}

void complete(void)
{
    printf("红包发送成功！\n");
}

int main(void)
{
    int choice;
    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            commonPacket();
            complete();
            break;
        case 2:
            fortunePacket();
            complete();
            break;
        case 3:
            wordPacket();
            complete();
            break;
        case 0:
            printf("谢谢，再见！\n");
            break;
        default:
            printf("请输入正确的红包类型序号！\n");
            break;
        }
    } 
    while (choice);

    return 0;
}