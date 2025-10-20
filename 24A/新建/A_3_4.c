#include <stdio.h>
#include <string.h>
#define N 100 // ���洢100��ͼ��

struct Book {
    char isbn[20];
    char name[50];
    float price;
    int pages;
};

// ���۸���ҳ����������
void sortBooks(struct Book arr[], int n) {
    struct Book temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i -1; j++) { // ����1��ѭ���߽����
            // ����2�������������󣨼۸���ҳ�������߼��ߵ���
            if (arr[j].price < arr[j+1].price || (arr[j].price == arr[j+1].price && arr[j].pages > arr[j+1].pages)) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// ��ȡ�ļ���ͼ����Ϣ������ʵ�ʶ�ȡ��ͼ������
int readBooks(struct Book arr[]) {
    FILE *fp;
    int count = 0;
    // ����3���ļ���ģʽ���󣨶��ı��ļ�Ӧʹ��"r"������"rb"��
    if (!(fp = fopen("books.txt", "r"))) {
        printf("�޷����ļ���\n");
        return -1;
    }
    // ����4��fscanf��ʽ���Ʒ������������ܺ��ո�%s�޷���ȡ������
    while (fscanf(fp, "%s %[^0-9] %f %d", arr[count].isbn, arr[count].name, &arr[count].price, &arr[count].pages) != EOF) {
        count++;
    }
    fclose(fp);
    return count;
}

// д��������ͼ����Ϣ���ļ�
void writeBooks(struct Book arr[], int n) {
    FILE *fp;
    if (!(fp = fopen("C:\\KS\\sorted_books.txt", "w"))) {
        printf("�޷������ļ���\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "ISBN��%s��������%s���۸�%.2f��ҳ����%d\n",
                arr[i].isbn, arr[i].name, arr[i].price, arr[i].pages);
    }
    fclose(fp);
}

int main(void) {
    struct Book books[N];
    int num = readBooks(books);
    if (num <= 0) return 1;
    sortBooks(books, num);
    printf("�����ͼ���б�\n");
    for (int i = 0; i < num; i++) {
        printf("ISBN��%s��������%s\b���۸�%.2f��ҳ����%d\n",
               books[i].isbn, books[i].name, books[i].price, books[i].pages);
    }
    writeBooks(books, num);
    return 0;
}
