#include <stdio.h>
// ����ѧ���ṹ��
struct Student {
    char name[20];  // ѧ������
    float score[3]; // 3�ſγ̳ɼ�
};

// ���㵥��ѧ����ƽ����
float calc_avg(struct Student s) {
    float sum = 0.0, avg;
    int i;
    // ѭ���ۼ�3�ſγ̳ɼ�
    for (i = 0; i < 3; i++) { // ��1����ȫѭ������
        sum += s.score[i]; // ��2����ȫ�ۼӵĳɼ���Ա
    }
    // ����ƽ���֣�3�ſγ̣�
    avg = sum/3; // ��3����ȫƽ���ּ��㹫ʽ
    return avg;
}

int main(void) {
    struct Student stu = {"Zhang San", {85.5, 92.0, 78.5}};
    float average;
    // ����calc_avg��������ƽ����
    average = calc_avg(stu); // ��4����ȫ�����������
    // ������������1λС����
    printf("%s��ƽ���֣�%.1f\n", stu.name, average);
    return 0;
}
