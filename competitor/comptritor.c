#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);

    int scores[N][4];

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &scores[i][0], &scores[i][1], &scores[i][2]);
        scores[i][3] = scores[i][0] + scores[i][1] + scores[i][2];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int diff_chinese = abs(scores[i][0] - scores[j][0]);
            int diff_math = abs(scores[i][1] - scores[j][1]);
            int diff_english = abs(scores[i][2] - scores[j][2]);
            int diff_total = abs(scores[i][3] - scores[j][3]);

            if (diff_chinese <= 5 && diff_math <= 5 && diff_english <= 5 && diff_total <= 10) {
                count++;
            }
        }
    }
}
