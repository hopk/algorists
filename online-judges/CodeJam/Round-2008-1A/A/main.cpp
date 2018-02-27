/**
 * Problem: A. Minimum Scalar Product
 * Judge: Codejam
 * Date: 27/02/2018
 * URL: https://code.google.com/codejam/contest/32016/dashboard#s=p0                                                              
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

long long solve(vector<long long> &a, vector<long long> &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    const int n = (int)a.size();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[ i ] * b[n - i - 1];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("input.txt", "r", stdin);
    // freopen("A-large-practice.in", "r", stdin);
    // freopen("A-large-practice.sol", "w", stdout);
    
    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        int n;
        cin >> n;
        vector<long long> a(n), b(n);
        for (long long &x: a) cin >> x;
        for (long long &x: b) cin >> x;

        cout << "Case #" << caso << ": " << solve(a, b) << '\n';
    }
    return 0;
}


