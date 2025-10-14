// �����⣺�ļ��༭
// �ļ��༭.c�� 2025��10��14�գ��Ӽ��̶�ȡ���֣����浽t1.txt����ȡ���100�浽t2.txt������������
#include <stdio.h>      // ��׼���������
#include <stdlib.h>     // ��׼�⺯��

void write_to_file(const char *filename, int value)
{   // ����write_to_file��д�����ֵ��ļ�
    FILE *file_pointer = fopen(filename, "w");

    if (file_pointer == NULL)
    {
        printf("����%s�ļ���ʧ��\n", filename);
        exit(1);
    }

    fprintf(file_pointer, "%d", value);
    fclose(file_pointer);
}   // ����write_to_file

int read_from_file(const char *filename)
{   // ����read_from_file�����ļ���ȡ���֣����ض�ȡ��������ֵ
    FILE *file_pointer = fopen(filename, "r");
    int read_value;

    if (file_pointer == NULL)
    {
        printf("����%s�ļ���ʧ��\n", filename);
        exit(1);
    }

    fscanf(file_pointer, "%d", &read_value);
    fclose(file_pointer);

    return read_value;
}   // ����read_from_file

int main(void)
{   // ������
    int input_value;    // �洢��������ֵ
    int read_value;     // �洢���ļ���ȡ��ֵ
    int result_value;   // �洢���ս��ֵ

    // �Ӽ��̶�ȡ����
    printf("������һ������: ");
    scanf("%d", &input_value);

    // ���浽t1.txt
    write_to_file("t1.txt", input_value);

    // ��t1.txt��ȡ����
    read_value = read_from_file("t1.txt");

    // �����100��Ľ��
    result_value = read_value + 100;

    // ��������t2.txt
    write_to_file("t2.txt", result_value);

    // ��t2.txt��ȡ��������
    result_value = read_from_file("t2.txt");

    printf("������ɣ�\n");
    printf("���ս����t2.txt���ݣ�: %d\n", result_value);
    printf("�������̣���������(%d) �� t1.txt(%d) �� t2.txt(%d)\n",
           input_value, read_value, result_value);

    return 0;
}   // ������

//����ʾ����
//������һ������: 50
//������ɣ�
//���ս����t2.txt���ݣ�: 150
//�������̣���������(50) -> t1.txt(50) -> t2.txt(150)
