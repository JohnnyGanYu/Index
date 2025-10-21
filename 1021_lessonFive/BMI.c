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
        cat = "����";
    }
    else if (BMI < 25)
    {
        cat = "����";
    }
    else if (BMI < 28)
    {
        cat = "����";
    }
    else
    {
        cat = "����";
    }
    return cat;
}

int main(void)
{
    float m;    //weight
    float h;    //height
    printf("����������(kg):");
    scanf("%f", &m);
    while (getchar() != '\n');
    printf("���������(m):");
    scanf("%f", &h);
    float bmi = calculateBMI(m, h);
    printf("����BMIΪ: %.2f\n", bmi);
    printf("���ĵȼ�Ϊ: %s\n", getBMIcategory(bmi));

    return 0;
}
