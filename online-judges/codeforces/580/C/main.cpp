/**
 * Problem: C. Kefa and Park
 * Judge: CodeForces
 * Date: 20/09/2017
 * URL: http://codeforces.com/contest/580/problem/C
 */

#include <iostream>
#include <vector>

const int MAX_NODES = 100005;
std::vector< int > g[ MAX_NODES ];
bool are_cats[ MAX_NODES ];
int allow_cats;

int dfs(int node, int p, int cats) {
    if (cats > allow_cats) return 0;

    int visited = 0;
    int ret = 0;

    for (const int &next : g[ node ]) {
        if (next == p) continue;
        visited++;

        int ncats = (are_cats[ next ])?cats + are_cats[ next ]:0;
        ret += dfs(next, node, ncats);
    }

    if (visited == 0) return 1;
    return ret;
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m, op;
    std::cin >> n >> allow_cats;
    for (int i = 0; i < n; ++i) {
        std::cin >> op;
        are_cats[i + 1] = (op & 1);
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[ u ].push_back( v );
        g[ v ].push_back( u );
    }

    std::cout << dfs(1, 0, are_cats[ 1 ]) << '\n';
    return 0;
}
