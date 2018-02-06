/**
 * Problem: B. Cookie Clicker Alpha
 * Judge: Codejam
 * Date: 30/01/2018
 * URL: https://code.google.com/codejam/contest/2974486/dashboard#s=p1
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <iomanip>
#include <algorithm>
const double EP = 1e-7;

double f(const int N, const double C, const double F, const double X) {
    double production = 2.0;
    double cookies = 0.0;
    double time = 0.0;

    for (int i = 0; i < N; ++i) {
        time += C / production;
        production += F;
    }

    time = time + X/production;
    return time;
}

double solve(const double C, const double F, const double X) {
    int left = 0, right = X;

    while (left + 2 < right) {
        int leftThird = left + (right  - left) / 3;
        int rightThird = right - (right - left + 1) / 3;
        if (f(leftThird, C, F, X) < f(rightThird, C, F, X)){
            right = rightThird;
        } else {
            left = leftThird;
        }
    }

    double ans = 1e9;
    while (left < right) {
        ans = min(ans, f(left, C, F, X));
        left++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.sol", "w", stdout);

    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        double C, F, X;
        cin >> C >> F >> X;
        double ans = solve(C, F, X);
        cout << "Case #" << caso << ": " << std::fixed << std::setprecision(7) << ans << '\n';
    }
    return 0;
}
