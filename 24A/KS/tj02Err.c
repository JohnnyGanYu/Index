//tj02.c��ʹ��ͼ�η���ϵ�к�����������������Բ
#include <stdio.h>
#include <stdlib.h>
#include "egeSend.h"

#define WinW 1024       //���ڿ�ȣ�����
#define WinH 768        //���ڸ߶ȣ�����
#define X0 512          //����ԲԲ��X���꣬X0
#define Y0 384          //����ԲԲ��Y���꣬Y0
#define R =300          //����Բ�뾶��R
#define K  30           //�����᳤������

int main(void)
{ //������
    printf("tj02:Begin\n")      //���ı�����������ʾ��Ϣ
    //EGE���ڳ�ʼ����
    SNDinit("tj02.txt");
    SNDinitgraph(WinW, WinH);   //��ʼ��EGE���ڣ���СWinW*WinH
    SNDsetbkcolor(WHITE);       //���ô��ڱ�����ɫ=��ɫ
    //������
    SNDsetcolor(RED);           //������ɫ=��ɫ��������
    SNDline(K/2,K,WinW-K,WinH-K);   //��������
    SNDline(WinW-K-8,K+8,WinW-K,K);   //�������°��ͷ
    SNDline(WinW-K-8,K-8,WinW-K,K);   //�������ϰ��ͷ
    SNDsetcolor(BLUE);          //������ɫ=��ɫ��������
    SNDline(K,K/2,K,WinH-K);        //��������
    SNDline(K+8,WinH-K-8,K,WinH-K);   //�������Ұ��ͷ
    SNDline(K-8,WinH-K-8,K,WinH-K);   //����������ͷ
    //����
    SNDsetcolor(BLACK);             //���û�ͼ��ɫ
    SNDsetfont(24,"����",0);        //�����ֺŽǶ�
    SNDouttextxy(K+2,K+2,"(30,30)");    //����ԭ��
    SNDouttextxy(WinW-K+2,K+2,"X");     //������
    SNDouttextxy(K+2,WinH-K+2,"Y");     //������
    //����Բ
    SNDsetcolor(RED|BLUE);          //���û�ͼ��ɫ����ɫ+��ɫ=��ɫ
    SNDcircle(X0,Y0,R);             //��������Բ��Բ������Ϊ(X0,Y0)���뾶ΪR
    SNDline(X0-R,Y0,X0+R,Y0);       //����Բ�������ֱ��
    SNDfill(X0,Y0-R/2,WHITE,RED);   //�ϰ�Բ���Ϊ��ɫ
    SNDfill(X0,Y0+R/2,WHITE,BLUE);  //�°�Բ���Ϊ��ɫ
    //����ͼ��
    SNDsaveimg("tj02.png");
    //���Ʒ������
    SNDend();
    //�����ⲿ�������ͼ��
    system("egeRun tj02.txt");
    printf("tj02:end\n");
    return 0;
}
