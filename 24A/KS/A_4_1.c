// A_4_1.c, 2025/10/15, ���ݷ���������ҵ�ȼ�
#include <stdio.h>  // ��׼���������

int main(void)
{// ��������������, ���ݷ���������ҵ�ȼ�
    double score;   // �洢�����������ҵ�ɼ�
    const char *output; // �洢��Ҫ�������ҵ�ȼ�

    // �Ӽ����������ҵ�ɼ�
    printf("��������ҵ�÷�:\n");
    scanf("%lf", &score);

    //��֧������ҵ�ȼ�
    if (score < 0 || score > 100)
        {
            output = "�������";
        }
    else if (score < 70)
        {
            output = "*";
        }
    else if (score < 80)
        {
            output = "**\n";
        }
    else if (score < 90)
        {
            output = "***";
        }
    else
        {
            output = "****";
        }

    //�����ҵ�ȼ�
    printf("%s\n", output);

    return 0;
}   // ������
