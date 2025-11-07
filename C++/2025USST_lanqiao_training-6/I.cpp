#include <iostream>
#include <ctype.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for (n; n > 0; n--)
    {
        char a[51];
        int i = 0;
        cin >> a;
        if (a[i] >= 'a'&&a[i] <= 'z')
            a[i] -= 32;
        for(i++;a[i];i++)
        {
            if (a[i] >= 'A'&&a[i] <= 'Z')
                a[i] += 32;
        }
        for(i = 0; a[i]; i++)
            cout << a[i];
        cout<<endl;
    }
    
	return 0;
}