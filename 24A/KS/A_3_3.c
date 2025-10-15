#define N 100
#include <stdio.h>
struct Medal
{
    char country[80];
    int gold;
    int silver;
    int bronze;
    int total;
};
void sort(struct Medal m[],int n)
{
    int i,j;
    struct Medal temp;  //add Medal
    for(i=0; i<n-1; i++)
        for(j=0; j<n-1-i; j++)
            if(m[j].total<m[j+1].total) //fix <
            {
                temp=m[j];
                m[j]=m[j+1];
                m[j+1]=temp;
            }
}
int main(void)
{
    int i,n;
    struct Medal m[N];
    printf("��������Ҹ�����");
    scanf("%d",&n);
    printf("������%d�����ҡ�������ͭ�Ƹ�����\n",n);
    for(i=0; i<n; i++)
    {
        scanf("%s%d%d%d",m[i].country,&m[i].gold,&m[i].silver,&m[i].bronze);
        m[i].total=m[i].gold+m[i].silver+m[i].bronze;   //add m[i].
    }
    sort(m,n);  //delete [N]
    printf("\n�����������ɶൽ�������\n");
    printf("����\t\t����\t����\tͭ��\t��������\n");
    for(i=0; i<n; i++)
        printf("%-16s%d\t%d\t%d\t%d\n", m[i].country, m[i].gold, m[i].silver,
                m[i].bronze,m[i].total);
    return 0;
}
