#include <stdio.h>


int main(void)
{
    int score;

    printf("���������ķ���: ");
    scanf("%d", &score);


    if (score >= 0 && score <= 100)
    {
        printf("���ĵȵ���: ");
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
        printf("��������ȷ�ķ���,");
    }
    printf("�ټ�!");
    return 0;
}
