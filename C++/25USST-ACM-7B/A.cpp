#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> arr;
    queue<long long> q;   

    q.push(4);
    q.push(7);

    while (!q.empty()) {
        long long num = q.front();
        q.pop();
        if (num > 10000000000LL) continue;
        arr.push_back(num);
        q.push(num * 10 + 4);
        q.push(num * 10 + 7);
    }

    sort(arr.begin(), arr.end());

    long long l, r;
    cin >> l >> r;

    long long result = 0;
    long long prev = l;
    for (long long lucky : arr) {
        if (lucky > r) {
            result += (r - prev + 1) * lucky;
            break;
        }
        if (lucky >= prev) {
            result += (lucky - prev + 1) * lucky;
            prev = lucky + 1;
        }
    }

    cout << result << "\n";

    return 0;
}