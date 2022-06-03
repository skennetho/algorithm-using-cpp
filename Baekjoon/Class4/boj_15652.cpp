//https://www.acmicpc.net/problem/15652
// N�� M(4)
#include <iostream>

using namespace std;

int n, m;
int pick[9];

void dfs(int cnt, int num) {
	if (cnt > m) {
		for (int i = 1; i <= m; ++i) {
			printf("%d ", pick[i]);
		}
		printf("\n");
		return;
	}

	for (int i = num; i <= n;  ++i) {
		pick[cnt] = i;
		dfs(cnt + 1, i);
	}
	//dfs����Ͽ� ���� n�� �̱�
}
int main() {
	scanf("%d %d", &n, &m);
	dfs(1, 1);	
}