#include <iostream>
#include <vector>
#include <map>
#define int long long
using namespace std;

vector<vector<int>> adjacent(200020);
vector<int> A(200020);
vector<int> visited(200020, 0);
vector<int> ans(200020, 1);
map<int, int> number;

void dfs(int cur)
{
    visited[cur] = 1;
    if (number[A[cur]] > 0)
    {
        ans[cur] = 0;
    }
    number[A[cur]]++;
    for (int i : adjacent[cur])
    {
        if (visited[i])
            continue;
        if (ans[cur] == 0)
        {
            ans[i] = 0;
        }
        dfs(i);
    }
    number[A[cur]]--;
    visited[cur] = 0;
}

signed main()
{
    int N, u, v;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= N; i++)
    {
        cout << (ans[i] ? "No" : "Yes") << endl;
    }

    return 0;
}