////egeSend.h
//EGE颜色定义，截取自EGE库
#define EGERGB(r, g, b)         ( ((r)<<16) | ((g)<<8) | (b))
enum COLORS {
    BLACK           = 0,                        //黑色
    BLUE            = EGERGB(0, 0, 0xA8),       //蓝色
    GREEN           = EGERGB(0, 0xA8, 0),       //绿色
    CYAN            = EGERGB(0, 0xA8, 0xA8),    //青色
    RED             = EGERGB(0xA8, 0, 0),       //红色
    MAGENTA         = EGERGB(0xA8, 0, 0xA8),    //紫色
    BROWN           = EGERGB(0xA8, 0xA8, 0),
    LIGHTGRAY       = EGERGB(0xA8, 0xA8, 0xA8),
    DARKGRAY        = EGERGB(0x54, 0x54, 0x54),
    LIGHTBLUE       = EGERGB(0x54, 0x54, 0xFC),
    LIGHTGREEN      = EGERGB(0x54, 0xFC, 0x54),
    LIGHTCYAN       = EGERGB(0x54, 0xFC, 0xFC),
    LIGHTRED        = EGERGB(0xFC, 0x54, 0x54),
    LIGHTMAGENTA    = EGERGB(0xFC, 0x54, 0xFC),
    YELLOW          = EGERGB(0xFC, 0xFC, 0x54),
    WHITE           = EGERGB(0xFC, 0xFC, 0xFC), //白色
};
//EGE图形指令集中保存在文本文件中（由egeRun.cpp程序读取并绘制图形）
char *SNDfn;  //EGE图形指令文件名称，全局变量
FILE *SNDfp;  //EGE图形指令文件指针，全局变量
void SNDinit(char *fn); //创建EGE图形指令文件
void SNDend(void);      //关闭EGE图形指令文件
//各EGE图形指令的“接口”函数，将指令及参数保存在SNDfp文件
void SNDinitgraph(int w,int h);  //创建EGE窗口，大小w*h像素
void SNDsetbkcolor(int bk);      //设置EGE窗口背景颜色
void SNDsetcolor(int cr);        //设置EGE窗口绘制颜色
void SNDline(int x1,int y1,int x2,int y2); //绘制直线，坐标(x1,y1)至(x2,y2)
void SNDcircle(int x0,int y0,int r); //绘制圆，圆心(x0,y0)，半径r
void SNDfill(int x0,int y0,int cr,int newcr); //填充，(x0,y0)颜色cr填充为newcr
void SNDsetlinewidth(int wd);   //设置线条宽度
void SNDsetfont(int h,char *font,int d); //设置字体高度、名称、角度(单位0.1度)
void SNDouttextxy(int x0,int y0,char *text); //在(x0,y0)位置输出文本text
void SNDsaveimg(char *pngfn); //保存EGE窗口至.png图像文件
void SNDfillellipse(int x, int y, int xr, int yr); //椭圆填充
void SNDarc(int x, int y, int deg1, int deg2, int r); //绘制弧线
//
//EGE发送指令函数集
void SNDinit(char *fn)
{ //创建EGE图形指令文件
    if (fn==NULL)
        fn = "SNDcmd.txt";
    SNDfn = fn;
    SNDfp = fopen(fn, "w");
    if (SNDfp==NULL)
        printf("EGE指令文件创建失败（%s）\n", fn);
}
void SNDend(void)
{ //关闭EGE图形指令文件
    fclose(SNDfp);
    SNDfp = NULL;
}
void SNDinitgraph(int w, int h)
{ //发送EGE初始化指令
    fprintf(SNDfp, "initgraph %d %d\n", w, h);
}
void SNDsetbkcolor(int bk)
{ //设置背景颜色
    fprintf(SNDfp, "setbkcolor %d\n", bk);
}
void SNDsetcolor(int cr)
{ //设置颜色
    fprintf(SNDfp, "setcolor %d\n", cr);
}
void SNDcircle(int x0, int y0, int r)
{ //绘制中心圆，圆心坐标为(x0,y0)，半径为r
    fprintf(SNDfp, "circle %d %d %d\n", x0, y0, r);
}
void SNDline(int x1, int y1, int x2, int y2)
{ //绘制直线，坐标(x1,y1)至(x2,y2)
    fprintf(SNDfp, "line %d %d %d %d\n", x1, y1, x2, y2);
}
void SNDsetfillcolor(int newcr)
{ //设置填充颜色cr
    fprintf(SNDfp, "setfillcolor %d\n", newcr);
}
void SNDfloodfillsurface(int x0, int y0, int cr)
{ //颜色填充，坐标(x0,y0)，颜色cr区域填充（新颜色newcr）
    fprintf(SNDfp, "floodfillsurface %d %d %d\n", x0, y0, cr);
}
void SNDfill(int x0, int y0, int cr, int newcr)
{ //颜色填充，坐标(x0,y0)，颜色cr区域填充为新颜色newcr
//    fprintf(SNDfp, "setfillcolor %d\n", newcr);
//    fprintf(SNDfp, "floodfillsurface %d %d %d\n", x0, y0, cr);
    fprintf(SNDfp, "fill %d %d %d %d\n", x0, y0, cr, newcr);
}
void SNDsetlinewidth(int wd)
{ //设置线条宽度
    fprintf(SNDfp, "setlinewidth %d\n", wd);
}
void SNDsetfont(int h, char *font, int d)
{ //设置字体，字体高度、字体名称、角度（以0.1度为单位）
    fprintf(SNDfp, "setfont %d %d %s\n", h, d, font);
}
void SNDouttextxy(int x0, int y0, char *text)
{ //输出文本，文本坐标、文本内容
    fprintf(SNDfp, "outtextxy %d %d %s\n", x0, y0, text);
}
void SNDsaveimg(char *pngfn)
{ //保存图像至png文件
    fprintf(SNDfp, "saveimg %s\n", pngfn);
}
void SNDfillellipse(int x, int y, int xr, int yr)
{ //椭圆填充
    fprintf(SNDfp, "fillellipse %d %d %d %d\n", x, y, xr, yr);
}
void SNDarc(int x, int y, int deg1, int deg2, int r)
{ //绘制弧线，圆心(x,y)半径r，从角度deg1画弧线至角度deg2。水平右向为0度
    fprintf(SNDfp, "arc %d %d %d %d %d\n", x, y, deg1, deg2, r);
}
