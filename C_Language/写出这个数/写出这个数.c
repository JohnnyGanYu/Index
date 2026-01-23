#include <stdio.h>

const char CHINESE[][5] = {"ling", "yi", "er", "san", "si",
                          "wu", "liu", "qi", "ba", "jiu"};

void printChinese(int n) {
    if(n >= 10) {
        printChinese(n / 10);
        printf(" ");
    }
    printf("%s", CHINESE[n % 10]);
}

int main() {
    int sum = 0;
    char c;

    while((c = getchar()) != '\n' && c != EOF) {
        if(c >= '0' && c <= '9') {
            sum += c - '0';
        }
    }

    if(sum == 0) {
        printf("%s\n", CHINESE[0]);
    } else {
        printChinese(sum);
        printf("\n");
    }

    return 0;
}
