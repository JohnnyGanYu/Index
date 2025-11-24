#include <iostream>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for ( int i = 0; i < t; i++ )
    {
        int n;
        cin >> n;
        n /= 2;
        if ( n % 2 )
        {
            n = n / 2 + 1;
        }
        else
        {
            n = n / 2;
        }
        cout << n << endl;
    }

    return 0;
}