#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void showWelcome();
void showMenu();
double getRoot(double a);
void read1();
void write1();
double read2();
void write2();

int main() {
    showWelcome();
    showMenu();
    return 0;
}

void showWelcome() {
    printf("====================\n");
    printf("   欢迎使用本程序\n");
    printf("====================\n");
    printf("\n");
}

void showMenu() {
    int n;
    double x, y;
    
    while(1) {
        printf("\n--- 菜单 ---\n");
        printf("1. 算平方根\n");
        printf("2. 写数据到文件1\n");
        printf("3. 读文件1数据\n");
        printf("4. 写数据到文件2\n");
        printf("5. 读文件2数据并算平方根\n");
        printf("0. 退出\n");
        printf("选一个: ");
        
        scanf("%d", &n);
        
        switch(n) {
            case 1:
                printf("输入数字: ");
                scanf("%lf", &x);
                if(x >= 0) {
                    y = getRoot(x);
                    printf("结果是: %.4lf\n", y);
                } else {
                    printf("不能算负数\n");
                }
                break;
                
            case 2:
                write1();
                break;
                
            case 3:
                read1();
                break;
                
            case 4:
                write2();
                break;
                
            case 5:
                x = read2();
                if(x >= 0) {
                    y = getRoot(x);
                    printf("读到的数: %.2lf\n", x);
                    printf("平方根: %.4lf\n", y);
                }
                break;
                
            case 0:
                printf("再见\n");
                return;
                
            default:
                printf("输错了\n");
        }
    }
}

double getRoot(double a) {
    return sqrt(a);
}

void write1() {
    FILE *f = fopen("data1.txt", "a");
    double x;
    
    if(f == NULL) {
        printf("打不开文件\n");
        return;
    }
    
    printf("写什么到文件1: ");
    scanf("%lf", &x);
    
    fprintf(f, "%.2lf\n", x);
    fclose(f);
    
    printf("写好了\n");
}

void read1() {
    FILE *f = fopen("data1.txt", "r");
    double x;
    int i = 0;
    
    if(f == NULL) {
        printf("没找到文件\n");
        return;
    }
    
    printf("文件1里的数:\n");
    while(fscanf(f, "%lf", &x) != EOF) {
        printf("%.2lf\n", x);
        i++;
    }
    
    if(i == 0) {
        printf("空的\n");
    }
    
    fclose(f);
}

double read2() {
    FILE *f = fopen("data2.txt", "r");
    double x;
    
    if(f == NULL) {
        printf("没找到文件\n");
        return -1;
    }
    
    if(fscanf(f, "%lf", &x) == EOF) {
        printf("文件是空的\n");
        fclose(f);
        return -1;
    }
    
    fclose(f);
    return x;
}

void write2() {
    FILE *f = fopen("data2.txt", "w");
    double x;
    
    if(f == NULL) {
        printf("打不开文件\n");
        return;
    }
    
    printf("写什么到文件2: ");
    scanf("%lf", &x);
    
    fprintf(f, "%.2lf", x);
    fclose(f);
    
    printf("写好了\n");
}