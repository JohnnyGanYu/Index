#include <stdio.h>

int loop(int x) {
    int original = x;
    int reversed = 0;
    
    if (x < 0) return 0;
    
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    
    return original == reversed;
}

int main() {
    int a, b, i;
    scanf("%d %d", &a, &b);
    
    for (i = a; i <= b; i++) {
        if (i % 2 == 0 && loop(i)) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}