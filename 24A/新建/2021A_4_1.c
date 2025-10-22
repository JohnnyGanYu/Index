#include <stdio.h>

int main(void)
{
    float price;
    int amount;
    float total;
    printf("请输入商品的单价和数量: \n");
    scanf("%d,%f", &amount, &price);
    if (!(price < 0) && !(amount < 0))
    {
        total = price * amount;
        printf("原总价: %.2f\n", total);
        switch (amount)
        {
        case 0:
        case 1:
            break;
        case 2:
            total *= 0.85;
            break;
        default:
            total *= 0.7;
            break;
        }
        total = ((int)total / 300) * 270 + (int)total % 300 + total - (int)total;
        printf("折扣后总价: %.2f\n"
               "客户已经享受的优惠: %.2f\n", total, price * amount - total);
               return 0;
    }
    printf("请输入商品的正确单价和数量！\n");
    return 0;
}
