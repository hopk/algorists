/**
 * Problem: B. Revenge of the Pancakes
 * Judge: Codejam
 * Date: 13/02/2018
 * URL: https://code.google.com/codejam/contest/6254486/dashboard#s=p1
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <vector>


int solve(const string &s) {
    const int n = (int) s.size();
    std::vector<bool> p(n);

    for (int i = 0; i < n; ++i) {
        p[ i ] = (s[ i ] == '+');
    }

    int ret = 0;
    for (int i = 1; i < n; ++i) {
        if (p[ i ] != p[i - 1]) {
            for (int j = 0; j < i; ++j) {
                p[ j ] = !p[ j ];
            }
            ret++;
        }
    }
    if (p[n - 1] == 0) ret ++;
    return ret;
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
        string s;
        cin >> s;

        cout << "Case #" << caso << ": " << solve(s) << '\n';
    }
    return 0;
}
