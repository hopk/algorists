/**
 * Problem: B. Weird Rounding
 * Judge: CodeForces
 * Date: 20/09/2017
 * URL: http://codeforces.com/contest/779/problem/B/
 */


#include <iostream>

using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    std::string num;
    int k;
    cin >> num >> k;

    int zeros = 0;
    int ans = 0;

    for (int i = num.size() - 1; i >= 0; i--) {
        if (zeros >= k){
            break;
        }

        if (num[ i ] == '0') {
            zeros++;
            continue;
        } else {
            ans ++;
        }

    }

    if (zeros < k){
        ans = num.size() - (zeros > 0);
    }

    cout << ans << "\n";
    return 0;
}
