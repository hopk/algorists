/**
 * Problem: A. Multi-base happiness
 * Judge: Codejam
 * Date: 05/03/2018
 * URL: https://code.google.com/codejam/contest/188266/dashboard#s=p0&a=1
 * Solved by: hopkins
 *
 * Note: The solution should be optimized
 */

using namespace std;
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

long long sqr(long long x) {
	return x*x;
}
long long change_base_10_to_base_b(long long x, long long b) {
	long long ret = 0LL;
	long long pot = 1LL;

	while (x > 0) {
		ret += x%b * pot;
		x /= b;
		pot *= 10LL;
	}
	return ret;
}

long long sum_square_of_digits(long long x){
	long long ret = 0;
	while (x > 0LL) {
		ret += sqr(x % 10LL);
		x   /= 10LL;
	}
	return ret;
}

bool test(long long int x, int base) {
	set <int> st;

	x = change_base_10_to_base_b(x, base);
	while (x > 1) {
		if (st.find(x) != st.end()){
			return false;
		}
		st.insert( x );
		x = change_base_10_to_base_b(sum_square_of_digits(x), base);
	}
	return true;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("input.txt", "r", stdin);
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.sol", "w", stdout);


    int tc;
    cin >> tc;
    cin.ignore();
    for (int caso = 1; caso <= tc; ++caso) {
        string buff;
        getline(cin, buff);

        vector<int> bases;
        stringstream sc(buff);

        int x;
        while (sc >> x) {
        	bases.push_back(x);
        }
        

        int ans = -1;
    	for (int i = 2; i <= 12000000; ++i) {
    		int flag = 0;
    		for (int j = 0; j < bases.size(); j++ ) {
        		if (test(i, bases[ j ])){
        			flag++;
        		}
    		}
    		if (flag == bases.size()) {
    			ans = i;
    			break;
    		}
    	}

        cout << "Case #" << caso << ": " << ans << '\n';
    }
    return 0;
}


