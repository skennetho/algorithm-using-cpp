//https://www.acmicpc.net/problem/1916
// �ּҺ�� ���ϱ�
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAX_COST = 100000'0000;
int nodeSize, busSize;


int main() {
	scanf("%d", &nodeSize);
	scanf("%d", &busSize);

	vector<vector<pair<int, int>>> edges(nodeSize + 1);

	int from, to, cost;
	for (int i = 0; i < busSize; ++i) {
		scanf("%d %d %d", &from, &to, &cost);
		edges[from].push_back({ to,cost });
	}
	scanf("%d %d", &from, &to);

	vector<bool> dp(nodeSize + 1);
	for (int i = 0; i <= nodeSize; ++i) {
		dp[i] = MAX_COST;
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ from, 0 });

	while (!pq.empty()) {
		int cur = pq.top().first;
		int curDist = pq.top().second;
		pq.pop();

		//cur�� ��ĥ�Ǵ� �̹� dp���� �� �������̶�� �о�.
		if (dp[cur] < curDist) continue;

		for (int i = 0; i < edges[cur].size(); ++i) {
			//���� ��ĥ ���� ���.
			int next = edges[cur][i].first;
			//cur�� ��ģ�� next�� �����ϴ� ���
			int nextDist = curDist + edges[cur][i].second;
			if (dp[cur] > nextDist) {
				dp[cur] = nextDist;
				pq.push({ next, nextDist });
			}
		}
	}
	pq.empty();
}
