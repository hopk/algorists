#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

double g[ 65 ][ 65 ];

void init() {
	g[0][0] = 1.0;
	g[1][0] = g[1][1] = 1.0;
	for (int i = 2; i < 64; ++i) {
		for (int j = 1; j < i; ++j)
		{
			g[i][j] = g[i-1][j] + g[i-1][j-1];
		}
		g[i][i] = 1.0;
		g[i][0] = 1.0;
	}
}

int main(int argc, char const *argv[])
{
	init();
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		int n;
		double k;
		scanf("%d %lf", &n, &k);

		double x = 0;
		for (int i = 2; i < n-1; ++i) {
			x += g[ n ][ i ];
			// printf("%lld\n", g[n][i]);
		}
		double ans = k * (double)(1e15);
		printf("%lf\n", ans / x);
	}
	return 0;
}