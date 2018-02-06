using namespace std;
#include <bits/stdc++.h>
#define color    first
#define position second

int solve(vector< pair<string, int> > RP) {
    int timeA = 0, timeB = 0;
    int posA = 1, posB = 1;
    int prev = -1;
    int ans = 0;

    for (const auto &rp : RP) {
        if (rp.color == "O") {
            int cost = abs(posA - rp.position) + 1;
            timeA += cost;

            if (prev == 1) {
                if (ans < timeA) {
                    ans = timeA;
                } else {
                    ans ++;
                    timeA = ans;
                }
            } else {
                ans = timeA;
            }
            prev = 0;
            posA = rp.position;
        }

        if (rp.color == "B") {
            int cost = abs(posB - rp.position) + 1;
            timeB += cost;

            if (prev == 0) {
                if (ans < timeB) {
                    ans = timeB;
                } else {
                    ans ++;
                    timeB = ans;
                }
            } else {
                ans = timeB;
            }
            prev = 1;
            posB = rp.position;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; caso++) {
        int n;
        cin >> n;

        vector< pair<string, int> > RP(n);
        for (auto &rp:RP) {
            cin >> rp.color >> rp.position;
        }
        cout << "Case #" << caso << ": "<< solve(RP) << '\n';
    }
    return 0;
}
