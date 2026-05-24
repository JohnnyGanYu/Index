#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *foods[] = {"猪脚饭", "沙县小吃", "卤肉饭"};
    int count = sizeof(foods) / sizeof(foods[0]);

    srand((unsigned)time(NULL));
    int index = rand() % count;

    printf("今天吃: %s\n", foods[index]);
    return 0;
}