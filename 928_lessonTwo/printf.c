#include <stdio.h>

int main()
{
    int length1;
    int width1;
    length1 = 10;
    width1 = 12;
    printf("长和宽分别为10和12的长方形面积为%d\n",length1 * width1);
    float length2;
    float width2;
    length2 = 5.53;
    width2 = 7.96;
    printf("长和宽分别为5.53和7.96的长方形面积为%f\n",length2 * width2);
    char character;
    character = 'Y';
    printf("%c\n",character);
    char name[] = "USST";
    printf("%s\n", name);
    float  length;
    printf("length");
    scanf("%f",&length);
    float  width;
    printf("width");
    scanf("%f",&width);
    int zone;
    zone =length * width/1;
    printf("%d\n",zone);
    return 0;
}