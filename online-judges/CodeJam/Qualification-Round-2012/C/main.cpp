/**
 * Problem: C. Recycled Numbers
 * Judge: Codejam
 * Date: 17/01/2018
 * URL: https://code.google.com/codejam/contest/1460488/dashboard#s=p2&a=2
 * Solved by: hopkins
 */

#include <iostream>

using namespace std;
typedef long long LL;

int solve(int A, int B){
    char s[ 20 ];

    int ans = 0;
    for (int x = A; x <= B; ++x) {
        int c = (sprintf(s, "%d%d", x, x)) >> 1;

        for (int i = 1; i < c; ++i) {
            int actual = 0;
            for (int j = 0; j < c; ++j) {
                actual = actual * 10 + s[i + j] - '0';
            }

            if (actual == x) break;
            if (A <= actual && actual <= B){
                ans++;
            }
        }
    }
    return ans / 2;
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(0);cin.tie(0);

    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        int A, B;
        cin >> A >> B;
        cout << "Case #" << caso << ": " << solve(A, B) << '\n';
    }
    return 0;
}
