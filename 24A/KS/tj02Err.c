//tj02.c，使用图形发送系列函数，绘制坐标轴与圆
#include <stdio.h>
#include <stdlib.h>
#include "egeSend.h"

#define WinW 1024       //窗口宽度，像素
#define WinH 768        //窗口高度，像素
#define X0 512          //中心圆圆心X坐标，X0
#define Y0 384          //中心圆圆心Y坐标，Y0
#define R =300          //中心圆半径，R
#define K  30           //坐标轴长度缩减

int main(void)
{ //主函数
    printf("tj02:Begin\n")      //在文本主窗口上显示信息
    //EGE窗口初始设置
    SNDinit("tj02.txt");
    SNDinitgraph(WinW, WinH);   //初始化EGE窗口，大小WinW*WinH
    SNDsetbkcolor(WHITE);       //设置窗口背景颜色=白色
    //坐标轴
    SNDsetcolor(RED);           //设置颜色=红色，横坐标
    SNDline(K/2,K,WinW-K,WinH-K);   //横坐标轴
    SNDline(WinW-K-8,K+8,WinW-K,K);   //横坐标下半箭头
    SNDline(WinW-K-8,K-8,WinW-K,K);   //横坐标上半箭头
    SNDsetcolor(BLUE);          //设置颜色=蓝色，纵坐标
    SNDline(K,K/2,K,WinH-K);        //纵坐标轴
    SNDline(K+8,WinH-K-8,K,WinH-K);   //纵坐标右半箭头
    SNDline(K-8,WinH-K-8,K,WinH-K);   //纵坐标左半箭头
    //文字
    SNDsetcolor(BLACK);             //设置绘图颜色
    SNDsetfont(24,"宋体",0);        //字体字号角度
    SNDouttextxy(K+2,K+2,"(30,30)");    //坐标原点
    SNDouttextxy(WinW-K+2,K+2,"X");     //横轴标记
    SNDouttextxy(K+2,WinH-K+2,"Y");     //纵轴标记
    //中心圆
    SNDsetcolor(RED|BLUE);          //设置绘图颜色，红色+蓝色=紫色
    SNDcircle(X0,Y0,R);             //绘制中心圆，圆心坐标为(X0,Y0)，半径为R
    SNDline(X0-R,Y0,X0+R,Y0);       //中心圆的中央横直线
    SNDfill(X0,Y0-R/2,WHITE,RED);   //上半圆填充为红色
    SNDfill(X0,Y0+R/2,WHITE,BLUE);  //下半圆填充为蓝色
    //保存图像
    SNDsaveimg("tj02.png");
    //绘制发送完成
    SNDend();
    //调用外部程序绘制图像
    system("egeRun tj02.txt");
    printf("tj02:end\n");
    return 0;
}
