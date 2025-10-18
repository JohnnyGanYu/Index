#include <stdio.h>
// 定义学生结构体
struct Student {
    char name[20];  // 学生姓名
    float score[3]; // 3门课程成绩
};

// 计算单个学生的平均分
float calc_avg(struct Student s) {
    float sum = 0.0, avg;
    int i;
    // 循环累加3门课程成绩
    for (i = 0; i < 3; i++) { // 空1：补全循环条件
        sum += s.score[i]; // 空2：补全累加的成绩成员
    }
    // 计算平均分（3门课程）
    avg = sum/3; // 空3：补全平均分计算公式
    return avg;
}

int main(void) {
    struct Student stu = {"Zhang San", {85.5, 92.0, 78.5}};
    float average;
    // 调用calc_avg函数计算平均分
    average = calc_avg(stu); // 空4：补全函数调用语句
    // 输出结果（保留1位小数）
    printf("%s的平均分：%.1f\n", stu.name, average);
    return 0;
}
