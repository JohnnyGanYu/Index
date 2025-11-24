#include <iostream>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for ( int i = 0; i < t; i++ )
    {
        int n, k;
        cin >> n >> k;
        cout << ( n - 1 ) * k + 1 << endl;
    }
    return 0;
}