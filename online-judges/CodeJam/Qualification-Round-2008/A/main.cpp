/**
 * Problem: A. Saving the Universe
 * Judge: Codejam
 * Date: 15/11/2017
 * URL: https://code.google.com/codejam/contest/32013/dashboard#s=p0
 * Solved by: hopkins
 */

using namespace std;
#include <bits/stdc++.h>

int counting[ 1005 ];
int solve(const vector<int> &querys, const int s){
    memset(counting, 0, sizeof(counting));
    int used = 0;

    int ans = 0;
    for (int i=0; i < querys.size(); i++ ) {
        int x = querys[ i ];
        if (x == 0) continue;
        if (counting[x]) continue;
        if (counting[ x ] == 0){
            counting[ x ] = 1;
            used++;
        }

        if (used == s) {
            memset(counting, 0, sizeof(counting));
            used = 1;
            counting[ x ] = 1;
            ans++;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // freopen("test.01.in", "r", stdin);
    vector<int> querys;
    map<string, int> engine;
    int tc;
    cin >> tc;

    for (int caso = 0; caso < tc; caso++) {
        int s, q;
        string buff;
        engine.clear();
        querys.clear();
        
        cin >> s;
        cin.ignore();
        for (int i = 0; i < s; ++i) {
            getline(cin, buff);
            engine[ buff ] = i + 1;
        }

        cin >> q;
        cin.ignore();
        for (int i = 0; i < q; ++i) {
            getline(cin, buff);
            querys.push_back(engine[ buff ]);
        }

        int ans = solve(querys, s);
        cout << "Case #" << (caso+1) << ": " << ans << endl;
    }
    return 0;
}