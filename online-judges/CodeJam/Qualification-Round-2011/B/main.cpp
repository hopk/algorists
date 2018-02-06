/**
 * Problem: B. Magicka
 * Judge: CodeJam
 * Date: 06/12/2017
 * URL: https://code.google.com/codejam/contest/975485/dashboard#s=p1
 * Solved by: hopkins
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

char combined(char a,  char b, map<string, char> combine) {
    string baseA = "" + a + b;
    string baseB = "" + b + a;
    if (combine.count(baseA) != 0) return combine[ baseA ];
    if (combine.count(baseB) != 0) return combine[ baseB ];
    return '#';
}

bool are_opposed(const string &s, const char &a, set<string> &opposed) {
    cout << "opposed = "<< s  << " - " << a << endl;
    for (const char &c : s) {
        string baseA = "" + c + a;
        string baseB = "" + a + c;
        if (opposed.find(baseA) != opposed.end()) return true;
        if (opposed.find(baseB) != opposed.end()) return true;
    }
    return false;
}
string solve(string s, const map<string, char> &combine, set<string> &opposed) {
    string x = "";

    for (char c: s) {
        cout << "=> " << c << " = ";
        if (x.size() == 0) {
            x += c;
            cout << '\n';
            continue;
        }

        char last = combined(x.back(), c, combine);
        cout << x << "=> " << last << " = ";
        if (last == '#') {
            cout << are_opposed(x, c, opposed) << " = ";
            if (are_opposed(x, c, opposed)){
                x = "";
            } else {
                x += c;
            }
        } else {
            x[x.size() - 1] = last;
        }
        cout << '\n';
    }
    return x;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    for (int caso = 1; caso <= tc; ++caso) {
        int C, D, N;
        map< string, char> combine;
        set< string > opposed;
        cin >> C;
        for (int i = 0; i < C; ++i) {
            string s;
            cin >> s;
            // cout << s << endl;
            combine[ "" + s[0] + s[1] ] = s[ 2 ];
        }
        cin >> D;
        for (int i = 0; i < D; ++i) {
            string s;
            cin >> s;
            // cout << s << endl;
            opposed.insert(s);
        }
        string buff;
        cin >> N >> buff;
        string ans = solve(buff, combine, opposed);

        cout << "Case #" << caso << ": [";
        for (int i = 0; i < ans.size(); ++i) {
            if (i) cout << ", ";
            cout << ans[ i ];
        }
        cout << "]\n";
    }
    return 0;
}
