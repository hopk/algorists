/**
 * Problem: C. Round Table Knights
 * Judge: CodeForces
 * Date: 18/08/2017
 * URL: http://codeforces.com/contest/71/problem/C
 * Solved by: hopkins
 */

using namespace std;
#include <bits/stdc++.h>

const int MAXN = (int)(1e5) + 7;

bool criba[ MAXN ];
vector<int> primos;
int knights[ MAXN ];


void sieve(){
    for (int i=2; i < MAXN; i++) {
        if (criba[i] == false) {
            for (int j = i + i; j < MAXN; j+= i) {
                criba[ j ] = true;
            }
            primos.push_back(i);
        }
    }
}


void solve(const int n) {
    bool ans = false;
    for (int d = 1; d <= n/3; d++){
        if (n%d == 0) {
            for (int i = 0; i < d; i++) {
                bool flag = true;
                for (int j = i; j < n; j+= d) {
                    if (knights[ j ] == 0){
                        flag = false;
                    }
                }
                if (flag) ans = flag;
            }
        }
    }
    cout << (ans?"YES":"NO") << endl;
}

int main(int argc, char const *argv[]) {
    sieve();

    int n;
    while(cin >> n){
        for (int i = 0; i < n; ++i) {
            cin >> knights[ i ];
        }
        solve(n);
    }
    return 0;
}
