#include <iostream>
using namespace std;

int main(void)
{
    int t, n, m, temp, std;
    bool ans;
    cin >> t;
    while ( t-- )
    {
        ans = true;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> std;
            a[std % n] = i + 1;
            for (int j = 1; j < m; j++)          
            {
                cin >> temp;
                if ((temp - std) % n != 0 && ans)
                {
                    ans = false;
                }
                
            }
        }
        if (ans)
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }       
    }
    
}