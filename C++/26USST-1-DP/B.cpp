#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    vector<int> a(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i < N; i++)
    {
        a[i] = abs(h[i-1]-h[i])+a[i-1];
        for (int j = 1; j <= K; j++)
        {
            a[i] = min(a[i], abs(h[i]-h[i-j])+a[i-j]);
            if (i<=j)
            {
                break;
            }
        }
        
    }
    cout << a[N-1];
}