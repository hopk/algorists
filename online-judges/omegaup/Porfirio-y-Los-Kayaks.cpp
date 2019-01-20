/**
 * Problem: Porfirio y Los Kayaks
 * Solved by: hopkins0
 * Judge: OmegaUp
 * Date: 01/20/2019
 * URL: https://omegaup.com/arena/problem/Porfirio-y-Los-Kayaks/#problems
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	n <<= 1;
	vector<int> w(n), aux;
	
	for (int &x: w) cin >> x;
	sort(w.begin(), w.end());
	
	int ans = 1<<27;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j ++) {
			int sum = 0;
			
			aux.clear();
			for (int k=0; k < n; k++) {
				if (k == i || k == j) continue;
				aux.push_back(w[ k ]);
			}
			
			for (int k = 0; k < aux.size(); k+= 2) {
				sum += aux[k + 1] - aux[ k ];
			}
			ans = min(ans, sum);
		}
	}
	cout << ans << '\n';
	return 0;
}
