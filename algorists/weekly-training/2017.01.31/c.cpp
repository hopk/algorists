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
const int MAXN = 200005;

int p[MAXN], rank[MAXN], used[MAXN];
void clearAll(){
	  for (int i = 0; i < MAXN; ++i)
	  {
		  p[i] = i;
		  rank[i] = 0;
		  used[i] = 0;
	  }
}

int findSet( int i )
{
    return (p[i]==i)?i:(p[i]=findSet(p[i]));
}

bool isSameSet( int i, int j )
{
    return findSet( i ) == findSet( j );
}

int unionSet( int i, int j )
{
  if( isSameSet( i, j ) ) return 1;
  int x = findSet( i ), y = findSet( j );
  if( rank[x] > rank[y] )
  {
    p[y] = x;   //psize[x] += psize[y];
  }
  else
  {
    p[x] = y;   //psize[y] += psize[x];
    if(rank[x]==rank[y])  rank[y]++;
  }
  return 0;
}


int main(int argc, char const *argv[])
{
    int tc = 0;
    // freopen("c.in", "r", stdin);
    // freopen("c.out", "w", stdout);

    while (1){
	    clearAll();
	    tc++;
    	int ban = 0;
    	int maxi = 0;
    	int u, v;
    	set< pair<int, int> >s;

    	while(scanf("%d %d", &u, &v) == 2){
    		if (u < 0 && v < 0) return 0;
    		if (u == 0 && v == 0) break;
    		if (s.find(make_pair(u,v)) != s.end()) continue;

    		s.insert(make_pair(u, v));
    		maxi = max(maxi, max(u, v));

    		ban += unionSet(u, v);
    		used[u] = 1;
    		used[v] = 1;
    	}
	    if (tc > 1) printf("\n");

    	int root = 0;
    	for (int i = 1; i <= maxi; i++)
    	{
    		if (p[i] == i && used[i] > 0) root++;
    		if (root > 2) break;
    	}

    	if (ban > 0 || root >= 2){
			printf("Case %d is not a tree.", tc);
    	}
		else{
    		printf("Case %d is a tree.", tc);
		}
    }

    return 0;
}
