#include <bits/stdc++.h>
using namespace std;

long long int v[ 1000009 ];
int main(int argc, char const *argv[]) {

    int n;
    int odds = 0;
    scanf("%d", &n);

    long long sum = 0LL;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", v + i);
        sum += v[ i ];

        if (v[ i ]%2) odds++;
    }

    if (odds > 0) {
        printf("First\n");
    } else {
        printf("Second\n");
    }


    return 0;
}
