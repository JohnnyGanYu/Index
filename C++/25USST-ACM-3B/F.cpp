#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for ( int i = 0; i < t; i++ )
    {
        int n;
        int cnt = 1, max = 0;
        cin >> n;
        char previous = getchar(), current;
        for ( int j = 0; j < n; j++ )
        {
            current = getchar();
            if ( previous == current )
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
            previous = current;
            if ( cnt > max )
            {
                max = cnt;
            }
        }
        cout << max+1 << endl;
    }
    return 0;
}