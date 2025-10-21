#include <stdio.h>

float calculateBMI(float m, float h)
{
    float bmi = m / (h*h);
    return bmi;
}
char* getBMIcategory(float BMI)
{
    char *cat;
    if (BMI < 18)
    {
        cat = "较轻";
    }
    else if (BMI < 25)
    {
        cat = "正常";
    }
    else if (BMI < 28)
    {
        cat = "超重";
    }
    else
    {
        cat = "肥胖";
    }
    return cat;
}

int main(void)
{
    float m;    //weight
    float h;    //height
    printf("请输入体重(kg):");
    scanf("%f", &m);
    while (getchar() != '\n');
    printf("请输入身高(m):");
    scanf("%f", &h);
    float bmi = calculateBMI(m, h);
    printf("您的BMI为: %.2f\n", bmi);
    printf("您的等级为: %s\n", getBMIcategory(bmi));

    return 0;
}
