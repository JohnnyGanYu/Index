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
        printf("��ӳɹ���\n");
    }
    else
    {
        printf("���ʧ�ܣ�\n");
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
        printf("ɾ��ʧ�ܣ�\n");
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
        printf("ɾ���ɹ���\n");
    }
    else
    {
        printf("ɾ��ʧ�ܣ�\n");
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
                printf("ƥ���ͼ����Ϣ��\n");
                i--;
            }
            printf("ISBN��%s��������%s�����ߣ�%s���۸�%.2f\n",
                   current -> isbn, current -> name, current -> author, current -> price);
        }
        current = current -> next;
    }
    if (i)
    {
        printf("δ�ҵ���ͼ�飡\n");
    }
    return;
}

void saveList(struct Book *head)
{
    struct Book *current = head;
    FILE *fp;
    if (!(fp = fopen("books.dat", "wb") ))
    {
        printf("���ļ�ʧ�ܣ�\n");
    }
    while (current != NULL)
    {
        fwrite(current, sizeof *current, 1, fp);
        current = current -> next;
    }
    fclose(fp);
    printf("��Ϣ�ѱ��浽books.dat�������˳���\n");
}

int main(void)
{
    printf("===== ͼ�����ϵͳ =====\n");
    int i = 0;
    struct Book *head = NULL;
    while(4-i)
    {
        char isbn[20];
        char name[20];
        char author[20];
        char key[20];
        float price;
        printf("1. ���ͼ��\n"
               "2. ɾ��ͼ��\n"
               "3. ģ����ѯ\n"
               "4. ���沢�˳�\n"
               "���������ѡ��1-4����");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("������ͼ��ISBN��");
            scanf("%s", isbn);
            printf("������������");
            scanf("%s", name);
            printf("���������ߣ�");
            scanf("%s", author);
            printf("������۸�");
            scanf("%f", &price);
            insertNode(&head, isbn, name, author, price);
            break;
        case 2:
            printf("������Ҫɾ����ͼ��ISBN��");
            scanf("%s", isbn);
            deleteNode(&head, isbn);
            break;
        case 3:
            printf("�������ѯ�ؼ��ʣ�");
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
