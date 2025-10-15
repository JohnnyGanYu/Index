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

//�����Ƴ������������
void display_match(struct match m[], int n)
{
    printf(" С��\t       ����\t    �ȷ�\n");
    for(int i=0; i<n; i++)
    {
        printf("  %c%13s:%-11s%d:%d\n", m[i].group, m[i].team1, m[i].team2, m[i].goal1, m[i].goal2);
    }
}
void display_team(struct team t[], int n)
{
    printf("\n С��  ���\t��/ʧ\t ʤ/ƽ/��   ����\n");
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

   //����ɱ�����ι���
    int n1 = sizeof(t) / sizeof(t[0]);
    int n2 = sizeof(m) / sizeof(m[0]);
    get_team(t, n1, m, n2);
    display_match(m, n2);
    display_team(t, n1);
    return 0;
}
