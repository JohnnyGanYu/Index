#include <iostream>
#include <ctype.h>
using namespace std;

int main(void)
{
    char a[51];
    int i = 0;
    cin >> a;
    for(;a[i];i++)
    {
        if (a[i] >= 'a'&&a[i] <= 'z')
            a[i] -= 32;
        else if (a[i] >= 'A'&&a[i] <= 'Z')
            a[i] += 32;
        if (a[i] >= 'a'&&a[i] <= 'w'|| a[i] >= 'A'&&a[i] <= 'W')
            a[i] += 3;
        else if (a[i] >= 'x'&&a[i] <= 'z'|| a[i] >= 'X'&&a[i] <= 'Z')
            a[i] -= 23;;
    }
    for(i--; i >= 0; i--)
        cout<<a[i];
    cout<<endl;

	return 0;
}