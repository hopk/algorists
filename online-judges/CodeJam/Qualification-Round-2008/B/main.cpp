/**
 * Problem: B. Train Timetable
 * Judge: CodeJam
 * Date: 15/11/2017
 * URL: https://code.google.com/codejam/contest/32013/dashboard#s=p1
 * Solved by: hopkins
 */


#include <bits/stdc++.h>

const int MAX_TIME = 60 * 24;
int left[MAX_TIME + 5], right[MAX_TIME + 5];


int main(int argc, char const *argv[])
{
    // freopen("test.01.in", "r", stdin);
    int tc;
    scanf("%d", &tc);

    for (int caso = 0; caso < tc; ++caso) {
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        int delay, na, nb;
        scanf("%d", &delay);
        scanf("%d %d", &na, &nb);
        
        for (int i = 0; i < na; ++i) {
            int h1, m1, h2, m2;
            scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
            int time_start = h1* 60 + m1 + 1;
            int time_finish = h2* 60 + m2 + 1 + delay;

            left[ time_start ]--;
            if (time_finish + delay <= MAX_TIME)
                right[ time_finish ]++;
        }

        for (int i = 0; i < nb; ++i) {
            int h1, m1, h2, m2;
            scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
            int time_start = h1* 60 + m1 + 1;
            int time_finish = h2* 60 + m2 + 1 + delay;

            right[ time_start ]--;
            if (time_finish + delay <= MAX_TIME)
                left[ time_finish ]++;
        }

        int ansLeft = 0, ansRight = 0;
        for (int i = 1; i <= MAX_TIME; ++i) {
            left[ i ] += left[i - 1];
            right[ i ] += right[i - 1];

            if (left[ i ] < 0) {
                ansLeft += -left[ i ];
                left[ i ] = 0;
            }
            if (right[ i ] < 0) {
                ansRight += -right[ i ];
                right[ i ] = 0;
            }
        }

        printf("Case #%d: %d %d\n", (caso + 1), ansLeft, ansRight);
    }
    return EXIT_SUCCESS;
}
