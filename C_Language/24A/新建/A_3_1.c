#include <stdio.h>
// 错误1：结构体定义缺少大括号闭合
struct Student {
    char name[20];
    int score[3];
    int total;
} ;  //添加}

int main(void) {
    struct Student stus[5];
    int i, j;
    // 输入5个学生信息
    for (i = 0; i < 5; i++) {
        printf("输入第%d个学生（姓名 3门成绩）：", i+1);
        scanf("%s %d %d %d", &stus[i].name, &stus[i].score[0], &stus[i].score[1], &stus[i].score[2]);   //添加&
        stus[i].total = 0;
        // 计算总分（循环累加3门成绩）
        for (j = 0; j < 3; j++) { // 修改j <= 3 为j < 3
            stus[i].total += stus[i].score[j];
        }
    }
    // 输出结果
    for (i = 0; i < 5; i++) {
        printf("%s：%d\n", stus[i].name, stus[i].total); //修改.0f到d
    }
    return 0;
}
