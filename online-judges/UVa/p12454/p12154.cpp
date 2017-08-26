/**
 * Problem: 12154 Shrinking Polygons
 * Judge: UVa Online Judge
 * Date: 26/08/2017
 * URL: https://uva.onlinejudge.org/external/121/12154.pdf
 */

#include <bits/stdc++.h>
const int MAXN = (int)1e7+ 7;
std::bitset< MAXN > seen;


bool check(int perimeter, int n, int init, int d) {
    for (int j = init; j < perimeter; j += d) {
        if (seen.test(j) == false) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {

    int n;
    while (std::cin >> n, n > 0) {
        seen.reset();
        int perimeter = 0;

        seen.set(0);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            perimeter += x;
            seen.set(perimeter);
        }

        int vertex = -1;
        for (int i = n; i >= 3; i--) {
            if (perimeter%i != 0) continue;

            bool ans = false;
            int dist = perimeter / i;
            for (int j = 0; j < dist; j++) {
                if (check(perimeter, n, j, dist)) {
                    ans = true;
                    break;
                }
            }
            if (ans) {
                vertex = i;
                break;
            }
        }

        if (vertex > 0)
            std::cout << (n - vertex) << '\n';
        else
            std::cout << "-1\n";
    }
    return 0;
}
