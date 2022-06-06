//https://www.acmicpc.net/problem/11725
// 트리의 부모 찾기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX = 100001;

int main() {
	int n, n1, n2;
	scanf("%d", &n);

	vector<vector<int>> list(MAX);
	int parent[MAX] = { 0, };
	queue<int> parentQ;

	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d", &n1, &n2);
		list[n1].push_back(n2);
		list[n2].push_back(n1);
	}


	parentQ.push(1);
	while (!parentQ.empty()) {
		int cur_parent = parentQ.front();
		parentQ.pop();

		for (const int& child : list[cur_parent]) {
			if (parent[child] == 0) {
				parent[child] = cur_parent;
				parentQ.push(child);
			}
		}
	}

	for (int i = 2; i <= n; ++i) {
		printf("%d\n", parent[i]);
	}
	printf("\n");
}
