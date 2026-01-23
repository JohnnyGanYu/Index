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
    printf("请输入国家个数：");
    scanf("%d",&n);
    printf("请输入%d个国家、金、银、铜牌个数：\n",n);
    for(i=0; i<n; i++)
    {
        scanf("%s%d%d%d",m[i].country,&m[i].gold,&m[i].silver,&m[i].bronze);
        m[i].total=m[i].gold+m[i].silver+m[i].bronze;   //add m[i].
    }
    sort(m,n);  //delete [N]
    printf("\n按奖牌总数由多到少排序后：\n");
    printf("国家\t\t金牌\t银牌\t铜牌\t奖牌总数\n");
    for(i=0; i<n; i++)
        printf("%-16s%d\t%d\t%d\t%d\n", m[i].country, m[i].gold, m[i].silver,
                m[i].bronze,m[i].total);
    return 0;
}
