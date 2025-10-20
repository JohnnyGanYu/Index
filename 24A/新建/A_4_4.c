#include <stdio.h>
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
    p -> = NULL;
    return p;
}

void insertNode(struct Book **head, char isbn[],
                char name[], char author[], float price)
{
    struct Book *p = createNode(isbn, name, author, price);
    if (*head == NULL)
    {
        *head = p;
    }

    while ()
    {

    }
    return;
}


