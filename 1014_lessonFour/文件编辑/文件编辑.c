#include <stdio.h>
#include <stdlib.h>

int rw( FILE *fp, int t);

int main()
{
    int i, o;

    FILE *fp1 = NULL, *fp2 = NULL;
    fp1 = fopen("t1.txt","w+");
     if  ( fp1 ){
            scanf("%d", &i);
            o=rw(fp1, i);
     }else{
        printf("文件打开失败");
        exit(0);
    }

    fp2 = fopen("t2.txt","w+");
     if  ( fp2 ){
            i = o + 100;
            o=rw(fp2, i);
            printf("%d", o);
     }else{
        printf("文件打开失败");
        exit(0);
    }


    return 0;
}

int rw( FILE *fp, int t)
{
    fprintf(fp, "%d", t);
    fseek(fp, 0, SEEK_SET);
    fscanf(fp, "%d", &t);
    //printf("%d", t);
    fclose(fp);

    return t;
}
