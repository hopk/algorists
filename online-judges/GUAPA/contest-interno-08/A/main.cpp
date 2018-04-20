#include <bits/stdc++.h>
using namespace std;

double area(double a, double b, double c) {
	double s = (a + b + c)/2.0;
	return sqrt(s * (s-a) * (s-b) * (s-c));
}


double side(double a, double c, double ang) {
	return sqrt(a*a + c*c - (2.0* a * c * cos(ang)) );
}

double angle(double a, double b, double c) {
	return acos((a*a + b*b - c*c) / (2.0 * a * b));
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while (t--) {
		double ab, bc, ca, mc, nc;
		scanf("%lf %lf %lf %lf %lf", &ab, &bc, &ca, &mc, &nc);

		std::vector<double> v(3);
		double C = angle(ca, bc, ab);

		v[ 0 ] = area(nc, mc, side(nc, mc, C));
		v[ 1 ] = area(bc, mc, side(bc, mc, C)) - v[ 0];
		v[ 2 ] = area(ab, bc, ca) - v[ 0 ] - v[ 1 ];
		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); ++i) {
			printf("%.5lf\n", v[ i ]);
		}
	}
	return 0;
}
