#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    char isbn[20];
    char name[20];
    char author[20];
    float price;
    struct Book *next;
};

struct Book *createNode(char isbn[], char name[],
                        char author[], float price)
{
    struct Book *p = (struct Book *)malloc(sizeof(struct Book));
    strcpy(p -> isbn, isbn);
    strcpy(p -> name, name);
    strcpy(p -> author, author);
    p -> price = price;
    p -> next = NULL;
    return p;
}

void insertNode(struct Book **head, char isbn[],
                char name[], char author[], float price)
{
    int i = 0;
    struct Book *p = createNode(isbn, name, author, price);
    struct Book *current = *head;
    struct Book *pre = NULL;
    if (*head == NULL)
    {
        *head = p;
        i =1;
    }
    else if (strcmp((*head) -> isbn, isbn) > 0)
    {
        p->next = *head;
        *head = p;
        i = 1;
    }
    else while (!i)
    {
        pre = current;
        current = current -> next;
        if (strcmp(current -> isbn, isbn) == 0)
        {
            free(p);
            i = 2;
        }
        else if (strcmp(current -> isbn, isbn) > 0)
        {
            p -> next = current;
            pre -> next = p;
            i = 1;
        }
        else if (current -> next == NULL)
        {
            current -> next = p;
            i = 1;
        }
    }

    if (i == 1)
    {
        printf("添加成功！\n");
    }
    else
    {
        printf("添加失败！\n");
    }

    return;
}

int deleteNode(struct Book **head, char isbn[])
{
    int i = 0;
    struct Book *current = *head;
    struct Book *pre = NULL;
    if (current == NULL)
    {
        printf("删除失败！\n");
        return 0;
    }
    if (strcmp(current -> isbn, isbn) == 0)
        {
            *head = current -> next;
            free(current);
            i = 1;
        }
    else while (!i && current)
    {
        if (strcmp(current -> isbn, isbn) == 0)
        {
            pre -> next = current -> next;
            free(current);
            i = 1;
        }
        pre = current;
        current = current -> next;
    }

    if (i == 1)
    {
        printf("删除成功！\n");
    }
    else
    {
        printf("删除失败！\n");
    }

    return i;
}

void searchNode(struct Book *head, char key[])
{
    struct Book *current = head;
    int i = 1;
    while (current != NULL)
    {
        if (strstr(current -> name, key))
        {
            if (i)
            {
                printf("匹配的图书信息：\n");
                i--;
            }
            printf("ISBN：%s，书名：%s，作者：%s，价格：%.2f\n",
                   current -> isbn, current -> name, current -> author, current -> price);
        }
        current = current -> next;
    }
    if (i)
    {
        printf("未找到该图书！\n");
    }
    return;
}

void saveList(struct Book *head)
{
    struct Book *current = head;
    FILE *fp;
    if (!(fp = fopen("books.dat", "wb") ))
    {
        printf("打开文件失败！\n");
    }
    while (current != NULL)
    {
        fwrite(current, sizeof *current, 1, fp);
        current = current -> next;
    }
    fclose(fp);
    printf("信息已保存到books.dat，程序退出！\n");
}

int main(void)
{
    printf("===== 图书管理系统 =====\n");
    int i = 0;
    struct Book *head = NULL;
    while(4-i)
    {
        char isbn[20];
        char name[20];
        char author[20];
        char key[20];
        float price;
        printf("1. 添加图书\n"
               "2. 删除图书\n"
               "3. 模糊查询\n"
               "4. 保存并退出\n"
               "请输入你的选择（1-4）：");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("请输入图书ISBN：");
            scanf("%s", isbn);
            printf("请输入书名：");
            scanf("%s", name);
            printf("请输入作者：");
            scanf("%s", author);
            printf("请输入价格：");
            scanf("%f", &price);
            insertNode(&head, isbn, name, author, price);
            break;
        case 2:
            printf("请输入要删除的图书ISBN：");
            scanf("%s", isbn);
            deleteNode(&head, isbn);
            break;
        case 3:
            printf("请输入查询关键词：");
            scanf("%s", key);
            searchNode(head, key);
            break;
        case 4:
            saveList(head);
            break;
        }
    }
    return 0;
}
