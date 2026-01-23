#include <stdio.h>

struct ProductionLine {
    int id;
    float actualOutput;
    float plannedOutput;
    float efficiency;
};

void calculateEfficiency(struct ProductionLine lines[], int n) {
    for (int i = 0; i < n; i++) {
        if (lines[i].plannedOutput != 0) {
            lines[i].efficiency = (lines[i].actualOutput / lines[i].plannedOutput) * 100.0f;
        } else {
            lines[i].efficiency = 0.0f;
        }
    }
}

void Sort(struct ProductionLine lines[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (lines[j].efficiency < lines[j + 1].efficiency) {
                struct ProductionLine temp = lines[j];
                lines[j] = lines[j + 1];
                lines[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("请输入生产线数量: ");
    scanf("%d", &n);

    struct ProductionLine lines[n];

    for (int i = 0; i < n; i++) {
        printf("请输入生产线%d的实际产量和计划产量: ", i + 1);
        scanf("%f %f", &lines[i].actualOutput, &lines[i].plannedOutput);
        lines[i].id = i + 1;
    }

    calculateEfficiency(lines, n);
    Sort(lines, n);

    printf("排序后的生产线生产效率:\n");
    for (int i = 0; i < n; i++) {
        printf("生产线%d: %.1f%%\n", lines[i].id, lines[i].efficiency);
    }

    return 0;
}