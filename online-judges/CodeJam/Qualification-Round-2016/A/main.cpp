/**
 * Problem: A. Counting Sheep
 * Judge: Codejam
 * Date: 13/02/2018
 * URL: https://code.google.com/codejam/contest/6254486/dashboard#s=p0
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <vector>


bool check(const std::vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[ i ] == 0) return false;
    }
    return true;
}

long long solve(long long x) {
    if (x == 0){
        return -1;
    }
    std::vector<int> v(10, 0);

    long long n = 0;
    while (!check(v)) {
        n += x;

        long long y = n;
        while (y) {
            v[ y%10LL ]++;
            y /= 10LL;
        }
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
        long long int n;
        cin >> n;
        long long ans = solve(n);

        cout << "Case #" << caso << ": ";
        if (ans < 0){
            cout << "INSOMNIA\n";
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}
