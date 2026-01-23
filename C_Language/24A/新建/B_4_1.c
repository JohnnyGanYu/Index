#include <stdio.h>

int main(void)
{
    printf("请输入一个长度为2的正整数：");
    char building = getchar();
    char category = getchar();
    char *out;
    switch (building)
    {
    case '1':
        switch (category)
        {
        case '1':
            out = "A楼干垃圾\n";
            break;
        case '2':
            out = "A楼湿垃圾\n";
            break;
        case '3':
            out = "A楼可回收垃圾\n";
            break;
        case '4':
            out = "A楼有害垃圾\n";
            break;
        default:
            out = "输入的整数不是有效标签！\n";
        }
        break;
        case '2':
        switch (category)
        {
        case '1':
            out = "B楼干垃圾\n";
            break;
        case '2':
            out = "B楼湿垃圾\n";
            break;
        case '3':
            out = "B楼可回收垃圾\n";
            break;
        case '4':
            out = "B楼有害垃圾\n";
            break;
        default:
            out = "输入的整数不是有效标签！\n";
        }
        break;
    default:
        out = "输入的整数不是有效标签！\n";
    }
    printf("%s", out);
    return 0;
}
