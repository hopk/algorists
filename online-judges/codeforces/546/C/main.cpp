/**
 * Problem: C. Soldier and Cards
 * Judge: CodeForces
 * Date: 01/11/2017
 * URL: http://codeforces.com/problemset/problem/546/C
 * Solved by: hopkins
 */

#include <bits/stdc++.h>
int player = 0;

int solve(std::queue<int> &a, std::queue<int> &b) {
    player = -1;
    int count = 0;

    while (count++ < 1000000){
        if (a.size() == 0){
            player = 1;
            return count - 1;
        }
        if (b.size() == 0){
            player = 0;
            return count - 1;
        }
        player ^= 1;

        int x = a.front();
        a.pop();

        int y = b.front();
        b.pop();

        if (x > y){
            a.push(y);
            a.push(x);
        } else {
            b.push(x);
            b.push(y);
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n, k1, k2, x;
    std::cin >> n;
    std::cin >> k1;
    std::queue<int> a;
    for (int i = 0; i < k1; ++i) {
        std::cin >> x;
        a.push(x);
    }

    std::cin >> k2;
    std::queue<int> b;
    for (int i = 0; i < k2; ++i) {
        std::cin >> x;
        b.push(x);
    }

    int steps = solve(a, b);

    if (player == -1)
        std::cout << "-1\n";
    else
        std::cout << steps << " " << (player+1) <<"\n";

    return EXIT_SUCCESS;
}
