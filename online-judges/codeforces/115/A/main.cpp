/**
 * Problem: A. Party
 * Judge: CodeForces
 * Date: 20/09/2017
 * URL: http://codeforces.com/contest/115/problem/A
 */

#include <iostream>
#include <algorithm>
#include <vector>
typedef long long LL;

const int MAX_NODES = 2005;
std::vector< int > g[ MAX_NODES ];
int dist[ MAX_NODES ];

int dfs(int node) {
    int ret = 0;
    for (int v : g[ node ]) {
        ret = std::max(ret, 1 + dfs(v));
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, x;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (x == -1) x = 0;
        g[ x ].push_back(i + 1);
    }

    std::cout << dfs(0) << '\n';

    return 0;
}
