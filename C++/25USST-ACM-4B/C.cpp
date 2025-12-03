#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        int b[m];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        int a;
        for (int i = 0; i < q; i++)
        {
            cin >> a;
        }
        int l1 = b[0] - a;
        int l2 = b[1] - a;
        if(l1 * l2 < 0)
        {
            cout << abs(l1-l2) << endl;
        }
        else
        {
            if (l1 > 0)
            {
                cout << (l1>l2)?b[1]:b[0] << endl;
            }
            else
            {
                cout << (l1>l2)?(n-b[1]):(n-b[0]) << endl;
            }
            
            
        }
        
        
    }
    
    return 0;
}