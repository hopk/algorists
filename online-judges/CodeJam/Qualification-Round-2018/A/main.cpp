/**
 * Problem: A. Saving the Universe Again
 * Judge: Codejam
 * Date: 07/04/2017
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <algorithm>

long long check(const string &s) {
    long long load = 1;
    long long damage = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[ i ] == 'C') load <<= 1LL;
        else damage += load;
    }
    return damage;
}

int solve(string s, long long D) {
    int ans = 0,
        iter = (int)s.size() * (int)s.size();

    while (check(s) > D && iter-- > 0) {
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            if (s[ i ] == 'S') {
                if (i > 0 && s[i - 1] == 'C') {
                    swap(s[i], s[i - 1]);
                    ans++;
                    break;
                }
            }
        }
    }
    return (check(s) > D)? -1: ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        long long D;
        string buff;
        cin >> D >> buff;

        int ans = solve(buff, D);

        cout << "Case #" << caso << ": ";
        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }
    return 0;
}
