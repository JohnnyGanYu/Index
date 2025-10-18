#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    float total;
};

// �����ܷ���ߵ�ѧ��
struct Student find_max(struct Student arr[], int n) {
    struct Student max_stu = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i].total > max_stu.total) { // ��1����ȫ�ֱܷȽ�����
            max_stu = arr[i];
        }
    }
    return max_stu;
}

int main(void) {
    struct Student stus[3], max_stu;
    FILE *fp1, *fp2;
    int i;

    // ��score.txt�ļ�����ģʽ��
    fp1 = fopen("score.txt", "r"); // ��2����ȫ�ļ���ģʽ
    if (fp1 == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
        return 1;
    }

    // ���ļ���ȡ3��ѧ����Ϣ
    for (i = 0; i < 3; i++) {
        fscanf(fp1, "%s %f", stus[i].name, &stus[i].total); // ��3����ȫ��ʽ���Ʒ�
    }
    fclose(fp1);

    // �����ܷ���ߵ�ѧ��
    max_stu = find_max(stus, 3); // ��4����ȫ�����������ṹ����������

    // ��max_score.txt�ļ���дģʽ��
    fp2 = fopen("C:\\KS\\max_score.txt", "w");
    // д����߳ɼ�ѧ����Ϣ
    fprintf(fp2, "��߷�ѧ����%s �ܷ֣�%.1f\n", max_stu.name, max_stu.total); // ��5����ȫд��ĳ�Ա����
    fclose(fp2);

    // ����̨������
    printf("��߷�ѧ����%s �ܷ֣�%.1f\n", max_stu.name, max_stu.total);
    return 0;
}
