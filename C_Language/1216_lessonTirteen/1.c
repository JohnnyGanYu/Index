#include <stdio.h>

int sum(int x) {
    int res = 0;
    while (x) {
        res += x%10; 
        x /= 10;
    }
    return res;
}

int main(void) {
    int x;
    scanf("%d", &x);
    printf("%d\n", sum(x));
    return 0;
}