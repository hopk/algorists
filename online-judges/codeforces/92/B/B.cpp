#include <bits/stdc++.h>

int main(int argc, char const *argv[]){
    std::string s;

    int one_on = 0;
    int ans = 0;

    std::cin >> s;
    for (int i = s.size() - 1; i > 0 ; --i) {
        if (s[ i ] == '0') {
            if (one_on) {
                ans += 2;
            } else {
                ans += 1;
            }
        } else {
            if (one_on) {
                ans += 1;
            } else {
                ans += 2;
                one_on = 1;
            }
        }
    }
    if (one_on) ans++;

    std::cout << ans << '\n';
    return 0;
}
