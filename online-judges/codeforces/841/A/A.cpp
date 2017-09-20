#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

    int n, k;
    string in;
    cin >> n >> k;
    cin >> in;

    vector<int> c(30, 0);

    for (int i = 0; i < n; ++i) {
        c[ in[i] - 'a']++;
    }

    bool ok = true;
    for (int i = 0; i < 30; ++i) {
        if (c[ i ] > k ) {
            ok = false;
        }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
