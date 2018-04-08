/**
 * Problem: B. Trouble Sort
 * Judge: Codejam
 * Date: 07/04/2017
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <algorithm>

int L_EVEN[ 100005 ];
int L_ODD [ 100005 ];
int L     [ 100005 ];

int print(int N, int *L) {
    for (int j = 0; j < N; ++j) {
        cout << L[ j ] << " ";
    }
    cout << "\n";
}

void troubleSort(int N, int *L) {
    bool done = false;
    while (!done) {
        done = true;
        print(N, L);
        for (int i = 0; i < N - 2; ++i) {
            if (L[ i ] > L[i + 2]) {
                done = false;
                swap(L[ i ], L[i + 2]);
            }
            print(N, L);
        }
    }
}

int solve(const int n, const int n_odd, const int n_even) {
    sort(L_ODD, L_ODD + n_odd);
    sort(L_EVEN, L_EVEN + n_even);

    int ans = -1;
    int iter_even = 0, iter_odd = 0;

    for (int i = 0; i < n; ++i) {
        if (i&1) L[ i ] = L_EVEN[ iter_even++ ];
        else L[ i ] = L_ODD[ iter_odd++ ];
    }

    // print(n, L);
    for (int i = 0; i < n-1; ++i) {
        if (L[ i ] > L[i + 1]){
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        int N;
        cin >> N;

        int n_odd = 0, n_even = 0;
        for (int i = 0; i < N; ++i) {
            if (i&1) cin >> L_EVEN[ n_even++ ];
            else cin >> L_ODD[ n_odd++ ];
        }

        int ans = solve(N, n_odd, n_even);

        cout << "Case #" << caso << ": ";
        if (ans == -1) cout << "OK\n";
        else cout << ans << '\n';
    }
    return 0;
}
