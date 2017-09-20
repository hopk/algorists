/**
 * Problem: 12144 Almost Shortest Path
 * Judge: UVa Online Judge
 * Date: 31/08/2017
 * URL: https://uva.onlinejudge.org/external/121/12144.pdf
 * Solved by: hopkins <https://github.com/hopkins0>
 */

#include <bits/stdc++.h>
using namespace std;
#define INF 0x77FFFF

const int MAXN = 505;
int g[ MAXN ][ MAXN ];
int dist[ MAXN ];
vector<int> parents[ MAXN ];

void dijkstra(int n,int source, int stink) {
    for (int i=0; i < MAXN; i++) {
        dist[ i ] = INF;
        parents[ i ].clear();
    }

    set< pair<int, int> > q;
    dist[ source ] = 0;
    q.insert(make_pair(0, source));

    while (!q.empty()) {
        int w = q.begin()->first;
        int u = q.begin()->second;
        q.erase(q.begin());

        for (int v = 0; v < n; v++) if (g[ u ][ v ]){
            int nw = w + g[ u ][ v ];

            if (nw < dist[ v ]) {
                q.erase(make_pair(dist[ v ], v));
                dist[ v ] = nw;
                q.insert(make_pair(dist[ v ], v));

                parents[ v ].clear();
                parents[ v ].push_back(u);
            } else if (nw == dist[ v ]) {
                parents[ v ].push_back(u);
            }
        }
    }
}

void limpiar(int u){
    if (parents[ u ].size() == 0) return;
    for (int i = 0; i < parents[ u ].size(); ++i) {
        limpiar(parents[ u ][ i ]);
        g[ parents[u][i] ][ u ] = 0;
    }
    parents[ u ].clear();
}


int main(int argc, char const *argv[]) {
    int n, m, s, d;

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> s >> d;
        memset(g, 0, sizeof(g));

        for (int i=0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            g[ u ][ v ] = p;
        }

        dijkstra(n, s, d);
        limpiar(d);
        dijkstra(n, s, d);

        if (dist[ d ] < INF) cout << dist[ d ] << '\n';
        else cout << "-1\n";
    }


    return 0;
}
