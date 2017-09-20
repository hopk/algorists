/**
 * Problem: A. Pupils Redistribution
 * Judge: CodeForces
 * Date: 20/09/2017
 * URL: http://codeforces.com/contest/779/problem/A
 */

#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

inline int myabs(int x) {
    return (x < 0)?-x:x;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    std::vector<int> fa(5, 0);
    std::vector<int> fb(5, 0);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        fa[x - 1]++;
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        fb[x - 1]++;
    }

    int ans = 0;
    int lp = 0, rp = 0;

    for (int i = 0; i < 5; ++i) {
        if ((fa[ i ] + fb[ i ]) %2 != 0) {
            cout << -1 << "\n";
            return 0;
        }

        ans += myabs(fa[ i ] - fb[ i ]) / 2;
    }

    cout << ans/2 << "\n";

    return 0;
}
