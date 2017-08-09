/**
 * Problem: Nikita and the Game
 * Judge: HackerRank
 * Date: 09/08/2017
 * URL: https://www.hackerrank.com/challenges/array-splitting/problem
 */

using namespace std;
#include <iostream>
#include <algorithm>
#include <assert.h>

const int MAXN = 17000;
int n;
long long int sa[ MAXN ];
long long int  v[ MAXN];

long long int sum(int l, int r) {
	return sa[ r ] - sa[l - 1];
}

int f(int l, int r, int m) {
	return (sum(l , m)  - sum(m + 1, r)) >= 0LL;
}

int binary_search(int left, int right) {
	if (sum(left, right) % 2LL) return -1;

	int lo = left, hi = right;
	while (lo < hi) {
		int mid = lo + (hi - lo)/2;

		if (f(left, right, mid)) hi = mid;
		else lo = mid + 1;
	}

	if (sum(left, lo) != sum(lo + 1, right)) return -1;
	return lo;
}

int solve(int left, int right){
	if (left >= right) return 0;

	int mid = binary_search(left, right);
	if (mid == -1) return 0;
	return 1 + std::max(solve(left, mid), solve(mid+1, right));
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	assert(1 <= t && t <= 10);

	while (t--){
		cin >> n;
		assert(1 <= n && n <= (1 << 14));
		for (int i = 1; i <= n; ++i) {
			cin >> v[ i ];
			assert(0 <= v[i] && v[i] <= (long long)(1e9));
			sa[ i ] = sa[i - 1] + v[ i ];
		}

		cout << solve(1, n) << endl;
	}
	return 0;
}
