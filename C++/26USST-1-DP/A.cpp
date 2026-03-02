#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    vector<int> a(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }
    a[1] = abs(h[0]-h[1]);
    for (int i = 2; i < N; i++)
    {
        a[i] = min(abs(h[i-1]-h[i])+a[i-1], abs(h[i]-h[i-2])+a[i-2]);
    }
    cout << a[N-1];
}