/**
 * Problem: Dados
 * Judge: OmegaUp
 * Date: 26/04/2017
 * URL: https://omegaup.com/arena/problem/Dados#problems
 */

/** Libr@ries **/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

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

int v[ 35 ];
LL dp[ 35 ][ 35 ];
int n;

LL solve(int id, int prev) {
	if (dp[id][prev] != -1LL) {
		return dp[id][prev];
	}
	if (id == n-1){
		return dp[id][prev] = v[id] - prev + 1;
	}

	LL &ans = dp[id][prev];
	ans = 0LL;
	for (int i = prev; i <= v[id]; ++i) {
		LL r = solve(id+1, i);
		ans += r;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	null(dp);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
    	cin >> v[ i ];
    }
    sort(v, v + n);
    LL ans = solve(0, 1);
    cout << ans << endl;
    return 0;
}
