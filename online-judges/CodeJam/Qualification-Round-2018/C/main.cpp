/**
 * Problem: C. Go, Gopher!
 * Judge: Codejam
 * Date: 07/04/2017
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <algorithm>
#include <cstring>

bool g[ 4 ][ 400 ];

void print_pair(int a, int b) {
    cout << a << " " << b << '\n' << std::flush;
}

bool check(int r, int c) {
    int x = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            x += g[r + i][c + j];
        }
    }

    return (x == 9);
}

int solve(const int A) {
    memset(g, 0, sizeof(g));
    int r = 2, c = 2;
    while (1) {
        print_pair(r, c);

        int i, j;
        cin >> i >> j;
        // cerr << i << "-" << j << "\n";

        if (i == -1 && j == -1) {
            // exit(0);
            return -1;
        } else if (i == 0 && j == 0) {
            return 1;
        }

        g[ i ][ j ] = 1;
        if (check(r, c)) {
            c += 3;
        }
    }
}


int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        int A;
        cin >> A;
        // cerr << " => A:" << A << "\n";
        if (-1 == solve(A)) {
            break;
        }
    }
    return 0;
}
