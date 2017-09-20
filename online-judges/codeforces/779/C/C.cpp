/**
 * Problem: C. Dishonest Sellers
 * Judge: CodeForces
 * Date: 19/09/2017
 * URL: http://codeforces.com/contest/779/problem/C
 */

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

int a[ 200005 ];
int b[ 200005 ];
int c[ 200005 ];

bool cmp(int i, int j) {
    return (a[ i ] - b[ i ]) < (a[ j ] - b[ j ]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[ i ];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[ i ];
    }
    for (int i = 0; i < n; ++i) {
        c[ i ] = i;
    }

    sort(c, c + n, cmp);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (i < k || a[ c[i] ] < b[ c[i] ])?a[ c[i] ]:b[ c[i] ];
    }
    cout << ans << "\n";
    return 0;
}
