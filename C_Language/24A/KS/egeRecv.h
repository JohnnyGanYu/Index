////egeRecv.h
#include <graphics.h>
#include <stdio.h>
#include <string.h>
//EGE指令→从文件中读取并执行
char *RCVfn;    //EGE指令文件名
FILE *RCVfp;    //EGE指令指针
char RCVcmd[80];    //EGE指令行
char RCVps[6][40];  //EGE指令及参数
int RCVpd[6];       //EGE指令整数参数
int WinW, WinH;
FILE *RCVinit(char *fn)
{ //打开EGE图形指令文件
    if (fn==NULL)
        fn = "RCVcmd.txt";
    RCVfn = fn;
    RCVfp = fopen(fn, "r");
    if (RCVfp==NULL)
        printf("EGE指令文件打开失败（%s）\n", fn);
    return RCVfp;
}
void RCVend(void)
{ //关闭EGE图形指令文件
    fclose(RCVfp);
    RCVfp = NULL;
}
void RCVinitgraph(void)
{ //接收EGE初始化指令
    initgraph(RCVpd[1], RCVpd[2]);
    WinW = RCVpd[1];
    WinH = RCVpd[2];
    setlinestyle(SOLID_LINE, 0, 1, NULL);   //单线
}
void RCVsetbkcolor(void)
{ //设置背景颜色
    setbkcolor(RCVpd[1]);
}
void RCVsetcolor(void)
{ //设置颜色
    setcolor(RCVpd[1]);
}
void RCVcircle(void)
{ //绘制中心圆，圆心坐标、半径
    circle(RCVpd[1], RCVpd[2], RCVpd[3]);
}
void RCVline(void)
{ //绘制直线，坐标1至坐标2
    line(RCVpd[1], RCVpd[2], RCVpd[3], RCVpd[4]);
}
void RCVsetfillcolor(void)
{ //设置填充颜色
    setfillcolor(RCVpd[1]);
}
void RCVfloodfillsurface(void)
{ //颜色填充，坐标\原颜色
    floodfillsurface(RCVpd[1], RCVpd[2], RCVpd[3]);
}
void RCVfill(void)
{ //颜色填充，坐标\原颜色→新颜色
    setfillcolor(RCVpd[4]);
    floodfillsurface(RCVpd[1], RCVpd[2], RCVpd[3]);
}
void RCVsetlinewidth(void)
{ //设置线条宽度
    setlinewidth(RCVpd[1]);
}
void RCVsetfont(void)
{ //设置字体，字体高度、字体名称、角度
    setfont(RCVpd[1], 0, RCVps[3], RCVpd[2]
            ,0,0,false,false,false);
}
void RCVouttextxy(void)
{ //输出文本，文本坐标、文本内容
    outtextxy(RCVpd[1], RCVpd[2], RCVps[3]);
}
void RCVsaveimg(void)
{ //保存图像至png文件
    PIMAGE img;             //图像对象
    img = newimage();       //建立新的图像对象
    getimage(img, 0, 0, WinW, WinH); //选取整个窗口到图像对象中
    savepng(img, RCVps[1], 0);  //保存图像对象中的图像到文件中
}
void RCVfillellipse(void)
{ //椭圆填充
    setfillstyle(SOLID_FILL, LIGHTGRAY);    //填充颜色
    fillellipse(RCVpd[1], RCVpd[2], RCVpd[3], RCVpd[4]);
}
void RCVarc(void)
{ //绘制弧线，圆心(x,y)半径r，从角度deg1画弧线至角度deg2。水平右向为0度
    arc(RCVpd[1], RCVpd[2], RCVpd[3], RCVpd[4], RCVpd[5]);
}
char *RCVcmdlst[] = {"initgraph", "setbkcolor", "setcolor", 
            "circle", "line",
            "setfillcolor","floodfillsurface","fill",
            "setlinewidth","setfont","outtextxy","saveimg","fillellipse","arc",
            NULL};
void (*RCVfunlst[])(void) = {RCVinitgraph,RCVsetbkcolor,RCVsetcolor,
            RCVcircle,RCVline,
            RCVsetfillcolor,RCVfloodfillsurface,RCVfill,
            RCVsetlinewidth,RCVsetfont,RCVouttextxy,RCVsaveimg,RCVfillellipse,RCVarc};
void RCVrun(void)
{
    int i;
    if (RCVfp==NULL)
        return;
    while (!feof(RCVfp))
    {
        RCVcmd[0] = '\0';
        fgets(RCVcmd, 80, RCVfp);
        sscanf(RCVcmd, "%s%s%s%s%s%s", RCVps[0],
                RCVps[1], RCVps[2], RCVps[3], RCVps[4], RCVps[5]);
        for (i=0; i<6; i++)
        {
            RCVpd[i] = 0;
            sscanf(RCVps[i], "%d", &RCVpd[i]);
        }
        for (i=0; RCVcmdlst[i]!=NULL; i++)
        {
            if (stricmp(RCVps[0],RCVcmdlst[i])==0)
            {
                RCVfunlst[i]();
                break;
            }
        }
    }
}
