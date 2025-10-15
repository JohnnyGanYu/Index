//egeRun，读取EGE指令文件，绘制图像
#include <stdio.h>
#include <math.h>
#include "egeRecv.h"

//GUIDE | 设置编译选项（适用于EGE19.01）
//  -l graphics -l gdi32 -l imm32 -l msimg32 -l ole32 -l oleaut32 -l winmm -l uuid

int main(int argc, char *argv[])
{ //主函数
    char *fn;
    if (argc<2)
        fn = "egeRun.txt";          //"tj02.txt"
    else
        fn = argv[1];
    printf("egeRun.Begin(%s)\n", fn); //文本主窗上显示信息
    RCVinit(fn);
    RCVrun();
    RCVend();
    //绘制完成
    getch();                    //EGE窗口绘制后，按任意键继续
    closegraph();               //关闭EGE窗口
    printf("egeRun.End\n");     //在文本主窗口上显示信息
    return 0;
}
