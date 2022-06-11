//https://www.acmicpc.net/problem/16953
// A->B
#include <iostream>

using namespace std;

int a, b;

int go(int start, int cnt) {
	if (start == a) {
		return cnt;
	}
	if (start < a) {
		return -1;
	}

	if (start % 2 == 0 && start >= 2) {
		return go(start / 2, cnt + 1);
	}
	if (start % 10 == 1 && start >= 10) {
		return go(start / 10, cnt + 1);
	}
	else {
		return -1;
	}
}

int main() {
	scanf("%d %d", &a, &b);
	cout << go(b, 1) << endl;
}
