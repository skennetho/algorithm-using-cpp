//https://www.acmicpc.net/problem/1629
// °ö¼À
#include <iostream>

using namespace std;

long long a, b, c, k;

long long power(long long exponent) {
	if (exponent == 0) {
		return 1;
	}
	if (exponent == 1) {
		return a % c;
	}

	k = power(exponent / 2);
	if (exponent % 2 == 0) {
		return (k * k) % c;
	}
	else {
		return k * k % c * a % c;
	}
}

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	cout << power(b) << endl;
}
