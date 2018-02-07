/**
 * Problem: A. Standing Ovation
 * Judge: Codejam
 * Date: 06/02/2018
 * URL: https://code.google.com/codejam/contest/6224486/dashboard#s=p0
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <iomanip>
#include <algorithm>

int solve(const std::string &s, const int n) {
    
    for (int prop = 0; prop < n; prop++) {
        int c = s[ 0 ] - '0' + prop;
        bool flag = true;
        
        for (int i = 1; i <= n; ++i) {
            if (c < i) {
                flag = false;
                break;
            }
            c += s[ i ] - '0';
        }
        if (flag)
            return prop;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.sol", "w", stdout);

    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        int n;
        string s;
        cin >> n >> s;
        // cout << n << " " << s << "=";

        cout << "Case #" << caso << ": " << solve(s, n) << '\n';
    }
    return 0;
}
