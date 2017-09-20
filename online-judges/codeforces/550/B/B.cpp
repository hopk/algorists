#include <bits/stdc++.h>

inline bool test(const int &mask, const int &pos) {
    return (mask >> pos) & 1;
}
int main(int argc, char const *argv[]) {
    int n, l, r, x;
    std::cin >> n >> l >> r >> x;
    std::vector<int> v(n, 0);
    for (int &i : v) std::cin >> i;

    int ans = 0;
    for (int mask = 1; mask < (1<<n); ++mask) {
        if (__builtin_popcount(mask) >= 2) {
            std::set<int> s;
            long long sum = 0LL;
            for (int i = 0; i < n; ++i) if (test(mask, i)){
                s.insert(v[ i ]);
                sum += (long long) v[ i ];
            }

            long long diff = (long long)*s.rbegin() - (long long)*s.begin();
            if (l <= sum && sum <= r && diff >= x) {
                ans++;
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}
