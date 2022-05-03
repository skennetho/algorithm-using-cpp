//https://www.acmicpc.net/problem/14500
// 14500 테트로미노
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int maxSum = 0;
int dirs[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
int board[501][501];
bool visited[501][501];

bool isInBoard(int i, int j) {
	return i >= 0 && i < n&& j >= 0 && j < m;
}

void dfsFromBlock(int i, int j, int depth, int sum) {
	if (depth == 4) {
		maxSum = max(maxSum, sum);
		return;
	}

	for (int d = 0; d < 4; d++) {
		int _i = i + dirs[d][0];
		int _j = j + dirs[d][1];
		if (isInBoard(_i, _j) && !visited[_i][_j]) { 
			visited[_i][_j] = true;
			dfsFromBlock(_i, _j, depth+1, sum+board[_i][_j]);
			visited[_i][_j] = false;
		}
	}
}

void TshapeBlock(int i, int j, int sum) {
	int minBlock = INT32_MAX;
	int cnt = 0;
	for (int d = 0; d < 4; d++) {
		int _i = i + dirs[d][0];
		int _j = j + dirs[d][1];
		if (isInBoard(_i, _j)) {
			minBlock = min(board[_i][_j], minBlock);
			sum += board[_i][_j];
			cnt++;
		}
	}

	if (cnt < 3) 
		return;
	if (cnt == 3) 
		maxSum = max(maxSum, sum);
	if (cnt == 4) 
		maxSum = max(maxSum, sum - minBlock);
}

int main() {
	maxSum = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfsFromBlock(i, j, 1, board[i][j]);
			TshapeBlock(i, j, board[i][j]);
			visited[i][j] = false;
 		}
	}

	printf("%d\n", maxSum);
}
