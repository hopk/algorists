/**
 * Problem: B. Code For 1
 * Judge: CodeForces
 * Date: 01/11/2017
 * URL: http://codeforces.com/problemset/problem/768/B
 * Solved by: hopkins
 */

#include <bits/stdc++.h>

long long L, R;
int solve(long long x, long long left, long long right) {
    if (R < left || right < L) return 0;
    if (x == 0LL || x == 1LL) return (int)x;

    long long mid = left + (right - left) / 2LL;

    return solve(x >> 1LL, left, mid - 1)
           + solve(x & 1, mid, mid)
           + solve(x >> 1LL, mid + 1, right);
}

int main(int argc, char const *argv[])
{
    long long n;
    std::cin >> n >> L >> R;
    long long N = log2(n) + 1LL;

    std::cout << solve(n, 1LL, (1LL << N) - 1LL) << "\n";
    return 0;
}