#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    char str[100];
    int i=0;
    if((fp=fopen("test.txt","r"))==NULL)
    {
        printf("can't open this file.\n");
        exit(0);
    }
    printf("ÊäÈë:");
    gets(str);
    while (str)
    {
        if(str[i]>='a' && str[i]<='z')
            str[i]=str[i]+32;
        fputc(str[i],fp);
        i++;
    }
    printf("%s\n",str);
    fclose(fp);
    return 0;
}
