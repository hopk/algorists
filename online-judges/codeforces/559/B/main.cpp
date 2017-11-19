/**
 * Problem: B. Equivalent Strings
 * Judge: CodeForces
 * Date: 01/11/2017
 * URL: http://codeforces.com/problemset/problem/559/B
 * Solved by: hopkins
 */

#include <bits/stdc++.h>

std::string solve(std::string x) {
    std::string a = x.substr(0, x.size() / 2);
    std::string b = x.substr(x.size() / 2);

    if (a.size() != b.size()) return x;
    a = solve(a);
    b = solve(b);
    return std::min(a, b) + std::max(a, b);
}

int main(int argc, char const *argv[])
{
    std::string a, b;
    std::cin >> a >> b;
    std::cout << (solve(a) == solve(b) ? "YES": "NO") << "\n";
    return 0;
}