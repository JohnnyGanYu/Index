#include <stdio.h>
#include <string.h>

void str_bin(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = len1 - 1; 
    int j = len2 - 1;
    int k = len1 + len2 - 1; 
    str1[k + 1] = '\0'; 

    while (i >= 0 && j >= 0) {
        if (str1[i] > str2[j]) {
            str1[k--] = str1[i--];
        } else {
            str1[k--] = str2[j--];
        }
    }
    
    while (j >= 0) {
        str1[k--] = str2[j--];
    }
}

int main() {
    char str1[201]; 
    char str2[100];
    
    scanf("%s", str1);
    scanf("%s", str2);

    str_bin(str1, str2);
    printf("%s\n", str1);
    
    return 0;
}