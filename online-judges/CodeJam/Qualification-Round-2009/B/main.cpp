/**
 * Problem: B. Watersheds
 * Judge: Codejam
 * Date: 17/11/2017
 * URL: https://code.google.com/codejam/contest/90101/dashboard#s=p1
 * Solved by: hopkins
 */

using namespace std;
#include <bits/stdc++.h>

const int MAXN = 105;
const int mov[][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int g[ MAXN ][ MAXN ];
int color[ MAXN ][ MAXN ];
int H, W;


int dfs(int R, int C, int c){
    queue< pair<int, int> > q, repaint;
    q.push(make_pair(R, C));
    int pastColor = -1;

    while (!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        repaint.push(make_pair(row, col));
        color[ row ][ col ] = c;
        int minrow = row, mincol = col;
        int minval = 1 << 20;

        for (int k = 0; k < 4; k++ ) {
            int nrow = row + mov[ k ][ 0 ];
            int ncol = col + mov[ k ][ 1 ];

            if (nrow < 0 || nrow >= H) continue;
            if (ncol < 0 || ncol >= W) continue;
            if (g[ nrow ][ ncol ] < g[ row ][ col ] && g[ nrow ][ ncol ] < minval){
                minval = g[ nrow ][ ncol ];
                minrow = nrow;
                mincol = ncol;
            }
        }

        if (minval < (1 << 20)){
            if (color[ minrow ][ mincol ] == -1){
                q.push(make_pair(minrow, mincol));
            } else {
                pastColor = color[ minrow ][ mincol ];
            }
        }
    }

    if (pastColor > 0){
        while (!repaint.empty()){
            int row = repaint.front().first;
            int col = repaint.front().second;
            color[ row ][ col ] = pastColor;
            repaint.pop();
        }
        c = c -1;
    }


    return c + 1;
}
int main(int argc, char const *argv[])
{
    // freopen("B-small-practice.in", "r", stdin);
    // freopen("B-small-practice.sol", "w", stdout);
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.sol", "w", stdout);
    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; caso++) {
        memset(color, -1, sizeof(color));
        cin >> H >> W;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; j++) {
                cin >> g[ i ][ j ];
            }
        }

        int c = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; j++) {
                if (color[ i ][ j ] == -1) {
                    c = dfs(i, j, c);
                }
            }
        }

        cout << "Case #" << caso <<":\n";
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; j++) {
                if (j) cout << ' ';
                cout << (char)('a' + color[ i ][ j ]);
            }
            cout << '\n';
        }
    }
    return 0;
}
