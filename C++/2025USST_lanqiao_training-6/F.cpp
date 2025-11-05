#include <iostream>
#include <string.h>
#include <stdbool.h>
using namespace std;

int main(void)
{
    int n;
    int m;
    int i;
    int cnt = 0;

    cin >> n >> m;

    bool isclosed[n+1];
    int closed[n];
    memset(isclosed, true, (n+1) * sizeof(bool)) ;
    memset(isclosed, false, (m+1) * sizeof(bool)) ;

    for (i = 1; i*i <= m; i++)
    {
        isclosed[i*i] = true;
    }

    for (i = m + 1; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (i % j == 0)
            {
                isclosed[i] = !isclosed[i];
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        if (isclosed[i])
        {
            closed[cnt++] = i;
        }
    }

    if (cnt == 0)
    {
        return 0;
    } 

    cout << closed[0];
    for (i = 1; i < cnt; i++)
    {
        cout << ',';
        cout << closed[i];
    }
    cout << endl;

    return 0;
}