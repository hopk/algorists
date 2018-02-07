/**
 * Problem: B. Infinite House of Pancakes
 * Judge: Codejam
 * Date: 06/02/2018
 * URL: https://code.google.com/codejam/contest/6224486/dashboard#s=p1
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <queue>
#include <algorithm>

int solve(std::vector<int> q, const int n) {
    int ans = 10000000;

    for (int i = 1; i <= 1000; ++i) {
        int c = 0;

        for (int j = 0; j < n; ++j) {
            c += (q[ j ] - 1) / i;
        }
        if (c + i < ans) {
            ans = c + i;
        }
    }

    return ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.sol", "w", stdout);

    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        int d;
        cin >> d;
        std::vector<int> v(d);

        for (int i = 0; i < d; ++i) {
            cin >> v[ i ];
        }

        cout << "Case #" << caso << ": " << solve(v, d) << '\n';
    }
    return 0;
}
