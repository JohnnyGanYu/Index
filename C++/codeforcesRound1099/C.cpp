#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<pair<int, int>> events;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    events.clear();

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int steps = 0;
        while (true)
        {
            events.push_back({x, steps});
            if (x == 1)
            {
                events.push_back({2, steps + 1});
                break;
            }
            if (x == 2)
            {
                events.push_back({1, steps + 1});
                break;
            }
            if (x % 2 == 0)
                x /= 2;
            else
                x += 1;
            steps++;
        }
    }

    sort(events.begin(), events.end());

    long long min_ops = -1;
    int m = events.size();
    for (int i = 0; i < m;)
    {
        int j = i;
        long long current_steps = 0;
        int count = 0;
        while (j < m && events[j].first == events[i].first)
        {
            current_steps += events[j].second;
            count++;
            j++;
        }
        if (count == n)
        {
            if (min_ops == -1 || current_steps < min_ops)
            {
                min_ops = current_steps;
            }
        }
        i = j;
    }

    cout << min_ops << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    events.reserve(7000000);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}