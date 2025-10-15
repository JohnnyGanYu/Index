////egeRecv.h
#include <graphics.h>
#include <stdio.h>
#include <string.h>
//EGEָ������ļ��ж�ȡ��ִ��
char *RCVfn;    //EGEָ���ļ���
FILE *RCVfp;    //EGEָ��ָ��
char RCVcmd[80];    //EGEָ����
char RCVps[6][40];  //EGEָ�����
int RCVpd[6];       //EGEָ����������
int WinW, WinH;
FILE *RCVinit(char *fn)
{ //��EGEͼ��ָ���ļ�
    if (fn==NULL)
        fn = "RCVcmd.txt";
    RCVfn = fn;
    RCVfp = fopen(fn, "r");
    if (RCVfp==NULL)
        printf("EGEָ���ļ���ʧ�ܣ�%s��\n", fn);
    return RCVfp;
}
void RCVend(void)
{ //�ر�EGEͼ��ָ���ļ�
    fclose(RCVfp);
    RCVfp = NULL;
}
void RCVinitgraph(void)
{ //����EGE��ʼ��ָ��
    initgraph(RCVpd[1], RCVpd[2]);
    WinW = RCVpd[1];
    WinH = RCVpd[2];
    setlinestyle(SOLID_LINE, 0, 1, NULL);   //����
}
void RCVsetbkcolor(void)
{ //���ñ�����ɫ
    setbkcolor(RCVpd[1]);
}
void RCVsetcolor(void)
{ //������ɫ
    setcolor(RCVpd[1]);
}
void RCVcircle(void)
{ //��������Բ��Բ�����ꡢ�뾶
    circle(RCVpd[1], RCVpd[2], RCVpd[3]);
}
void RCVline(void)
{ //����ֱ�ߣ�����1������2
    line(RCVpd[1], RCVpd[2], RCVpd[3], RCVpd[4]);
}
void RCVsetfillcolor(void)
{ //���������ɫ
    setfillcolor(RCVpd[1]);
}
void RCVfloodfillsurface(void)
{ //��ɫ��䣬����\ԭ��ɫ
    floodfillsurface(RCVpd[1], RCVpd[2], RCVpd[3]);
}
void RCVfill(void)
{ //��ɫ��䣬����\ԭ��ɫ������ɫ
    setfillcolor(RCVpd[4]);
    floodfillsurface(RCVpd[1], RCVpd[2], RCVpd[3]);
}
void RCVsetlinewidth(void)
{ //�����������
    setlinewidth(RCVpd[1]);
}
void RCVsetfont(void)
{ //�������壬����߶ȡ��������ơ��Ƕ�
    setfont(RCVpd[1], 0, RCVps[3], RCVpd[2]
            ,0,0,false,false,false);
}
void RCVouttextxy(void)
{ //����ı����ı����ꡢ�ı�����
    outtextxy(RCVpd[1], RCVpd[2], RCVps[3]);
}
void RCVsaveimg(void)
{ //����ͼ����png�ļ�
    PIMAGE img;             //ͼ�����
    img = newimage();       //�����µ�ͼ�����
    getimage(img, 0, 0, WinW, WinH); //ѡȡ�������ڵ�ͼ�������
    savepng(img, RCVps[1], 0);  //����ͼ������е�ͼ���ļ���
}
void RCVfillellipse(void)
{ //��Բ���
    setfillstyle(SOLID_FILL, LIGHTGRAY);    //�����ɫ
    fillellipse(RCVpd[1], RCVpd[2], RCVpd[3], RCVpd[4]);
}
void RCVarc(void)
{ //���ƻ��ߣ�Բ��(x,y)�뾶r���ӽǶ�deg1���������Ƕ�deg2��ˮƽ����Ϊ0��
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
