/**
 * Problem: C. Recycled Numbers
 * Judge: Codejam
 * Date: 17/01/2018
 * URL: https://code.google.com/codejam/contest/1460488/dashboard#s=p2&a=2
 * Solved by: hopkins
 */

#include <iostream>
#include <algorithm>
typedef long long LL;

const int MAXN = 105;
const int MAX_VALUE = 1001;

int a[ MAXN ][ MAXN ];
int color[ MAXN ][ MAXN ];

std::string solve(int N, int M){
    // Color the rows
    for (int i = 0; i < N; ++i) {
        int max = 0;
        for (int j = 0; j < M; j++) {
            max = std::max(max, a[ i ][ j ]);
        }

        for (int j = 0; j < M; j++) {
            color[ i ][ j ] = max;
        }
    }

    // Color the columns
    for (int j = 0; j < M; j++) {
        int max = 0;
        for (int i = 0; i < N; ++i) {
            max = std::max(max, a[ i ][ j ]);
        }

        for (int i = 0; i < N; ++i) {
            color[ i ][ j ] = std::min(color[i][j], max);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; j++) {
            if (a[ i ][ j ] != color[ i ][ j ]) return "NO";
        }
    }
    return "YES";
}

int main(int argc, char const *argv[])
{
    // std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    // freopen("input.txt", "r", stdin);
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.sol", "w", stdout);

    int tc;
    std::cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        int N, M;
        std::cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; j++) {
                std::cin >> a[ i ][ j ];
            }
        }
        std::cout << "Case #" << caso << ": " << solve(N, M) << '\n';
    }
    return 0;
}
