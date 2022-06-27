//https://www.acmicpc.net/problem/1916
// 최소비용 구하기
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAX_COST = 100000'0000;
int nodeSize, busSize;

struct Compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int minIndex(const vector<int>& dp, const vector<bool>& visited) {
	int index = -1;
	int min = MAX_COST;
	for (int i = 1; i <= nodeSize; ++i) {
		if (!visited[i] && min > dp[i]) {
			index = i;
			min = dp[i];
		}
	}
	return index;
}

int main() {
	scanf("%d", &nodeSize);
	scanf("%d", &busSize);

	vector<vector<pair<int, int>>> edges(nodeSize + 1);
	priority_queue<pair<int, int>> pq;

	int from, to, cost;
	for (int i = 0; i < busSize; ++i) {
		scanf("%d %d %d", &from, &to, &cost);
		edges[from].push_back({ to,cost });
	}
	scanf("%d %d", &from, &to);

	for (int i = 1; i <= nodeSize; ++i) {
		printf("%d node : ", i);
		for (auto pair : edges[i]) {
			printf("{%d, %d}, ", pair.first, pair.second);
		}
		printf("\n");
	}
	
	vector<int> dp(nodeSize + 1, MAX_COST);
	dp[from] = 0; // 스스로는 거리가 0;
	pq.push({ from, 0 });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int curDist = -pq.top().second;
		pq.pop();
		printf("pop : %d,%d\n\t", cur, curDist);
		for (int a : dp) {
			if (a == MAX_COST)cout << "INF ";
			else cout << a << " ";
		}
		cout << endl;
		if (curDist > dp[cur]) {
			continue;
		}

		for (int i = 0; i < edges[cur].size(); ++i) {
			int next = edges[cur][i].first;
			int nextDist = curDist + edges[cur][i].second;
			
			printf("  => %d, %d}, \n", next, edges[cur][i].second);
			
			if (nextDist < dp[next]) {
				dp[next] = nextDist;
				printf("\tpush : %d,%d\n", next, nextDist);

				pq.push({ next, -nextDist });
			}
		}
	}
	
	printf("%d\n", dp[to]);
	printf("%d\n", dp[to]);
}
