/**
 * Problem: A. Do you want a date?
 * Judge: CodeForces
 * Date: 09/08/2017
 * URL: http://codeforces.com/contest/809/problem/A
 */


using namespace std;
#include <iostream>
#include <algorithm>

const long long MOD = (long long) 1e9 + 7LL;
int v[ 300005 ];
int n;

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> v[ i ];
	sort(v, v + n);

	long long ans = 0LL;
	long long pot = 2LL;

	for (int i = 1; i < n; ++i) {
		ans = (ans + (v[ i ] * (pot - 1LL)) % MOD) % MOD;
		pot = (pot << 1LL) % MOD;
	}

	pot = 2LL;
	for (int i = n-2; i >= 0; i--) {
		ans = (ans - (v[i] * (pot - 1LL)) % MOD + MOD) % MOD;
		pot = (pot << 1LL) % MOD;
	}

	cout << ans << endl;
	return 0;
}
