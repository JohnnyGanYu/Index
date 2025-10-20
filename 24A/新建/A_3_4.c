#include <stdio.h>
#include <string.h>
#define N 100 // 最多存储100本图书

struct Book {
    char isbn[20];
    char name[50];
    float price;
    int pages;
};

// 按价格降序、页数升序排序
void sortBooks(struct Book arr[], int n) {
    struct Book temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i -1; j++) { // 错误1：循环边界错误
            // 错误2：排序条件错误（价格降序、页数升序逻辑颠倒）
            if (arr[j].price < arr[j+1].price || (arr[j].price == arr[j+1].price && arr[j].pages > arr[j+1].pages)) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// 读取文件中图书信息，返回实际读取的图书数量
int readBooks(struct Book arr[]) {
    FILE *fp;
    int count = 0;
    // 错误3：文件打开模式错误（读文本文件应使用"r"，而非"rb"）
    if (!(fp = fopen("books.txt", "r"))) {
        printf("无法打开文件！\n");
        return -1;
    }
    // 错误4：fscanf格式控制符错误（书名可能含空格，%s无法读取完整）
    while (fscanf(fp, "%s %[^0-9] %f %d", arr[count].isbn, arr[count].name, &arr[count].price, &arr[count].pages) != EOF) {
        count++;
    }
    fclose(fp);
    return count;
}

// 写入排序后的图书信息到文件
void writeBooks(struct Book arr[], int n) {
    FILE *fp;
    if (!(fp = fopen("C:\\KS\\sorted_books.txt", "w"))) {
        printf("无法创建文件！\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "ISBN：%s，书名：%s，价格：%.2f，页数：%d\n",
                arr[i].isbn, arr[i].name, arr[i].price, arr[i].pages);
    }
    fclose(fp);
}

int main(void) {
    struct Book books[N];
    int num = readBooks(books);
    if (num <= 0) return 1;
    sortBooks(books, num);
    printf("排序后图书列表：\n");
    for (int i = 0; i < num; i++) {
        printf("ISBN：%s，书名：%s\b，价格：%.2f，页数：%d\n",
               books[i].isbn, books[i].name, books[i].price, books[i].pages);
    }
    writeBooks(books, num);
    return 0;
}
