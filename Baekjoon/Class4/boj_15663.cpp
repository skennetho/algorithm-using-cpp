//https://www.acmicpc.net/problem/15663
// N°ú M(9)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> num;
int pick[9];
int cnt[10000];

void select(int cur, int picked) {
	if (cur >= m) {
		for (int i = 0; i < m; ++i) {
			printf("%d ", num[pick[i]]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < num.size(); ++i) {
		if (cnt[num[i]] > 0) {
			--cnt[num[i]];
			pick[cur] = i;
			select(cur + 1, i);
			++cnt[num[i]];
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		int number;
		scanf("%d", &number);
		if (cnt[number] == 0) {
			num.push_back(number);
		}
		++cnt[number];
	}

	sort(num.begin(), num.end());
	select(0, 0);
}

/*
* ¼±ÅÃ
*/