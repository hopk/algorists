/**
 * Problem: Gridland Metro
 * Judge: HackerRank
 * Date: 11/08/2017
 * URL: https://www.hackerrank.com/challenges/gridland-metro/problem
 */

/*
	Solution description:
	We can see the problem in two different ways:
		- Count how many cells are empty for each row or
		- Count how many cells are fill for each row.

		I follow the second approach, so, I used a sweep line for each row
		and count how many cells are filled in it. After that the solution
		will be the total of cells minus the filled cells.
 */

using namespace std;
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <assert.h>

using track = pair<int, pair<int, int> >;
int rows, cols, k;
vector<track> v;

track build_track(int r, int c1, int c2) {
	return make_pair(r, make_pair(c1, c2));
}

int get_init(track t) { return t.second.first; }
int get_end(track t) { return t.second.second; }
int get_row(track t) { return t.first; }

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> rows >> cols >> k;
	assert(1 <= rows && rows <= (int)(1e9));
	assert(1 <= cols && cols <= (int)(1e9));
	assert(0 <= k && k <= (int)(1e3));

	for (int i = 0; i < k; ++i) {
		int r, c1, c2;
		cin >> r >> c1 >> c2;
		assert(1<= c1 && c1 <= cols);
		assert(1<= c2 && c2 <= cols);
		assert(c1 <= c2 );
		v.push_back(build_track(r, c1, c2));
	}
	sort(v.begin(), v.end());

	int counting = 0;

	for (int i = 0; i < k; i++) {
		int init_col = get_init(v[i]), end_col = get_end(v[i]);
		int current_row = get_row(v[i]);

		while(i < k && get_row(v[ i ]) == current_row) {

			if (get_init(v[ i ]) <= end_col) {
				end_col = max(end_col, get_end(v[ i ]));
			} else {
				counting += end_col - init_col + 1;
				init_col = get_init(v[ i ]);
				end_col = get_end(v[ i ]);
			}
			i++;
		}
		i--;

		counting += end_col - init_col + 1;
		current_row ++;
	}

	long long ans = ((long long) rows * (long long) cols) - (long long) counting;
	cout << ans << '\n';
	return 0;
}
