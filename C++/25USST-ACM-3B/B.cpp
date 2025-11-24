#include <iostream>
#define N 5
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for ( int i = 0; i < t; i++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        for ( int j = 0; j < N; j++ )
        {
            if ( a <= b && a <= c )
            {
                a++;
            }
            else if( b <= c )
            {
                b++;
            }
            else
            {
                c++;
            }
        }
        cout << a * b * c << endl;
    }
    return 0;
}