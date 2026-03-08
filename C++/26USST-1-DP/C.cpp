#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(N);
    vector<int> d(N, 0);
    vector<int> e(N, 0);
    vector<int> f(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    d[0] = a[0];
    e[0] = b[0];
    f[0] = c[0];
    for (int i = 1; i < N; i++)
    {
        d[i] = max(e[i-1], f[i-1]) + a[i];
        e[i] = max(d[i-1], f[i-1]) + b[i];
        f[i] = max(e[i-1], d[i-1]) + c[i];
    }
    cout << max(max(d[N-1], e[N-1]), f[N-1]);

    return 0;
}