#include <stdio.h>
// ����1���ṹ�嶨��ȱ�ٴ����űպ�
struct Student {
    char name[20];
    int score[3];
    int total;
} ;  //���}

int main(void) {
    struct Student stus[5];
    int i, j;
    // ����5��ѧ����Ϣ
    for (i = 0; i < 5; i++) {
        printf("�����%d��ѧ�������� 3�ųɼ�����", i+1);
        scanf("%s %d %d %d", &stus[i].name, &stus[i].score[0], &stus[i].score[1], &stus[i].score[2]);   //���&
        stus[i].total = 0;
        // �����ܷ֣�ѭ���ۼ�3�ųɼ���
        for (j = 0; j < 3; j++) { // �޸�j <= 3 Ϊj < 3
            stus[i].total += stus[i].score[j];
        }
    }
    // ������
    for (i = 0; i < 5; i++) {
        printf("%s��%d\n", stus[i].name, stus[i].total); //�޸�.0f��d
    }
    return 0;
}
