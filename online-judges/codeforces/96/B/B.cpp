#include <bits/stdc++.h>

inline bool test(int &mask, int &pos) {
    return ((mask >> pos) & 1);
}

long long solve(const long long val, const int digits){
    long long ans = -1LL;
    for (int mask = 0; mask < (1 << digits); mask++) {
        long long v = 0LL;
        for (int d = digits - 1; d >= 0; d--) {
            v = v * 10LL + (test(mask, d)?7LL:4LL);
        }

        if (v >= val && __builtin_popcount(mask) == (digits/2)) {
            ans = v;
            break;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    std::string s;
    std::cin >> s;

    int digits = s.size() + ((s.size()%2 == 1)?1:0);
    int val = std::stoi(s);

    long long ans = -1LL;
    while (ans < 0LL) {
        ans = solve(val, digits);
        digits +=2;
    }

    std::cout << ans << std::endl;
    return 0;
}
