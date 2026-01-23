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
    int i, j;
    struct student t2, st[50] = {"25345", "lisan", 'M', 18, 98, 78.5, 99};
    struct student t3, t1 = {"2511111", "zhangsan", 'W', 18, 98, 78.5, 99};
    t2=t1;

    printf("年龄 %d\n", t1.age);
    printf("第二个成绩 %.2f\n", t1.score[1]);
    printf("性别 %c\n", t1.xb);
    printf("姓名 %s\n", t1.name);
    puts(t2.name);

    printf("数组中的性别 %c\n", st[0].xb);
    puts(st[0].name);
    
    printf("输入t3变量中的年龄--成员");
    scanf("%d", &t3.age);
    printf("3:age%d\n", t3.age);

    for (i = 0; i < 3; i++)
    {
        scanf("%f", &t3.score[i]);
    }
    printf("验证三个成绩\n");
    for (i = 0; i < 3; i++)
    {
        printf("%5.2f", t3.score[i]);
    }
    printf("\n数组中: ");
    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%f", &st[i].score[j]);
        }
    }

    return 0;
}