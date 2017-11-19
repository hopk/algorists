/**
 * Problem: A. Alien Language
 * Judge: Codejam
 * Date: 17/11/2017
 * URL: https://code.google.com/codejam/contest/90101/dashboard#s=p0
 * Solved by: hopkins
 */

using namespace std;
#include <bits/stdc++.h>

const int SIZE_ALPHABETH = 26 + 1;
const int MAX_WORDS = 5000;
const int SIZE_TRIE = MAX_WORDS * SIZE_ALPHABETH + 5;
int trie[ SIZE_TRIE ][ SIZE_ALPHABETH + 5 ];

int _stateCount = 0;

int solve(const vector<string> &options,  int len, int state, string s) {
    if (len == options.size()){
        return 1;
    }

    int ans = 0;
    for (char c : options[ len ]) {
        int next = c - 'a';

        if (trie[ state ][ next ] != -1){
            ans += solve(options, len + 1, trie[ state ][ next ], s + c);
        }
    }
    return ans;

}
int solve(string buff) {
    size_t pos = 0;
    vector< string > v;
    string s = "";

    while((pos = buff.find("(")) != string::npos) {
        string token = buff.substr(0, pos);
        for (char c: token) {
            v.push_back(s + c);
        }
        buff.erase(0, pos + 1);

        pos = buff.find(")");
        token = buff.substr(0, pos);
        if (token.size() > 0){
            v.push_back(token);
        }
        buff.erase(0, pos + 1);
    }
    for (char c: buff) {
        v.push_back(s + c);
    }
    return solve(v, 0, 0, "");
}

void inset_trie(string s){
    int state = 0;
    for (char c : s ) {
        int next = c  - 'a';
        if (trie[ state ][ next ] == -1) {
            memset(trie[ _stateCount  ], -1, sizeof(trie[ _stateCount ]));
            trie[ state ][ next] = _stateCount++;
        }
        state = trie[ state ][ next ];
    }
}
int main(int argc, char const *argv[]) {
    // freopen("A-small-practice.in", "r", stdin);
    // freopen("A-small-practice.sol", "w", stdout);
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.sol", "w", stdout);
    int L, D, N;
    string buff;

    cin >> L >> D >> N;
    _stateCount = 1;
    memset(trie[ 0 ], -1, sizeof(trie[ 0 ]));

    while (D--) {
        cin >> buff;
        inset_trie(buff);
    }

    for (int caso = 1; caso <= N; ++caso) {
        cin >> buff;
        cout <<"Case #"<< caso << ": " << solve(buff) << "\n";
    }
    return 0;
}
