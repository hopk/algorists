/**
 * Problem: B. Coins
 * Judge: CodeForces
 * Date: 28/08/2017
 * URL: http://codeforces.com/contest/47/problem/B
 */

#include <bits/stdc++.h>

int getPos(const std::string &s, char c) {
    int pos = -1;
    for (int i = 0; i < s.size(); ++i){
        if (s[ i ] == c) return i;
    }
}

int main(int argc, char const *argv[]) {
    std::vector<std::string> v;
    std::string s;

    while (std::cin >> s) {
        v.push_back(s);
    }

    s = "ABC";
    std::string ans ("Impossible");
    do {
        bool ban = true;

        for (const std::string &o:v){
            int p1 = getPos(s, o[ 0 ]);
            int p2 = getPos(s, o[ 2 ]);

            if (o[ 1 ] == '<') {
                if (p1 >= p2) {
                    ban = false;
                    break;
                }
            } else if (o[ 1 ] == '>') {
                if (p1 <= p2) {
                    ban = false;
                    break;
                }
            }
        }

        if (ban) {
            ans = s;
            break;
        }
    } while ( std::next_permutation(s.begin(), s.end()) );

    std::cout << ans << "\n";
    return 0;
}
