/**
 * Problem: C. Welcome to Code Jam
 * Judge: Codejam
 * Date: 17/11/2017
 * URL: https://code.google.com/codejam/contest/90101/dashboard#s=p2
 * Solved by: hopkins
 */

using namespace std;
#include <bits/stdc++.h>

const int MOD = 10000;
const int MAXL = 505;
const string WORD = "welcome to code jam";
const int WORD_SIZE = 19;
int dp[WORD_SIZE + 1][ MAXL ];
int cc[WORD_SIZE + 1][ MAXL ];
int _caso;
inline int mod(int x){
    return x % MOD;
}

int solve(const string s){
    for (int i = 0; i <= s.size(); ++i) {
        dp[ 0 ][ i ] = 1;
    }
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= WORD_SIZE; ++j) {

            dp[ j ][ i ] = dp[ j ][i - 1];
            if (s[i - 1] == WORD[j - 1]){
                dp[ j ][ i ] = mod(dp[ j ][ i ] + dp[j - 1][i - 1]);
            }
        }
    }
    return dp[ WORD_SIZE ][ s.size() ];
}

int solve1(const string &b, const string &a, int ib, int ia) {
    if (ia == 0 || ib == 0) return (ia == ib || ia == 0);
    if (cc[ ia ][ ib ] == _caso) return dp[ ia ][ ib ];

    cc[ ia ][ ib ] = _caso;
    int &ret = dp[ ia ][ ib ];
    ret = 0;

    if (a[ia - 1] == b[ib - 1]){
        ret = mod(ret + solve1(b, a, ib-1, ia-1));
    }
    ret = mod(ret + solve1(b, a, ib-1, ia));

    return ret;
}

int main(int argc, char const *argv[])
{
    // freopen("C-small-practice.in", "r", stdin);
    // freopen("C-small-practice.sol", "w", stdout);
    freopen("C-large-practice.in", "r", stdin);
    freopen("C-large-practice.sol", "w", stdout);
    int tc;
    cin >> tc;
    cin.ignore();
    for (int caso = 1; caso <= tc; caso++) {
        _caso = caso;
        string buff;
        getline(cin, buff);
        cout << "Case #" << caso << ": " <<
            setfill('0') << setw(4) << solve(buff) << '\n';
    }
    return 0;
}