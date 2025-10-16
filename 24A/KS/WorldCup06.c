#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int count(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    int record_count = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        record_count ++;
    }
    fclose(fp);
    return record_count;
}

int read(struct match m[])
{
    int i=0;
    FILE *fp;
    fp = fopen("match.txt", "r");
    while (fscanf(fp, "%c %s %s %d %d\n", &m[i].group, m[i].team1,
                  m[i].team2, &m[i].goal1, &m[i].goal2) == 5)
    {
        i++;
    }
    fclose(fp);
    return i;
}

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

void score_sort(struct team t[], int n)
{
    int i,j;
    struct team temp;
    for(i=0; i<n-1; i++)
        for(j=0; j<n-1-i; j++)
            if(t[j].score<t[j+1].score)
            {
                temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }
    for(i=0; i<n-1; i++)
        for(j=0; j<n-1-i; j++)
            if(t[j].group>t[j+1].group)
            {
                temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }
}
void get_rank(struct team t[], int n)
{
    int i = 0, cnt = 1;
    for (i = 0; i < n - 1; i ++)
    {
        t[i].rank = cnt;
        cnt++;
        if (t[i].group != t[i + 1].group)
        {
            cnt = 1;
        }
    }
    t[i].rank = cnt;
}

void display_match(struct match m[], int n)
{
    printf(" 小组\t       赛事\t    比分\n");
    for(int i=0; i<n; i++)
    {
        printf("  %c%13s:%-11s%d:%d\n", m[i].group, m[i].team1, m[i].team2, m[i].goal1, m[i].goal2);
    }
    printf("\n");
}

void display_team(struct team t[], int n)
{
    printf("小组  球队\t进/失\t 胜/平/负   积分   排名\n");
    for(int i=0; i<n; i++)
    {
        printf("  %c   %s\t%2d/%d\t%2d/%d/%d\t    %d\t    %d\n", t[i].group, t[i].team,
               t[i].goal, t[i].lost, t[i].win, t[i].tie, t[i].defeat, t[i].score, t[i].rank);
    }
    printf("\n");
}

int search_match(struct match m[], int n, struct match m_work[], char team[ ])
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(strcmp(m[i].team1, team) * strcmp(m[i].team2, team)))
        {
            m_work[cnt++] = m[i];
        }
    }
    if (!cnt)
    {
        printf("没有找到与该球队相关的赛事\n");
    }
    return cnt;
}

void search_team(struct team t[], int n, char team[ ])
{
        int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(t[i].team, team))
        {
            cnt --;
        printf("小组  球队\t进/失\t 胜/平/负   积分   排名\n");
        printf("  %c   %s\t%2d/%d\t%2d/%d/%d\t    %d\t    %d\n", t[i].group, t[i].team,
               t[i].goal, t[i].lost, t[i].win, t[i].tie, t[i].defeat, t[i].score, t[i].rank);
        }
    }
    if (cnt)
    {
        printf("没有找到该球队\n");
    }
}

void save(struct team t[], int n)
{
    FILE *fp;
    fp = fopen("team.txt", "w");
    for (int i = 0; i < n; i ++)
    {
        if (strlen(t[i].team) < 7 * sizeof(char))
            {fprintf(fp, "%c %s\t    %d/%d   %d/%d/%d   %d   %d\n", t[i].group, t[i].team,
                  t[i].goal, t[i].lost, t[i].win, t[i].tie, t[i].defeat, t[i].score, t[i].rank);}
        else
            {fprintf(fp, "%c %s    %d/%d   %d/%d/%d   %d   %d\n", t[i].group, t[i].team,
                  t[i].goal, t[i].lost, t[i].win, t[i].tie, t[i].defeat, t[i].score, t[i].rank);}
    }
    fclose(fp);
}

void line(void)
{
        for (int i = 0; i < 20; i++)
    {
        printf("%c", '-');
    }
    printf("\n");
}
void menu(void)
{
    line();
    printf("1. 赛事信息\n"
           "2. 积分排名\n"
           "3. 查询球队信息\n"
           "4. 查询赛事信息\n"
           "0. 退出\n");
    line();
    printf("请输入你的选择(0-4):");
}
int main(void)
{
    struct team t[]={{'A',"Qatar"},{'A',"Senegal"},{'A',"Holland"},{'A',"Ecuador"},
                        {'B',"Iran"},{'B',"England"},{'B',"USA"},{'B',"Wales"}};
    const int n2 = count("match.txt");
    struct match *m, *m_work;
    m=(struct match *)malloc(sizeof(struct match) * n2);
    m_work=(struct match *)malloc(sizeof(struct match) * n2);
    int choice;
    char name[20];
    int n1 = sizeof(t) / sizeof(t[0]);
    read(m);

    get_team(t, n1, m, n2);
    score_sort(t, n1);
    get_rank(t, n1);

    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            save(t, n1);
            printf("谢谢, 再见!\n");
            break;
        case 1:
            display_match(m, n2);
            break;
        case 2:
            display_team(t, n1);
            break;
        case 3:
            printf("请输入想要查询的球队:");
            scanf("%s", name);
            search_team(t, n1, name);
            break;
        case 4:
            printf("请输入想要查询的球队:");
            scanf("%s", name);
            int ret = search_match(m, n2, m_work, name) ;
            if (ret) display_match(m_work, ret);
            break;
        default:
            printf("输入错误\n");
        }
    }
    while (choice != 0);

    return 0;
}

