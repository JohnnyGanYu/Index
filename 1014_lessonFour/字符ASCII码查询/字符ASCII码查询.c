// �����⣺�ַ�ASCII���ѯ
// ���������ַ��������ASCII��
#include <stdio.h>      // ��׼���������

void display_ascii_code(char input_char)
{   // ����display_ascii_code����ʾ�ַ���ASCII��
    int ascii_value;    // ASCII����ֵ

    ascii_value = (int)input_char;  // �ַ�ת��ΪASCII��

    printf("�ַ� '%c' ��ASCII����Ϣ:\n", input_char);
    printf("ʮ����: %d\n", ascii_value);
    printf("�˽���: %o\n", ascii_value);
    printf("ʮ������: %X\n", ascii_value);
}   // ����display_ascii_code

int main(void)
{   // ������
    char input_character;   // �洢������ַ�

    // �Ӽ��̶�ȡ�ַ�
    printf("������һ���ַ�: ");
    scanf("%c", &input_character);

    // ����ASCII����ʾ����
    display_ascii_code(input_character);

    return 0;
}   // ������

//������һ���ַ�: A
//�ַ� 'A' ��ASCII����Ϣ:
//ʮ����: 65
//�˽���: 101
//ʮ������: 41
