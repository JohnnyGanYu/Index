//egeRun����ȡEGEָ���ļ�������ͼ��
#include <stdio.h>
#include <math.h>
#include "egeRecv.h"

//GUIDE | ���ñ���ѡ�������EGE19.01��
//  -l graphics -l gdi32 -l imm32 -l msimg32 -l ole32 -l oleaut32 -l winmm -l uuid

int main(int argc, char *argv[])
{ //������
    char *fn;
    if (argc<2)
        fn = "egeRun.txt";          //"tj02.txt"
    else
        fn = argv[1];
    printf("egeRun.Begin(%s)\n", fn); //�ı���������ʾ��Ϣ
    RCVinit(fn);
    RCVrun();
    RCVend();
    //�������
    getch();                    //EGE���ڻ��ƺ󣬰����������
    closegraph();               //�ر�EGE����
    printf("egeRun.End\n");     //���ı�����������ʾ��Ϣ
    return 0;
}
