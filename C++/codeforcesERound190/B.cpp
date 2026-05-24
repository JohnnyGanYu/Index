#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = (int)s.size();
        int total13 = 0;
        for (char c : s)
        {
            if (c == '1' || c == '3')
                total13++;
        }
        int cur2 = 0, seen13 = 0;
        int max_keep = total13;
        for (char c : s)
        {
            if (c == '2')
                cur2++;
            else if (c == '1' || c == '3')
                seen13++;
            max_keep = max(max_keep, cur2 + (total13 - seen13));
        }
        cout << n - max_keep << '\n';
    }
    return 0;
}