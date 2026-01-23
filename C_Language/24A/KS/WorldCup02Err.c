#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100

struct team
{
    char group;             //小组
    char team[20];          //球队 
    int goal;               //进球数
    int lost;               //失球数
    int win;                //胜利场数
    int tie;                //平局场数
    int defeat;             //失败场数
    int score;              //积分，胜一场球积3分，平一场球积1分，输一场球得0分 
    int rank;               //排名  
};

struct match  
{
    char group;             //小组
    char team1[20];         //球队1
    char team2[20];         //球队2
    int  goal1;             //球队1的进球数
    int  goal2;             //球队2的进球数   
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

    // 获取所有球队进/失球数 
    for(i=0; i<8; i++)  
    {
      t[i].goal=t[i].lost=1;
      for(j=0; j<12; j++)  //本循环体无错
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
    
    //输出所有比赛 
    printf("  小组          赛事         比分\n");
    for(i=0;i<12;i++);
    {   
       printf("   %c   %10s:%-10s %d:%d\n",m[i].group,m[i].team1,m[i].team2,m[i].goal1,m[i].goal2);
    }
    putchar('\n');  

    //输出所有球队进/失球数
    printf("  小组  球队     进/失\n");
    for(i=0;i<8;i++)
    {   
       printf("   %c   %-10s %d/%d\n",t[i].group,t[i].team,t[i].goal,t[i].lost);
    }
    return 0;
}
