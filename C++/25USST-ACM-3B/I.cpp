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
                cout << n - i;
            }
            else
            {
                cout << i;
            }
       } 
       cout << endl;
       for ( int i = 0; i < n; i++ )
       {
            if ( i % 2 == 0 )
            {
                cout << n - i;
            }
            else
            {
                cout << i;
            }
       } 
    }
    

    return 0;
}