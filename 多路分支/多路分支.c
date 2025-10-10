#include <stdio.h>

int main()
{ 
    //初始化
    double x;
    double y;
    int type;
    
    //读入自变量x
    printf("请输入自变量x:");
    scanf("%lf",&x);

    //判断类型
    type = ( x > 0 ) - ( x < 0 );

    //计算函数值
    switch ( type ) {
        case  1: y = 2 * x; break;
        case  0: y = 0; break;
        case -1: y = -1; break;
    }

    //输出函数值
    printf("f(x) = %lf\n", y);

    return 0;
}
