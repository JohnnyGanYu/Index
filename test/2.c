#include <stdio.h>
int main(void)
{
	int a, b;
	printf("请输入a,b:");
	scanf("%d%d", &a, &b);
	if (b != 0)
		printf("%d/%d=%d\n", a, b, a / b);
	else
		printf("除数不能等于0\n");
	return 0;
}