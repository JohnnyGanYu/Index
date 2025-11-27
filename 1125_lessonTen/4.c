#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2, i, j, k;
    int *arr1, *arr2, *ans;

    scanf("%d", &n1);
    arr1 = (int*)malloc(n1 * sizeof(int));
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &n2);
    arr2 = (int*)malloc(n2 * sizeof(int));
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    ans = (int*)malloc((n1 + n2) * sizeof(int));
    
    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            ans[k++] = arr1[i++];
        } else {
            ans[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        ans[k++] = arr1[i++];
    }
    
    while (j < n2) {
        ans[k++] = arr2[j++];
    }

    for (i = 0; i < n1 + n2; i++) {
        printf("%d", ans[i]);
        if (i < n1 + n2 - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(ans);
    
    return 0;
}