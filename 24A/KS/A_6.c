#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct team
{
    char group;             //С��
    char team[20];          //���
    int goal;               //������
    int lost;               //ʧ����
    int win;                //ʤ������
    int tie;                //ƽ�ֳ���
    int defeat;             //ʧ�ܳ���
    int score;              //���֣�ʤһ����3�֣�ƽһ����1�֣���һ����0��
    int rank;               //����
};
struct match
{
    char group;             //С��
    char team1[20];         //���1
    char team2[20];         //���2
    int  goal1;             //���1�Ľ�����
    int  goal2;             //���2�Ľ�����
};

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
    // ��ȡ������ӱ����ɼ�
    for(i=0; i<n1; i++)
    {
      t[i].goal=t[i].lost=0;
      t[i].win=t[i].tie=t[i].defeat=0;
      t[i].score=0;
      for(j=0; j<n2; j++)
      {

        if (strcmp(t[i].team, m[j].team1)==0)
        {
            //����ɱ�����ι���
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
            //����ɱ�����ι���
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
        if (t[i].group != t[i + 1].group)
        {
            cnt = 1;
        }
    }
    t[i].rank = cnt;
}
void display_match(struct match m[], int n)
{
    printf(" С��\t       ����\t    �ȷ�\n");
    for(int i=0; i<n; i++)
    {
        printf("  %c%13s:%-11s%d:%d\n", m[i].group, m[i].team1, m[i].team2, m[i].goal1, m[i].goal2);
    }
    printf("\n");
}
void display_team(struct team t[], int n)
{
    printf("С��  ���\t��/ʧ\t ʤ/ƽ/��   ����   ����\n");
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
    return cnt;
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
    printf("1. ������Ϣ\n"
           "2. ��������\n"
           "3. ����Ӳ�ѯ������Ϣ\n"
           "0. �˳�\n");
    line();
    printf("���������ѡ��(0-3):");
}
int main(void)
{
    struct team t[]={{'A',"Qatar"},{'A',"Senegal"},{'A',"Holland"},{'A',"Ecuador"},
                        {'B',"Iran"},{'B',"England"},{'B',"USA"},{'B',"Wales"}};
    struct match m[100];
    struct match m_work[100];
    int choice;
    char name[20];
    int n1 = sizeof(t) / sizeof(t[0]);
    int n2 = read(m);

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
            break;
        case 1:
            display_match(m, n2);
            break;
        case 2:
            display_team(t, n1);
            break;
        case 3:
            printf("��������Ҫ��ѯ�����:");
            scanf("%s", name);
            display_match(m_work, search_match(m, n2, m_work, name));
            break;
        default:
            printf("�������\n");
        }
    }
    while (choice != 0);
    printf("лл, �ټ�!\n");
    return 0;
}
