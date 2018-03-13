/**
 * Problem: 2311 - Semafori
 * Judge: COJ
 * Date: 12/03/2018
 * URL: http://coj.uci.cu/24h/problem.xhtml?pid=2311
 * Solved by: hopkins
 */

#include <stdio.h>
int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    int n, l;
    int ans = 0;
    int mod = 0;

    scanf("%d %d", &n, &l);

    int prev = 0;
    for (int i = 0; i < n; i++) {
        int d, r, g;
        scanf("%d %d %d", &d, &r, &g);

        ans += d - prev;
        prev = d;
        mod = ans % (r + g);
        if (mod < r) {
            ans += r - mod;
        }
    }

    ans += l - prev;
    printf("%d\n", ans);

    return 0;
}
