#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
    int q;
    long long l, r;
    std::cin >> q;
    while (q--) {
        std::cin >> l >> r;
        long long ans = l;
        int pos = 0;
        while (pos < 63) {
            if ((ans | (1LL << pos)) <= r)
                ans |= (1LL << pos);
            pos++;
        }
        std::cout << ans << "\n";
    }
    return 0;
}
