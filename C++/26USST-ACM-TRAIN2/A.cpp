#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <climits>
// 按需增删
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int u = 0; u < m; u++)
    {
        cout << 1;
    }
    cout << endl;
    int tag = 0, ntag = 0, mtag = 0;
    if (n % 2 == 1)
        ntag = 1;
    if (m % 2 == 1)
        mtag = 1;
    int ztag = 0;
    if (ntag == 1 && mtag == 1)
    {
        int cc = 0;
        for (int i = 0; i < n - 2; i++)
        {
            cout << 1;
            for (int j = 0; j < m - 2; j++)
            {

                if (j % 2 == tag)
                {
                    if (i % 2 == 1 && (j == i || (i >= m - 2 && j == m - 4) || (j >= n - 2 && i == n - 4)))
                    {
                        cout << "+";
                    }
                    else
                        cout << "*";
                }
                else
                    cout << "1";
            }
            //    if(cc<m-4&&cc<n-4)cc++;
            //    else  ztag=1;
            cout << 1;
            if (tag == 0)
                tag = 1;
            else
                tag = 0;
            cout << endl;
        }
        // cout<<cc;
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            if (ntag == 1 && i == 1)
            {
                cout << 1;
                for (int j = 0; j < m - 2; j++)
                {
                    if (j % 2 == tag)
                        cout << "+";
                    else
                        cout << "1";
                }
                cout << 1;
                if (tag == 0)
                    tag = 1;
                else
                    tag = 0;
                cout << endl;
            }
            else
            {
                cout << 1;
                for (int j = 0; j < m - 2; j++)
                {
                    if (mtag == 1 && j == 1)
                    {
                        if (j % 2 == tag)
                            cout << "+";
                        else
                            cout << "1";
                    }
                    else
                    {
                        if (j % 2 == tag)
                            cout << "*";
                        else
                            cout << "1";
                    }
                }
                cout << 1;
                if (tag == 0)
                    tag = 1;
                else
                    tag = 0;
                cout << endl;
            }
        }
    }
    for (int u = 0; u < m; u++)
    {
        cout << 1;
    }
    cout << endl;
}