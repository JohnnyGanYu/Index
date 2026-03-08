#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    vector<vector<int>> b(H, vector<int>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> a[i][j];
        }
    }
    b[0][0] = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 && j == 0) continue;
            if (a[i][j] == '#') {
                b[i][j] = 0;
                continue;
            }
            if (i > 0) {
                b[i][j] = (b[i][j] + b[i-1][j]) % MOD;
            }
            if (j > 0) {
                b[i][j] = (b[i][j] + b[i][j-1]) % MOD;
            }
        }
    }
    cout << b[H-1][W-1] << endl;
    return 0;
    return 0;
}