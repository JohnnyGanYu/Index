#include <stdio.h>
#include <stdlib.h>

// ��������
void write_to_file(const char *filename, int value);
int read_from_file(const char *filename);

int main()
{
    int input_value;

    // �Ӽ��̶�ȡ����
    printf("������һ������: ");
    scanf("%d", &input_value);

    // ���浽t1.txt
    write_to_file("t1.txt", input_value);

    // ��t1.txt��ȡ����
    int read_value = read_from_file("t1.txt");

    // ��100�󱣴浽t2.txt
    write_to_file("t2.txt", read_value + 100);

    printf("������ɣ�\n");
    printf("���̣���������(%d) -> t1.txt(%d) -> t2.txt(%d)\n",
           input_value, read_value, read_value + 100);

    return 0;
}

// ������д�����ֵ��ļ�
void write_to_file(const char *filename, int value)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("%s�ļ���ʧ��\n", filename);
        exit(1);
    }
    fprintf(fp, "%d", value);
    fclose(fp);
}

// ���������ļ���ȡ����
int read_from_file(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s�ļ���ʧ��\n", filename);
        exit(1);
    }
    int value;
    fscanf(fp, "%d", &value);
    fclose(fp);
    return value;
}
