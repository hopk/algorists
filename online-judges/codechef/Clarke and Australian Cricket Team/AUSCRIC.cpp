/**
 * Problem: Clarke and Australian Cricket Team
 * Judge: Codechef
 * Date: 24/09/2017
 * URL: https://www.codechef.com/problems/AUSCRIC
 * Solved by: hopkins
 */

#include <iostream>
#include <bitset>
#include <utility>
#include <vector>
#include <unordered_set>

const int MAXN = 1005;
std::bitset< MAXN > deleted;
std::unordered_set<int> g[ MAXN ];

bool check(int n) {
    std::vector< std::pair<int, int> > ones;

    for (int i = 0; i < n ; ++i) {
        if (g[ i ].size() == 1) {
            ones.push_back( std::make_pair(i, *g[ i ].begin()) );
        }
    }

    bool flag = false;
    for (auto x : ones) {
        flag = true;
        g[ x.first ].clear();
        g[ x.second ].erase(x.first);
        deleted.set(x.first);
    }
    return flag;
}


int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        deleted.reset();

        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            g[ u ].insert( v );
            g[ v ].insert( u );
        }

        int ans = 0;
        while (check(n)) ans++;

        for (int i = 0; i < n; ++i) {
            g[ i ].clear();
        }
        std::cout << ans << '\n';
    }
    return 0;
}

