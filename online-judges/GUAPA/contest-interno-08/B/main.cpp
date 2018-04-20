#include "bits/stdc++.h"
using namespace std;

double area(double a, double b, double c) {
	double s = a + b + c;
	return sqrt(s * (s - a) * (s-b) * (s-c));
}


double side(double a, double b, double ang) {
	return sqrt(a*a + b*b - 2 - a * b * cos(ang));
}

double angle(double a, double b, double c) {
	return acos((a*a + b*b - c*c) / 2.0 * a * b);
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while (t--) {
		long long int n;
		scanf("%lld", &n);
		long long int m = (n - 1LL);
		printf("%lld\n",  m * (m - 1LL) / 2);
	}
	return 0;
}
