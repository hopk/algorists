/**
 * Problem: C. Lawnmower
 * Judge: Codejam
 * Date: 23/01/2018
 * URL: https://code.google.com/codejam/contest/2270488/dashboard#s=p2
 * Solved by: hopkins
 */

using namespace std;
#include <iostream>
#include <algorithm>

const int MAXNUMS = 49;
long long nums[] = { 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944 , 1002001, 1234321,
                     4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521,
                     400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321,
                     40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201,
                     1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121,
                     1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001,
                     100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121,
                     123212464212321, 123456787654321, 400000080000004, 10000000200000001 };

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("C-large-practice-1.in", "r", stdin);
    freopen("C-large-practice-1.sol", "w", stdout);

    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        long long int A, B;
        cin >> A >> B;
        int ans = lower_bound(nums, nums + MAXNUMS, B + 1)  - lower_bound(nums, nums + MAXNUMS, A);
        cout << "Case #" << caso << ": " << ans << '\n';
    }
    return 0;
}
