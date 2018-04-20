#include "bits/stdc++.h"
using namespace std;
const int maxn = 100005;
int a[ maxn ] , b[ maxn ];

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int na, nb;
		scanf("%d %d", &na, &nb);
		for (int i = 0; i < na; ++i) {
			scanf("%d", a + i);
		}
		for (int i = 0; i < nb; ++i) {
			scanf("%d", b + i);
		}

		int pos = 0;
		int i = 0;
		while (pos < nb && i < na) {
			// printf("%d %d\n", a[i], b[pos] );
			if (a[ i ] == b[ pos ]) {
				pos++;
			}
			i++;
		}

		if (pos == nb)
			printf("Estan entre nosotros\n");
		else printf("You always knew\n");
	}
	return 0;
}
