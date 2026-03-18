#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9;
const int K = 30;
const int LIMIT = 10000;

int n, m, q;
vector<int> adj[MAXN];

int comp[MAXN];
int comp_size[MAXN];
vector<int> comp_nodes[MAXN];
int num_comp = 0;

int dist[MAXN];
int from[MAXN];
int saved_dist[MAXN];
int saved_from[MAXN];

void build_components() {
    memset(comp, -1, sizeof(comp));
    for (int i = 1; i <= n; i++) {
        if (comp[i] == -1) {
            queue<int> bfsq;
            bfsq.push(i);
            comp[i] = num_comp;
            comp_size[num_comp] = 1;
            comp_nodes[num_comp].push_back(i);
            while (!bfsq.empty()) {
                int v = bfsq.front(); bfsq.pop();
                for (int u : adj[v]) {
                    if (comp[u] == -1) {
                        comp[u] = num_comp;
                        comp_size[num_comp]++;
                        comp_nodes[num_comp].push_back(u);
                        bfsq.push(u);
                    }
                }
            }
            num_comp++;
        }
    }
}

void bfs_large_comp(vector<int>& bases) {
    fill(dist + 1, dist + n + 1, INF);
    fill(from + 1, from + n + 1, -1);
    
    queue<int> bfsq;
    for (int s : bases) {
        dist[s] = 0;
        from[s] = s;
        bfsq.push(s);
    }
    
    while (!bfsq.empty()) {
        int v = bfsq.front(); bfsq.pop();
        for (int u : adj[v]) {
            if (dist[u] == INF) {
                dist[u] = dist[v] + 1;
                from[u] = from[v];
                if (dist[u] < LIMIT) {
                    bfsq.push(u);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    build_components();
    
    for (int c = 0; c < num_comp; c++) {
        if ((int)comp_nodes[c].size() > 20000) {
            vector<int> bases;
            for (int i = 0; i < K; i++) {
                bases.push_back(comp_nodes[c][rand() % comp_nodes[c].size()]);
            }
            bfs_large_comp(bases);
            for (int v : comp_nodes[c]) {
                saved_dist[v] = dist[v];
                saved_from[v] = from[v];
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        
        if (comp[x] != comp[y]) {
            cout << "YES\n";
        } else if ((int)comp_nodes[comp[x]].size() <= 20000) {
            cout << "NO\n";
        } else {
            if (saved_dist[x] <= LIMIT && saved_dist[y] <= LIMIT && saved_from[x] == saved_from[y]) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
    
    return 0;
}
