// Hopkins
// COJ: 2927 - Jorge's Party
// URL: http://coj.uci.cu/24h/problem.xhtml?pid=2927

using namespace std;
#include <bits/stdc++.h>
#define MAXN 1005
#define NOVISIT 0
#define BLACK  1
#define WHITE  2

vector<int> g[ MAXN ];
int visitados[ MAXN ];
int n;

bool check(int vert){
    queue <int>q;
    visitados[ vert ] = BLACK;
    q.push(vert);

    bool ban = true;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        int nextColor = 3 - visitados[ v ];

        for (auto u: g[ v ]) {
            if (visitados[ u ] == NOVISIT) {
                visitados[ u ] = nextColor;
                q.push(u);
            } else if (visitados[ u ] != nextColor){
                ban = false;
            }
        }
    }
    return ban;
}


int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);

    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[ u ].push_back(v);
        g[ v ].push_back(u);
    }

    bool ans = true;
    for (int i = 0; i < n; ++i)
    {
        if (visitados[ i ] == NOVISIT){
            if (check(i) == false){
                ans = false;
                break;
            }
        }
    }

    cout << (ans?"YES":"NO") << endl;
    return 0;
}
