#include <stdio.h>

void f(int *p);

int  main()
{
    int i=-1;
    int k=0;
    // f(&i); 
    int *p;
    p=&i;
    p[0]=3;
    printf("%d",*p);
    return 0 ;
}

// void f(int *p)
// {
//     *p =1;
// }