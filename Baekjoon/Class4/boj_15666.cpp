//https://www.acmicpc.net/problem/15666
// N°ú M(12)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int pick[9];
vector<int> num;
int cnt[10001];

void select(int cur, int picked) {
	if (cur == m) {
		for (int i = 0; i < m; ++i) {
			printf("%d ", num[pick[i]]);
		}
		printf("\n");
		return;
	}

	for (int i = picked; i < num.size(); ++i ) {
		pick[cur] = i;
		select(cur + 1, i);
	}
}

int main() {
	scanf("%d %d", &n, &m);

	int number;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &number);
		if (cnt[number] == 0) {
			num.push_back(number);
		}
		++cnt[number];
	}
	sort(num.begin(), num.end());
	select(0, 0);
}
