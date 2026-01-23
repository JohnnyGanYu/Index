#include <stdio.h>

int main()
{
    int chinese;
    int maths;
    int english;
    int totalScore;
    float averageScore ;
    chinese = 95;
    maths = 86 ;
    english = 97;
    //totalScore = chinese + maths + english ;
    averageScore = (chinese + maths + english)/3;
    printf("%.3f\n",averageScore);
    //printf("你的三门总分是%d\n你的平均成绩是%.2f\n",totalScore,averageScore);
    return 0;
}