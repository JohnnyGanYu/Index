#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> adjacent(200020);
int cnt = 0;
vector<bool> visited(200020, 0);
void dfs(int cur) {
    cnt++;
    visited[cur] = 1;
    if (cnt >= 1000000) return;
    for (int i : adjacent[cur]) {
        if (visited[i]) continue;
        dfs(i);
    }
    visited[cur] = 0;
}

int main() {
    int N, M;
    int u, v;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    
    dfs(1);
    cout << min(cnt, 1000000) <<endl;
    return 0;
}