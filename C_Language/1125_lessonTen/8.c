#include <stdio.h>
#include <string.h>

int main() {
    char num[100], temp;
    int i;
    scanf("%s", num);

    int len = strlen(num);
    for (i = 0; i < len / 2; i++) {
        temp = num[i];
        num[i] = num[len - 1 - i];
        num[len - 1 - i] = temp;
    }

    printf("%s\n", num);
    
    return 0;
}