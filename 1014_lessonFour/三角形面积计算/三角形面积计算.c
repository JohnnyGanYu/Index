// �ڶ��⣺�������������
// ���������ε�3���ߣ����������ε����
#include <stdio.h>      // ��׼���������
#include <math.h>       // ��ѧ������

double calculate_triangle_area(double side_a, double side_b, double side_c)
{   // ����calculate_triangle_area���������������
    double semi_perimeter;  // ���ܳ�
    double triangle_area;   // ���������

    // ������ܳ�
    semi_perimeter = (side_a + side_b + side_c) / 2.0;

    // ʹ�ú��׹�ʽ�������
    triangle_area = sqrt(semi_perimeter *
                        (semi_perimeter - side_a) *
                        (semi_perimeter - side_b) *
                        (semi_perimeter - side_c));

    return triangle_area;
}   // ����calculate_triangle_area

int main(void)
{   // ������
    double side_length_a;   // �洢�����α߳�a
    double side_length_b;   // �洢�����α߳�b
    double side_length_c;   // �洢�����α߳�c
    double area_result;     // �洢����������

    // �Ӽ��̶�ȡ�����߳�
    printf("�����������ε������߳����ÿո�ָ���: ");
    scanf("%lf %lf %lf", &side_length_a, &side_length_b, &side_length_c);

    // ����������㺯��
    area_result = calculate_triangle_area(side_length_a, side_length_b, side_length_c);

    // ���������
    printf("���������������ɣ�\n");
    printf("�����α߳�: a=%.2f, b=%.2f, c=%.2f\n",
           side_length_a, side_length_b, side_length_c);
    printf("���������: %.2f\n", area_result);

    return 0;
}   // ������

//�����������ε������߳����ÿո�ָ���: 3 4 5
//���������������ɣ�
//�����α߳�: a=3.00, b=4.00, c=5.00
//���������: 6.00
