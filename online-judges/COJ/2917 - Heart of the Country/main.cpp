/**
 * Problem: 2917 - Heart of the Country
 * Judge: Caribbean Online Judge
 * Date: 24/09/2017
 * URL: http://coj.uci.cu/24h/problem.xhtml?pid=2917
 * Solved by: hopkins
 */
#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>
#include <unordered_set>

const int MAXN = 1005;

std::bitset< MAXN > deleted;
int quartered [ MAXN ];
int all_troops[ MAXN];
std::unordered_set< int > g[ MAXN ];


bool check(const int n, const int k){
    std::vector<int> to_delete;

    for (int i = 0; i < n; ++i) {
        if (!deleted.test(i) && all_troops[ i ] < k) {
            to_delete.push_back(i);
            deleted.set(i);
        }
    }

    for (const int &to_d : to_delete) {
        for (const int x : g[ to_d ]) {
            all_troops[ x ] -= quartered[ to_d ];
            g[ x ].erase(to_d);
        }
    }

    return (to_delete.size() > 0);
}

int main(int argc, char const *argv[]) {
    int n , k;
    while (std::cin >> n >> k, n && k) {
        std::memset(all_troops, 0, sizeof(all_troops));
        deleted.reset();

        for (int i = 0; i < n; ++i)
            g[ i ].clear();

        for (int i = 0; i < n; ++i) {
            int m, v;
            std::cin >> quartered[ i ] >> m;
            for (int j = 0; j < m; ++j) {
                std::cin >> v;
                g[ i ].insert( v );
                g[ v ].insert( i );
            }
        }

        for (int u = 0; u < n; u++) {
            int cont = quartered[ u ];
            for (const int &v : g[ u ])
                cont += quartered[ v ];

            all_troops[ u ] = cont;
        }

        while (check(n, k));

        int nodes = 0, troops = 0;
        for (int i = 0; i < n; ++i) {
            if (deleted.test(i) == false) {
                troops += quartered[ i ];
                nodes ++;

            }
        }

        std::cout << nodes << ' ' << troops << '\n';
    }
    return 0;
}
