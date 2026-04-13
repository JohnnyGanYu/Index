#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Function
{
    double a, b, c;
    double calc(double x) const
    {
        return a * x * x + b * x + c;
    }
};

int n;
vector<Function> funcs;

// 计算 F(x) = max(f_i(x))
double F(double x)
{
    double max_val = funcs[0].calc(x);
    for (int i = 1; i < n; ++i)
    {
        max_val = max(max_val, funcs[i].calc(x));
    }
    return max_val;
}

void solve()
{
    cin >> n;
    funcs.clear();
    for (int i = 0; i < n; ++i)
    {
        double a, b, c;
        cin >> a >> b >> c;
        funcs.push_back({a, b, c});
    }

    double L = 0.0, R = 1000.0;
    // 进行 100 次迭代，足以满足小数点后四位的精度要求
    for (int i = 0; i < 100; ++i)
    {
        double m1 = L + (R - L) / 3.0;
        double m2 = R - (R - L) / 3.0;
        if (F(m1) < F(m2))
        {
            R = m2; // 最小值在左侧区域
        }
        else
        {
            L = m1; // 最小值在右侧区域
        }
    }

    // 输出结果，保留四位小数
    cout << fixed << setprecision(4) << F(L) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}