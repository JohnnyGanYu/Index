#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    float total;
};

// 查找总分最高的学生
struct Student find_max(struct Student arr[], int n) {
    struct Student max_stu = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i].total > max_stu.total) { // 空1：补全总分比较条件
            max_stu = arr[i];
        }
    }
    return max_stu;
}

int main(void) {
    struct Student stus[3], max_stu;
    FILE *fp1, *fp2;
    int i;

    // 打开score.txt文件（读模式）
    fp1 = fopen("score.txt", "r"); // 空2：补全文件打开模式
    if (fp1 == NULL) {
        printf("文件打开失败！\n");
        return 1;
    }

    // 从文件读取3个学生信息
    for (i = 0; i < 3; i++) {
        fscanf(fp1, "%s %f", stus[i].name, &stus[i].total); // 空3：补全格式控制符
    }
    fclose(fp1);

    // 查找总分最高的学生
    max_stu = find_max(stus, 3); // 空4：补全函数参数（结构体数组名）

    // 打开max_score.txt文件（写模式）
    fp2 = fopen("C:\\KS\\max_score.txt", "w");
    // 写入最高成绩学生信息
    fprintf(fp2, "最高分学生：%s 总分：%.1f\n", max_stu.name, max_stu.total); // 空5：补全写入的成员变量
    fclose(fp2);

    // 控制台输出结果
    printf("最高分学生：%s 总分：%.1f\n", max_stu.name, max_stu.total);
    return 0;
}
