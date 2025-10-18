#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4

struct Student
{
    char name[20];
    int score[100];
    int total;
    char level;
};

void read_score(struct Student arr[], int n)
{
    FILE *fp;
    if (!(fp = fopen("total.txt", "r")))
    {
        printf("无法打开文件");
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s %d", arr[i].name, &arr[i].total);
    }
    fclose(fp);
}

void sort_score(struct Student arr[], int n)
{
    struct Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if ((arr[j].total < arr[j + 1].total) || ((arr[j].total == arr[j + 1].total) && (strcmp(arr[j].name, arr[j + 1].name) > 0)))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void write_result(struct Student arr[], int n)
{
        FILE *fp;
    if (!(fp = fopen("sorted_total.txt", "w")))
    {
        printf("无法打开文件");
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%s %d\n", arr[i].name, arr[i].total);
    }
    fclose(fp);
}

int main(void)
{
    struct Student s[N];
    read_score(s, N);
    sort_score(s, N);

    for (int i = 0; i < N; i++)
    {
        printf("%s %d\n", s[i].name, s[i].total);
    }

    write_result(s, N);

    return 0;
}
