//https://www.acmicpc.net/problem/2407
// 2407 а╤гу

#include <iostream>

using namespace std;

static const unsigned long long D_MAX = 100000'00000'00000; //16zeroes

int main() {
	int _n, _m;
	cin >> _n >> _m;

	unsigned long long d[101][101];
	unsigned long long d2[101][101];
	d[1][0] = 1;
	d[1][1] = 1;
	d2[1][0] = 0;
	d2[1][1] = 0;

	for (int n = 2; n <= 100; ++n) {
		d[n][0] = 1;
		d[n][n] = 1;
		d2[n][0] = 0;
		d2[n][n] = 0;

		for (int r = 1; r <= (n+1)/2; ++r) {
			d[n][r] = d[n - 1][r - 1] + d[n - 1][r];
			d2[n][r] = d2[n - 1][r - 1] + d2[n - 1][r];
			

			if (d[n][r] > D_MAX) {
				d2[n][r] += d[n][r] / D_MAX;
				d[n][r] %= D_MAX;
			}

			d[n][n-r] = d[n][r];
			d2[n][n-r] = d2[n][r];
		}
	}

	if (d2[_n][_m] != 0) {
		printf("%lld%015lld\n", d2[_n][_m], d[_n][_m]);
	}
	else {
		printf("%lld\n", d[_n][_m]);
	}
}