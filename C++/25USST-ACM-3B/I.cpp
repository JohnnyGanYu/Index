#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while ( t-- )
    {
       int n;
       cin >> n;
       for ( int i = 0; i < n; i++ )
       {
            if ( i % 2 == 0 )
            {
                cout << 2 * n - i - 1;
            }
            else
            {
                cout << i;
            }
            cout << ' ';
       } 
       cout << endl;
       for ( int i = 0; i < n - 1; i++ )
       {
            if ( i % 2 != 0 )
            {
                cout << 2 * n - i - 1;
            }
            else
            {
                cout << i + 2;
            }
            cout << ' ';
       } 
       cout << 2 * n;
       cout << endl;
    }
    

    return 0;
}