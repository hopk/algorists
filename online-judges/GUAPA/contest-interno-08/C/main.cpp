#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

long long  g[ 605 ][ 605 ];
long long  d[ 605 ][ 605 ];

int mov[][2] = { {1,-1}, {1, 0}, {1,1}, {0,-1},
				 {0, 1}, {-1, -1}, {-1, 0}, {-1, 1} };

// using celda = pair<long long, pair<long long, pair<int, int> > >;


pair<long long, pair<long long, pair<int, int> > > crear_celda(long long c, long long  a, int i, int j) {
	return make_pair(c,
			make_pair(a, 
				make_pair(i, j)));
}

int main(int argc, char const *argv[])
{
	int R, C;
	cin >> R >> C;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> g[ i ][ j ];
			d[ i ][ j ] = -1LL;
		}
	}

	int dm, dn;
	set< pair<long long, pair<long long, pair<int, int> > >  > q;
	cin >> dm >> dn;
	dm --, dn--;
	q.insert(crear_celda(0LL, g[ dm ][ dn ], dm, dn));
	d[ dm ][ dn ] = 0LL;

	while (!q.empty()) {
		long long  costo = q.begin()->first;
		long long  last  = q.begin()->second.first;
		int r = q.begin()->second.second.first;
		int c = q.begin()->second.second.second;
		q.erase(q.begin());

		if (d[ r ][ c ] != costo) continue;
		for (int i = 0; i < 8; ++i) {
			int nr = r + mov[ i ][ 0 ];
			int nc = c + mov[ i ][ 1 ];

			if (nc < 0 || nc >= C) continue;
			if (nr < 0 || nr >= R) continue;
			if (nr == dm && nc == dn) continue;
			if (g[ nr ][ nc ] == 0LL) continue;

			long long nlast = min(last, g[ nr ][ nc ]);
			if (nlast > d[ nr ][ nc ]) {
				q.erase(crear_celda(d[ nr ][ nc ], nlast, nr, nc));
				d[ nr ][ nc ] = nlast;
				q.insert(crear_celda(d[ nr ][ nc ], nlast, nr, nc));
			}
		}
	}

	long long ans = g[ dm ][ dn ];
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (d[ i ][ j ] > 0LL )
				ans += d[ i ][ j ];
			// cout << d[ i ][ j ] << " ";
		}
		// cout << "\n";
	}

	cout << ans << '\n';
	return 0;
}
