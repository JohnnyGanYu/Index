#include <stdio.h>

int main(void)
{
    float price;
    int amount;
    float total;
    printf("��������Ʒ�ĵ��ۺ�����: \n");
    scanf("%d,%f", &amount, &price);
    if (!(price < 0) && !(amount < 0))
    {
        total = price * amount;
        printf("ԭ�ܼ�: %.2f\n", total);
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
        printf("�ۿۺ��ܼ�: %.2f\n"
               "�ͻ��Ѿ����ܵ��Ż�: %.2f\n", total, price * amount - total);
               return 0;
    }
    printf("��������Ʒ����ȷ���ۺ�������\n");
    return 0;
}
