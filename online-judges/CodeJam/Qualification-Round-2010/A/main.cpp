/**
 * Problem: A. Bot Trust
 * Judge: CodeJam
 * Date: 22/11/2017
 * URL: https://code.google.com/codejam/contest/975485/dashboard#s=p0
 * Solved by: hopkins
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // freopen("A-small-practice.in", "r", stdin);
    // freopen("A-small-practice.sol", "w", stdout);
    // freopen("A-large-practice.in", "r", stdin);
    // freopen("A-large-practice.sol", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for (int caso = 1; caso <= tc; ++caso) {
        int n, k;
        scanf("%d %d", &n, &k);

        int mask = (1 << n) - 1;

        printf("Case #%d: ", caso);
        if ((k & mask) == mask){
            printf("ON\n");
        } else {
            printf("OFF\n");
        }
    }
    return 0;
}