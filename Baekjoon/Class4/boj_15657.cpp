//https://www.acmicpc.net/problem/15657
// N과 M(8)
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9]; //조합
int numbers[9]; //주어진 숫자들

void dfs(int cur, int picked) {
	if (cur >= m) {
		for (int i = 0; i < m; ++i) {
			printf("%d ", numbers[arr[i]]);
		}
		printf("\n");
		return;
	}

	for (int i = picked; i < n; ++i) {
		arr[cur] = i;
		dfs(cur + 1, i);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &numbers[i]);
	}
	sort(numbers, numbers + n);

	dfs(0, 0);
}
