#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adjacent(N + 5);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
    }
    int S, T;
    cin >> S >> T;
    vector<vector<int>> dist(N + 5, vector<int>(3));
    queue<pair<int, int>> status;
    dist[S][0] = 0;
    status.push({S, 0});
    int ans = 0;
    while (!status.empty())
    {
        int x = status.front().first;
        int y = status.front().second;
        status.pop();
        if (x == T && y == 0)
        {
            cout << dist[x][y] / 3 << endl;
            return 0;
        }
        for (int i : adjacent[x])
        {
            if (!dist[i][(y + 1) % 3])
            {
                status.push({i, (y + 1) % 3});
                dist[i][(y + 1) % 3] = dist[x][y] + 1;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}