#include <stdio.h>


int main(void)
{
    int score;

    printf("请输入您的分数: ");
    scanf("%d", &score);


    if (score >= 0 && score <= 100)
    {
        printf("您的等第是: ");
        switch(score / 10)
        {
        case 10:
        case 9:
            printf("A\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 7:
            printf("C\n");
            break;
        case 6:
            printf("D\n");
            break;
        default:
            printf("E\n");
            break;
        }
    }
    else
    {
        printf("请输入正确的分数,");
    }
    printf("再见!");
    return 0;
}
