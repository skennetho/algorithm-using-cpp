//https://www.acmicpc.net/problem/2096
// 내려가기
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);




	int n1, n2, n3;
	int t1, t2, t3;
	scanf("%d %d %d", &n1, &n2, &n3);
	int maxx[3] = { n1,n2,n3 };
	int minn[3] = { n1,n2,n3 };
	printf("%d %d %d\n", maxx[0], maxx[1], maxx[2]);


	while (n-- > 1) {
		scanf("%d %d %d", &n1, &n2, &n3);

		t1 = min(minn[0], minn[1]) + n1;
		t2 = min(min(minn[0], minn[1]), minn[2]) + n2;
		t3 = min(minn[2], minn[1])+ n3;
		minn[0] = t1;
		minn[1] = t2;
		minn[2] = t3;

		t1 = max(maxx[0], maxx[1]) + n1;
		t2 = max(max(maxx[0], maxx[1]), maxx[2]) + n2;
		t3 = max(maxx[2], maxx[1]) + n3;
		maxx[0] = t1;
		maxx[1] = t2;
		maxx[2] = t3;

		printf("%d %d %d\n", maxx[0], maxx[1], maxx[2]);
	}

	sort(minn, minn + 3);
	sort(maxx, maxx + 3);

	printf("%d %d", maxx[2], minn[0]);
	cout << endl;
}

