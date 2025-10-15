//tj03org.c������������
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "egeSend.h"

#define WinW 1024       //���ڿ�ȣ�����
#define WinH 768        //���ڸ߶ȣ�����
#define X0 512          //����ԲԲ��X����
#define Y0 384          //����ԲԲ��Y����
#define R  300          //����Բ�뾶��R
#define K  30           //�����᳤������
#define PI 3.14159265   //Բ����

struct point
{ //�������㡱�ṹ��
    float  x;       //���X����
    float  y;       //���Y����
};
void drawHeartLine(void)
{ //����������
    struct point xy[361];  //��������361���㣬���ڵ������߶�
    float dQ; //���������ߵĵ���ԭ�㣬��������y��н�ΪdQ��dQ��0��360��
    float rQ; //�����ߵĳ���ΪrQ��rQ��R����0������R
    int  i;
    //������ϵ���费ֱ���·���Ϊ0�ȣ���ʱ����ת360��
    for (i=0; i<=360; i++)
    { //360��ѭ����ǰ180�������������Ҳ�������꣬��180����������������
        dQ = PI*i/180;          //�Ƕ�ת��Ϊ����
        rQ = R*cos(dQ/2);       //�����곤��ʹ�����ҵݼ�
        if (rQ<0)
            rQ = -rQ;           //ȡ����Ϊ��ֵ
        xy[i].x = rQ*sin(dQ) + 0.5;   //������ת��ΪX����ֵ
        xy[i].y = rQ*cos(dQ) + 0.5;   //������ת��ΪY����ֵ
    }
    for (i=0; i<360; i++)  //����360���߶Σ�����2�������߶�
        SNDline(X0+xy[i].x, Y0+xy[i].y, X0+xy[i+1].x, Y0+xy[i+1].y);
}

int main(void)
{ //������
    printf("tj03org:Begin\n");     //���ı�����������ʾ������Ϣ
    //EGE���ڳ�ʼ����
    SNDinit("tj03org.txt");
    SNDinitgraph(WinW, WinH);       //��ʼ��EGE���ڣ���СWinW*WinH
    SNDsetbkcolor(WHITE);           //���ô��ڱ�����ɫ=��ɫ
    //����Բ��������
    SNDsetcolor(RED|BLUE);          //���û�ͼ��ɫ����ɫ+��ɫ=��ɫ
    SNDcircle(X0, Y0, R);           //��������Բ��Բ������Ϊ(X0,Y0)���뾶ΪR
    drawHeartLine();
    SNDfill(X0, Y0+R/2, WHITE, RED);//����������ԭ��ɫ���Ϊ��ɫ
    //������
    SNDsetcolor(BLACK);           //������ɫ=��ɫ
    SNDline(K/2,Y0,WinW-K,Y0);        //��������
    SNDline(WinW-K-8,Y0+8,WinW-K,Y0);   //���������°��ͷ
    SNDline(WinW-K-8,Y0-8,WinW-K,Y0);   //���������ϰ��ͷ
    SNDline(X0,K/2,X0,WinH-K);        //��������
    SNDline(X0+8,WinH-K-8,X0,WinH-K);   //���������Ұ��ͷ
    SNDline(X0-8,WinH-K-8,X0,WinH-K);   //������������ͷ
    //����
    SNDsetfont(24,"����",0);          //�����ֺŽǶ�
    SNDouttextxy(2, 2, "tj03org");      //��������
    SNDouttextxy(WinW-K+2,Y0+2,"X");    //������
    SNDouttextxy(X0+2,WinH-K+2,"Y");    //������
    //����ͼ��
    SNDsaveimg("tj03org.png");
    //���Ʒ������
    SNDend();
    //�����ⲿ�������ͼ��
    system("egeRun tj03org.txt");
    printf("tj03org:end\n");
    return 0;
}
