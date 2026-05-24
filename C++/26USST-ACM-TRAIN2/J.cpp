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
    string choice[4];
    int len[4];
    for (int i = 0; i < 4; ++i)
    {
        cin >> choice[i];
        len[i] = choice[i].size() - 2;
    }
    int cnt = 0;
    char ans = 'C';

    for (int i = 0; i < 4; ++i)
    {
        bool lon = true;
        bool sho = true;
        for (int j = 0; j < 4; ++j)
        {
            if (i == j)
            {
                continue;
            }
            if (len[i] < 2 * len[j])
            {
                lon = false;
            }
            if (len[i] * 2 > len[j])
            {
                sho = false;
            }
        }
        if (lon || sho)
        {
            cnt++;
            ans = 'A' + i;
        }
    }
    if (cnt == 1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << 'C' << endl;
    }
    return 0;
}