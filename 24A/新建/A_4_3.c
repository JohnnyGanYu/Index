#include <stdio.h>
#include <string.h>
#define N (5)

struct Book
{
    char isbn[20];
    char author[20];
    float price;
    char category[20];
};

// 读取图书信息
void readBooks(struct Book arr[])
 {
    for (int i = 0; i < N; i ++)
    {
        printf("请输入第%d本图书信息（ISBN 作者 价格 分类）：", i + 1);
        scanf("%s %s %f %s",
                  arr[i].isbn, arr[i].author,
                  &arr[i].price, arr[i].category);
    }
    return;
}

void searchBook(struct Book arr[])
{
    char authorName[20];
    int cnt = -1;
    printf("请输入要查询的作者姓名：");
    scanf("%s", authorName);
    for (int i = 0; i < N; i ++)
    {
        if (strcmp(arr[i].author, authorName) == 0)
        {
            cnt = i;
            printf("作者\"%s\"的图书信息：\n"
                   "ISBN：%s，作者：%s，价格：%.2f，分类：%s\n",
                   arr[i].author, arr[i].isbn, arr[i].author, arr[i].price, arr[i].category);
            break;
        }
    }
    if (cnt == -1)
    {
        printf("未搜索到该作者\n");
    }
    return;
}

void bookprice(struct Book arr[])
{
    int cnt = 0;
    for (int i = 0; i < N; i ++)
    {
        if (arr[i].price > 50)
        {
            cnt ++;
        }
    }
    printf("价格≥50元的图书数量：%d\n", cnt);
    return;
}

int main(void)
{
    struct Book books[N];
    readBooks(books);
    searchBook(books);
    bookprice(books);
    return 0;
}
