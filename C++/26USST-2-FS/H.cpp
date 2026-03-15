#include <iostream>
#include <vector>
#include <utility>
#define int long long
using namespace std;

signed main()
{
    int M, A, B, result = 0;
    cin >> M >> A >> B;
    vector<vector<int>> memo(M, vector<int>(M, 0));
    vector<vector<bool>> seen(M, vector<bool>(M, false));
    vector<pair<int, int>> path;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int current = i, next = j;
            path.clear();
            while (!seen[current][next] && current != 0 && memo[current][next] == 0)
            {
                seen[current][next] = true;
                path.push_back({current, next});
                int now = (A * next + B * current) % M;
                current = next;
                next = now;
            }
            if (current != 0 && (memo[current][next] == 2 || memo[current][next] == 0))
            {
                result++;
                while (!path.empty())
                {
                    pair<int, int> temp = path.back();
                    path.pop_back();
                    memo[temp.first][temp.second] = 2;
                }
            }
            else
            {
                while (!path.empty())
                {
                    pair<int, int> temp = path.back();
                    path.pop_back();
                    memo[temp.first][temp.second] = 1;
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}
