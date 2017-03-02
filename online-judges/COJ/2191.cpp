// Hopkins
// COJ: 2191 - Rub Task
// URL: http://coj.uci.cu/24h/problem.xhtml?pid=2191

/** Libr@ries **/
#include <bits/stdc++.h>

/** System_Win_32 **/
#if ( WIN32 || __WIN32_ )
#define lld I64d
#endif
/** System **/
#define _ ios_base::sync_with_stdio(0);cin.tie(0);


/** Utilities **/
#define forit(i,v  )  for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define fori( i,a,b)  for (int i = (int)(a); i < (int)(b); i++)
#define forn( i, n )  fori( i, 0, n )
#define zeros( a )    memset(a, 0,sizeof(a))
#define null( a )     memset(a,-1,sizeof(a))
#define all( a )      (a).begin() , (a).end()
#define sqr( a )      ( (a)*(a) )
#define sz( a )       (a).size()
#define pb            push_back
#define mp            make_pair
#define F             first
#define S             second
#define PI            2*acos(0.0)
#define oo            0x7FFFFFFF
using namespace std;
typedef long long LL;

#define MAXN 105

int mov_i[ 4 ] = { -1, 1, 0, 0},
	mov_j[ 4 ] = { 0, 0, -1, 1};

int g[ MAXN ][ MAXN ];
LL d[ MAXN ][ MAXN ];


int solve(int n, int m){
	null(d);

	set< pair<LL, pair<int, int> > > q;

	for (int i = 0; i < n; ++i) {
		d[ i ][ 0 ] = g[ i ][ 0 ];
		q.insert(make_pair(g[ i ][ 0 ], make_pair(i, 0)));
	}

	while (!q.empty()) 	{
		LL c = q.begin()->first;
		int i = q.begin()->second.first;
		int j = q.begin()->second.second;
		q.erase(q.begin());

		for (int k = 0; k < 4; ++k) {
			int ni = i + mov_i[ k ],
				nj = j + mov_j[ k ];


			if (ni < 0 || ni >= n) continue;
			if (nj < 0 || nj >= m) continue;

			LL nc = c + g[ ni ][ nj ];

			if (d[ ni ][ nj ] == -1 || nc < d[ ni ][ nj ]){
				q.erase(make_pair(d[ ni ][ nj ], make_pair(ni, nj)));
				d[ ni ][ nj ] = nc;
				q.insert(make_pair(d[ ni ][ nj ], make_pair(ni, nj)));
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	// freopen("input.txt", "r", stdin);
  
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> g[i][j];
		}
	}


	LL ans = oo;
	solve(n, m);

	for (int i = 0; i < n; ++i) {
		if (ans > d[ i ][ m-1 ]) ans = d[ i ][ m-1 ];
	}

	cout << ans << endl;
	return 0;
}
