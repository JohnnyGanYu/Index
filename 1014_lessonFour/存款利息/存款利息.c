#include <stdio.h>
#include <math.h>

int main() {
    double m; // ������Ԫ��
    int n;  // ����
    double rate = 0.17 / 100;  // ������ 0.17%
    double total;  // ��Ϣ�ܶ�

    // ���뱾�������
    printf("�����뱾��m����������n:");
    scanf("%lf %d", &m, &n);

    // ���㸴����Ϣ�ܶ�
    total = m * pow(1 + rate, n);

    // ������������2λС��
    printf("%d�º����Ϣ�ͱ���Ϊ: %.2f��Ԫ\n", n, total);

    return 0;

}
