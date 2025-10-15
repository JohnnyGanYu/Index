////egeSend.h
//EGE��ɫ���壬��ȡ��EGE��
#define EGERGB(r, g, b)         ( ((r)<<16) | ((g)<<8) | (b))
enum COLORS {
    BLACK           = 0,                        //��ɫ
    BLUE            = EGERGB(0, 0, 0xA8),       //��ɫ
    GREEN           = EGERGB(0, 0xA8, 0),       //��ɫ
    CYAN            = EGERGB(0, 0xA8, 0xA8),    //��ɫ
    RED             = EGERGB(0xA8, 0, 0),       //��ɫ
    MAGENTA         = EGERGB(0xA8, 0, 0xA8),    //��ɫ
    BROWN           = EGERGB(0xA8, 0xA8, 0),
    LIGHTGRAY       = EGERGB(0xA8, 0xA8, 0xA8),
    DARKGRAY        = EGERGB(0x54, 0x54, 0x54),
    LIGHTBLUE       = EGERGB(0x54, 0x54, 0xFC),
    LIGHTGREEN      = EGERGB(0x54, 0xFC, 0x54),
    LIGHTCYAN       = EGERGB(0x54, 0xFC, 0xFC),
    LIGHTRED        = EGERGB(0xFC, 0x54, 0x54),
    LIGHTMAGENTA    = EGERGB(0xFC, 0x54, 0xFC),
    YELLOW          = EGERGB(0xFC, 0xFC, 0x54),
    WHITE           = EGERGB(0xFC, 0xFC, 0xFC), //��ɫ
};
//EGEͼ��ָ��б������ı��ļ��У���egeRun.cpp�����ȡ������ͼ�Σ�
char *SNDfn;  //EGEͼ��ָ���ļ����ƣ�ȫ�ֱ���
FILE *SNDfp;  //EGEͼ��ָ���ļ�ָ�룬ȫ�ֱ���
void SNDinit(char *fn); //����EGEͼ��ָ���ļ�
void SNDend(void);      //�ر�EGEͼ��ָ���ļ�
//��EGEͼ��ָ��ġ��ӿڡ���������ָ�����������SNDfp�ļ�
void SNDinitgraph(int w,int h);  //����EGE���ڣ���Сw*h����
void SNDsetbkcolor(int bk);      //����EGE���ڱ�����ɫ
void SNDsetcolor(int cr);        //����EGE���ڻ�����ɫ
void SNDline(int x1,int y1,int x2,int y2); //����ֱ�ߣ�����(x1,y1)��(x2,y2)
void SNDcircle(int x0,int y0,int r); //����Բ��Բ��(x0,y0)���뾶r
void SNDfill(int x0,int y0,int cr,int newcr); //��䣬(x0,y0)��ɫcr���Ϊnewcr
void SNDsetlinewidth(int wd);   //�����������
void SNDsetfont(int h,char *font,int d); //��������߶ȡ����ơ��Ƕ�(��λ0.1��)
void SNDouttextxy(int x0,int y0,char *text); //��(x0,y0)λ������ı�text
void SNDsaveimg(char *pngfn); //����EGE������.pngͼ���ļ�
void SNDfillellipse(int x, int y, int xr, int yr); //��Բ���
void SNDarc(int x, int y, int deg1, int deg2, int r); //���ƻ���
//
//EGE����ָ�����
void SNDinit(char *fn)
{ //����EGEͼ��ָ���ļ�
    if (fn==NULL)
        fn = "SNDcmd.txt";
    SNDfn = fn;
    SNDfp = fopen(fn, "w");
    if (SNDfp==NULL)
        printf("EGEָ���ļ�����ʧ�ܣ�%s��\n", fn);
}
void SNDend(void)
{ //�ر�EGEͼ��ָ���ļ�
    fclose(SNDfp);
    SNDfp = NULL;
}
void SNDinitgraph(int w, int h)
{ //����EGE��ʼ��ָ��
    fprintf(SNDfp, "initgraph %d %d\n", w, h);
}
void SNDsetbkcolor(int bk)
{ //���ñ�����ɫ
    fprintf(SNDfp, "setbkcolor %d\n", bk);
}
void SNDsetcolor(int cr)
{ //������ɫ
    fprintf(SNDfp, "setcolor %d\n", cr);
}
void SNDcircle(int x0, int y0, int r)
{ //��������Բ��Բ������Ϊ(x0,y0)���뾶Ϊr
    fprintf(SNDfp, "circle %d %d %d\n", x0, y0, r);
}
void SNDline(int x1, int y1, int x2, int y2)
{ //����ֱ�ߣ�����(x1,y1)��(x2,y2)
    fprintf(SNDfp, "line %d %d %d %d\n", x1, y1, x2, y2);
}
void SNDsetfillcolor(int newcr)
{ //���������ɫcr
    fprintf(SNDfp, "setfillcolor %d\n", newcr);
}
void SNDfloodfillsurface(int x0, int y0, int cr)
{ //��ɫ��䣬����(x0,y0)����ɫcr������䣨����ɫnewcr��
    fprintf(SNDfp, "floodfillsurface %d %d %d\n", x0, y0, cr);
}
void SNDfill(int x0, int y0, int cr, int newcr)
{ //��ɫ��䣬����(x0,y0)����ɫcr�������Ϊ����ɫnewcr
//    fprintf(SNDfp, "setfillcolor %d\n", newcr);
//    fprintf(SNDfp, "floodfillsurface %d %d %d\n", x0, y0, cr);
    fprintf(SNDfp, "fill %d %d %d %d\n", x0, y0, cr, newcr);
}
void SNDsetlinewidth(int wd)
{ //�����������
    fprintf(SNDfp, "setlinewidth %d\n", wd);
}
void SNDsetfont(int h, char *font, int d)
{ //�������壬����߶ȡ��������ơ��Ƕȣ���0.1��Ϊ��λ��
    fprintf(SNDfp, "setfont %d %d %s\n", h, d, font);
}
void SNDouttextxy(int x0, int y0, char *text)
{ //����ı����ı����ꡢ�ı�����
    fprintf(SNDfp, "outtextxy %d %d %s\n", x0, y0, text);
}
void SNDsaveimg(char *pngfn)
{ //����ͼ����png�ļ�
    fprintf(SNDfp, "saveimg %s\n", pngfn);
}
void SNDfillellipse(int x, int y, int xr, int yr)
{ //��Բ���
    fprintf(SNDfp, "fillellipse %d %d %d %d\n", x, y, xr, yr);
}
void SNDarc(int x, int y, int deg1, int deg2, int r)
{ //���ƻ��ߣ�Բ��(x,y)�뾶r���ӽǶ�deg1���������Ƕ�deg2��ˮƽ����Ϊ0��
    fprintf(SNDfp, "arc %d %d %d %d %d\n", x, y, deg1, deg2, r);
}
