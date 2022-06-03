//https://www.acmicpc.net/problem/15654
// N°ú M(5)
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int pick[9] = { 0, };
int numbers[9] = { 0, };
bool visited[9] = {false, };

void dfs(int cur_index, int picked) {
	if (cur_index > m) {
		for (int i = 1; i <= m; ++i) {
			printf("%d ", numbers[pick[i]]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		pick[cur_index] = i;
		dfs(cur_index + 1, i);
		visited[i] = false;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &numbers[i]);
	}
	sort(numbers+1, numbers + n + 1);
	
	dfs(1, 0);
}