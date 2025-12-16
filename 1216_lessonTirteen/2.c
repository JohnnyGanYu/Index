#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc (const void * a1, const void * a2)
{
   return ( *(int*)a1 - *(int*)a2 );
}

int same_set(int a[],int b[],int len) {
    qsort(a, len, sizeof(int), cmpfunc);
    qsort(b, len, sizeof(int), cmpfunc);
    if (memcmp(a, b, len * sizeof(int)) == 0) {
        return 1;
    } 
    else {
        return 0;
    }
}

int main(void) {
    int len, i;
    int a[100000], b[100000];
    scanf("%d", &len);
    for (i = 0; i < len; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < len; i++) {
        scanf("%d", &b[i]);
    }
    printf("%d\n", same_set(a, b, len));
    return 0;
}