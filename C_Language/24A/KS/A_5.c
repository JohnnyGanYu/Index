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
    int score;              //积分，胜一场积3分，平一场积1分，负一场积0分
    int rank;               //排名
};

struct match
{
    char group;             //小组
    char team1[20];         //球队1
    char team2[20];         //球队2
    int  goal1;             //球队1的进球数
    int  goal2;             //球队2的进球数
};


void get_team(struct team t[], int n1, struct match m[], int n2)
{

    int i,j;
    // 获取所有球队比赛成绩
    for(i=0; i<n1; i++)
    {
      t[i].goal=t[i].lost=0;
      t[i].win=t[i].tie=t[i].defeat=0;
      t[i].score=0;
      for(j=0; j<n2; j++)
      {

        if (strcmp(t[i].team, m[j].team1)==0)
        {
            //请完成本程序段功能
            t[i].goal += m[j].goal1;
            t[i].lost  += m[j].goal2;
            if (m[j].goal1 > m[j].goal2)
            {
                t[i].win ++;
                t[i].score +=3;
            }
            else if (m[j].goal1 < m[j].goal2)
            {
                t[i].defeat ++;
            }
            else
            {
                t[i].tie ++;
                t[i].score += 1;
            }
        }
        if (strcmp(t[i].team, m[j].team2)==0)
        {
            //请完成本程序段功能
            t[i].goal += m[j].goal2;
            t[i].lost  += m[j].goal1;
            if (m[j].goal2 > m[j].goal1)
            {
                t[i].win ++;
                t[i].score += 3;
            }
            else if (m[j].goal2 < m[j].goal1)
            {
                t[i].defeat ++;
            }
            else
            {
                t[i].tie ++;
                t[i].score += 1;
            }
        }
      }
    }
}

//请完善程序的其他功能
void display_match(struct match m[], int n)
{
    printf(" 小组\t       赛事\t    比分\n");
    for(int i=0; i<n; i++)
    {
        printf("  %c%13s:%-11s%d:%d\n", m[i].group, m[i].team1, m[i].team2, m[i].goal1, m[i].goal2);
    }
}
void display_team(struct team t[], int n)
{
    printf("\n 小组  球队\t进/失\t 胜/平/负   积分\n");
    for(int i=0; i<n; i++)
    {
        printf("  %c   %s\t%2d/%d\t%2d/%d/%d\t    %d\n", t[i].group, t[i].team, t[i].goal, t[i].lost, t[i].win, t[i].tie, t[i].defeat, t[i].score);
    }
}
int main()
{
    struct team t[]={{'A',"Qatar"},{'A',"Senegal"},{'A',"Holland"},{'A',"Ecuador"},
                        {'B',"Iran"},{'B',"England"},{'B',"USA"},{'B',"Wales"}};
    struct match m[]={{'A',"Qatar","Ecuador",0,2}, {'A',"Senegal","Holland",0,2},
                      {'A',"Qatar","Senegal",1,3}, {'A',"Holland","Ecuador",1,1},
                      {'A',"Holland","Qatar",2,0}, {'A',"Ecuador","Senegal",1,2},
                      {'B',"England","Iran",6,2}, {'B',"USA","Wales",1,1},
                      {'B',"Wales","Iran",0,2}, {'B',"England","USA",0,0},
                      {'B',"Wales","England",0,3}, {'B',"Iran","USA",0,1}};

   //请完成本程序段功能
    int n1 = sizeof(t) / sizeof(t[0]);
    int n2 = sizeof(m) / sizeof(m[0]);
    get_team(t, n1, m, n2);
    display_match(m, n2);
    display_team(t, n1);
    return 0;
}
