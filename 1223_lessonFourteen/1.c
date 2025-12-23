#include <stdio.h>

int main(void)
{
    struct student
    {
        char num[10];
        char name[20];
        char xb;
        int age;
        float score[3];
    };
    struct student t2, st[50];
    struct student t1 = {"2511111", "zhangsan", 'W', 18, 98, 78.5, 99};

    printf("年龄 %d\n", t1.age);
    printf("第二个成绩 %.2f\n", t1.score[1]);


    return 0;
}