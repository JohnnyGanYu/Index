//tj03org.c，绘制心形线
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "egeSend.h"

#define WinW 1024       //窗口宽度，像素
#define WinH 768        //窗口高度，像素
#define X0 512          //中心圆圆心X坐标
#define Y0 384          //中心圆圆心Y坐标
#define R  300          //中心圆半径，R
#define K  30           //坐标轴长度缩减
#define PI 3.14159265   //圆周率

struct point
{ //声明“点”结构体
    float  x;       //点的X坐标
    float  y;       //点的Y坐标
};
void drawHeartLine(void)
{ //绘制心形线
    struct point xy[361];  //心形线上361个点，相邻点连成线段
    float dQ; //连接心形线的点与原点，该连线与y轴夹角为dQ，dQ从0至360度
    float rQ; //该连线的长度为rQ，rQ从R减至0再增至R
    int  i;
    //极坐标系，设垂直向下方向为0度，逆时针旋转360度
    for (i=0; i<=360; i++)
    { //360度循环，前180度生成心形线右侧各点坐标，后180度生成左侧各点坐标
        dQ = PI*i/180;          //角度转换为弧度
        rQ = R*cos(dQ/2);       //极坐标长度使用余弦递减
        if (rQ<0)
            rQ = -rQ;           //取长度为正值
        xy[i].x = rQ*sin(dQ) + 0.5;   //极坐标转换为X坐标值
        xy[i].y = rQ*cos(dQ) + 0.5;   //极坐标转换为Y坐标值
    }
    for (i=0; i<360; i++)  //绘制360个线段，相邻2点连成线段
        SNDline(X0+xy[i].x, Y0+xy[i].y, X0+xy[i+1].x, Y0+xy[i+1].y);
}

int main(void)
{ //主函数
    printf("tj03org:Begin\n");     //在文本主窗口上显示程序信息
    //EGE窗口初始设置
    SNDinit("tj03org.txt");
    SNDinitgraph(WinW, WinH);       //初始化EGE窗口，大小WinW*WinH
    SNDsetbkcolor(WHITE);           //设置窗口背景颜色=白色
    //中心圆与心形线
    SNDsetcolor(RED|BLUE);          //设置绘图颜色，红色+蓝色=紫色
    SNDcircle(X0, Y0, R);           //绘制中心圆，圆心坐标为(X0,Y0)，半径为R
    drawHeartLine();
    SNDfill(X0, Y0+R/2, WHITE, RED);//心形线以内原白色填充为红色
    //坐标轴
    SNDsetcolor(BLACK);           //设置颜色=黑色
    SNDline(K/2,Y0,WinW-K,Y0);        //横坐标轴
    SNDline(WinW-K-8,Y0+8,WinW-K,Y0);   //横坐标轴下半箭头
    SNDline(WinW-K-8,Y0-8,WinW-K,Y0);   //横坐标轴上半箭头
    SNDline(X0,K/2,X0,WinH-K);        //纵坐标轴
    SNDline(X0+8,WinH-K-8,X0,WinH-K);   //纵坐标轴右半箭头
    SNDline(X0-8,WinH-K-8,X0,WinH-K);   //纵坐标轴左半箭头
    //文字
    SNDsetfont(24,"宋体",0);          //字体字号角度
    SNDouttextxy(2, 2, "tj03org");      //程序名称
    SNDouttextxy(WinW-K+2,Y0+2,"X");    //横轴标记
    SNDouttextxy(X0+2,WinH-K+2,"Y");    //纵轴标记
    //保存图像
    SNDsaveimg("tj03org.png");
    //绘制发送完成
    SNDend();
    //调用外部程序绘制图像
    system("egeRun tj03org.txt");
    printf("tj03org:end\n");
    return 0;
}
