//https://www.acmicpc.net/problem/6064
// 6064 Ä«À×´Þ·Â

#include <iostream>

using namespace std;

int GCD(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	while (b != 0) {
		int r= a % b;
		a = b;
		b = r;
	}
	return a;
}

void solve(int m, int n, int _m, int _n) {
	int x = 0, y = 0;
	int lcf = m * n / GCD(m, n);

	for (int year = _m; year <= lcf; year += m) {
		int temp = (year % n == 0) ? n : year % n;
		if (temp == _n) {
			printf("%d\n", year);
			return;
		}
	}
	printf("-1\n");
}

int main() {
	int t;
	scanf("%d", &t);

	while (t-- > 0) {
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		solve(m, n, x, y);
	}
}	