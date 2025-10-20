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

// ��ȡͼ����Ϣ
void readBooks(struct Book arr[])
 {
    for (int i = 0; i < N; i ++)
    {
        printf("�������%d��ͼ����Ϣ��ISBN ���� �۸� ���ࣩ��", i + 1);
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
    printf("������Ҫ��ѯ������������");
    scanf("%s", authorName);
    for (int i = 0; i < N; i ++)
    {
        if (strcmp(arr[i].author, authorName) == 0)
        {
            cnt = i;
            printf("����\"%s\"��ͼ����Ϣ��\n"
                   "ISBN��%s�����ߣ�%s���۸�%.2f�����ࣺ%s\n",
                   arr[i].author, arr[i].isbn, arr[i].author, arr[i].price, arr[i].category);
            break;
        }
    }
    if (cnt == -1)
    {
        printf("δ������������\n");
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
    printf("�۸��50Ԫ��ͼ��������%d\n", cnt);
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
