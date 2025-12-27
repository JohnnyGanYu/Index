#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    int eaten = 0;
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'W') {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (grid[ni][nj] == 'P') {
                            eaten++;
                            grid[ni][nj] = '.';
                            break;
                        }
                    }
                }
            }
        }
    }
    
    cout << eaten << endl;
    
    return 0;
}