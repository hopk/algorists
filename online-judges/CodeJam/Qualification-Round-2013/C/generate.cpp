using namespace std;
#include <stdio.h> 
#include <set>
#include <cmath>
#include <iostream>
set<long long> ppmid;


bool check(long long x) {
    long long l = sqrt(x);
    if (l*l != x) return false;

    char s[ 20 ];
    int c = sprintf(s, "%lld", x);
    
    for (int i = 0; i < c/2; i++) {
        if (s[ i ] != s[c - 1 - i]) return false;
    }

    c = sprintf(s, "%lld", l);
    for (int i = 0; i < c/2; i++) {
        if (s[ i ] != s[c - 1 - i]) return false;
    }
    return true;
}

void insert(long long m) {
    if (check(m))
        ppmid.insert(m);

    for (int i = 0LL; i < 10LL; i++) {
        long long int s = m, x = m;

        x = x*10LL + i;
        while (s > 0LL) {
            x = x * 10LL + s%10LL;
            s /= 10LL;
        }
        
        if (check(x)) ppmid.insert(x);
    }
    long long int s = m, x = m;
    while (s > 0LL) { 
        x = x * 10LL + s%10LL; 
        s /= 10LL;
    } 
    if (check(x)) ppmid.insert(x);
}

int main () {

    // for (int i=1; i < 10; i++) ppmid.insert(i);

    for (long long i=1LL; i <= 10000000LL; i++) {
        insert(i);
    }

    for (auto x : ppmid) {
            cout << x << endl;
    }
    cout << endl;
    return 0;
}
