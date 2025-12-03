/* ???????*/ 
#include <stdio.h>


void line(int start,int end ) ;
void point(int start,int end ) ;
void triangle(int n, int leftMargin); 


int main()
{
	int n;
    printf("n=");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        triangle(n, 3 + 2 * i);
    }
    
    printf("????\n");
    
    return 0;
}


/*
*????????
*/
void triangle(int n, int leftMargin) {
    if (n <= 0) return;

    for (int i = 0; i < leftMargin; i++) printf(" ");
    for (int i = 0; i < n - 1; i++) printf(" ");  
    line(1, 1);

    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < leftMargin; j++) printf(" ");
        for (int j = 0; j < n - i - 1; j++) printf(" ");
        point(1, 2 * i + 1);
    }

    if (n > 1) {
        for (int i = 0; i < leftMargin; i++) printf(" ");
        line(1, 2 * n - 1);
    }
}


/*
*????start???end????*?????
*/
void line(int start,int end ) 
{ 
	int i;
	for(i=1;i<start;i++)   //?start-1???
		printf(" ");   
	for(i=start;i<=end;i++)//?*?????
		printf("*");
	printf("\n");        //??
}


/*
*????start?end????????????
*/
void point(int start,int end ) 
{  
	int i;
	for(i=1;i<start;i++)   //?start-1???
		printf(" ");  
	
	printf("*");//????
	
	for(i=start+1;i<end;i++)//?*?????
		printf(" ");//????
	printf("*\n") ;       //??
}