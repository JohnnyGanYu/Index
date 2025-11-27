#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        int x, k;
        cin >>  x >> k;
        if ( x % k != 0 )
        {
            cout << 1 << endl << x << endl;
        }
        else 
        {
            cout << 2 << endl << x - k - 1 << ' ' << k + 1 << endl;
        }
    }
    return 0;
}