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
using namespace std;

string fun(int num)
{
    string c;
    c += (num & 4) ? 'r' : '-';
    c += (num & 2) ? 'w' : '-';
    c += (num & 1) ? 'x' : '-';
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string ans = fun(s[0] - '0') + fun(s[1] - '0') + fun(s[2] - '0');
        cout << ans << endl;
    }
    return 0;
}