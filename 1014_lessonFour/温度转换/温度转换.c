// ��һ�⣺�¶�ת��
// ���������¶ȣ����Ӧ�Ļ����¶�
#include <stdio.h>      // ��׼���������

double celsius_to_fahrenheit(double celsius_temp)
{   // ����celsius_to_fahrenheit���������¶�ת��Ϊ�����¶�
    double fahrenheit_temp;

    fahrenheit_temp = (9.0 / 5.0) * celsius_temp + 32;

    return fahrenheit_temp;
}   // ����celsius_to_fahrenheit

int main(void)
{   // ������
    double input_celsius;      // �洢����������¶�
    double result_fahrenheit;  // �洢ת����Ļ����¶�

    // �Ӽ��̶�ȡ�����¶�
    printf("�����������¶�: ");
    scanf("%lf", &input_celsius);

    // �����¶�ת������
    result_fahrenheit = celsius_to_fahrenheit(input_celsius);

    // ���ת�����
    printf("�¶�ת����ɣ�\n");
    printf("�����¶�: %.2f��C\n", input_celsius);
    printf("�����¶�: %.2f��F\n", result_fahrenheit);
    printf("ת����ʽ: F = (9/5) �� %.2f + 32 = %.2f\n",
           input_celsius, result_fahrenheit);

    return 0;
}   // ������

//�����������¶�: 25
//�¶�ת����ɣ�
//�����¶�: 25.00��C
//�����¶�: 77.00��F
//ת����ʽ: F = (9/5) �� 25.00 + 32 = 77.00
