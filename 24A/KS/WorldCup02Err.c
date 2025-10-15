#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100

struct team
{
    char group;             //С��
    char team[20];          //��� 
    int goal;               //������
    int lost;               //ʧ����
    int win;                //ʤ������
    int tie;                //ƽ�ֳ���
    int defeat;             //ʧ�ܳ���
    int score;              //���֣�ʤһ�����3�֣�ƽһ�����1�֣���һ�����0�� 
    int rank;               //����  
};

struct match  
{
    char group;             //С��
    char team1[20];         //���1
    char team2[20];         //���2
    int  goal1;             //���1�Ľ�����
    int  goal2;             //���2�Ľ�����   
}

int main()
{
    struct team t[8]={{'A',"Qatar"},{'A',"Senegal"},{'A',"Holland"},{'A',"Ecuador"},
                        {'B',"Iran"},{'B',"England"},{'B',"USA"},{'B',"Wales"}};
    struct match m[12]={{'A',"Qatar","Ecuador",0,2}, {'A',"Senegal","Holland",0,2},
                      {'A',"Qatar","Senegal",1,3}, {'A',"Holland","Ecuador",1,1},
                      {'A',"Holland","Qatar",2,0}, {'A',"Ecuador","Senegal",1,2},
                      {'B',"England","Iran",6,2}, {'B',"USA","Wales",1,1},
                      {'B',"Wales","Iran",0,2}, {'B',"England","USA",0,0},
                      {'B',"Wales","England",0,3}, {'B',"Iran","USA",0,1}};
    int i,j,flag;

    // ��ȡ������ӽ�/ʧ���� 
    for(i=0; i<8; i++)  
    {
      t[i].goal=t[i].lost=1;
      for(j=0; j<12; j++)  //��ѭ�����޴�
      {
        flag=0;
        if (strcmp(t[i].team, m[j].team1)==0) flag=1; 
        if (strcmp(t[i].team, m[j].team2)==0) flag=2;
        switch (flag)
        {   
            case 1: t[i].goal=t[i].goal+m[j].goal1; t[i].lost=t[i].lost+m[j].goal2; break;  
            case 2: t[i].goal=t[i].goal+m[j].goal2; t[i].lost=t[i].lost+m[j].goal1; 
        }
      }
    }
    
    //������б��� 
    printf("  С��          ����         �ȷ�\n");
    for(i=0;i<12;i++);
    {   
       printf("   %c   %10s:%-10s %d:%d\n",m[i].group,m[i].team1,m[i].team2,m[i].goal1,m[i].goal2);
    }
    putchar('\n');  

    //���������ӽ�/ʧ����
    printf("  С��  ���     ��/ʧ\n");
    for(i=0;i<8;i++)
    {   
       printf("   %c   %-10s %d/%d\n",t[i].group,t[i].team,t[i].goal,t[i].lost);
    }
    return 0;
}
