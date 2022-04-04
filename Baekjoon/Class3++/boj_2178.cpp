//https://www.acmicpc.net/problem/2178
// ¹Ì·Î Å½»ö

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define POINT pair<int,int>

enum FROM{
	D_UP,
	D_RIGHT,
	D_DOWN,
	D_LEFT,
};

struct BfsPoint {
	BfsPoint(int _count, FROM _from, int _x, int _y) {
		count = _count;
		from = _from;
		x = _x;
		y = _y;
	}

	int count;
	FROM from;
	int x;
	int y;
};

queue<BfsPoint> bfsQueue;

void check_push_bfsPoint(int x, int y) {

}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		char c[100];
		scanf("%s", &c);

		for (int j = 0; j < m; j++) {
			arr[i][j] = c[j] - '0';
		}
	}

	BfsPoint bp(1, D_UP, 0, 0);
	bfsQueue = queue<BfsPoint>();
	bfsQueue.push(bp);
	arr[bp.x][bp.y] = 0;

	while (!bfsQueue.empty()) {
		bp = bfsQueue.front();
		bfsQueue.pop();

		if (bp.x == n - 1 && bp.y == m - 1) {
			printf("%d", bp.count);
			break;
		}

		if (bp.from != D_DOWN && bp.x + 1 < n && arr[bp.x + 1][bp.y] == 1) {
			bfsQueue.push(BfsPoint(bp.count + 1, D_UP, bp.x + 1, bp.y));
			arr[bp.x + 1][bp.y] = 0;
		}
		if (bp.from != D_RIGHT && bp.y + 1 < m && arr[bp.x][bp.y + 1] == 1) {
			bfsQueue.push(BfsPoint(bp.count + 1, D_LEFT, bp.x, bp.y + 1));
			arr[bp.x][bp.y + 1] = 0;
		}
		if (bp.from != D_UP		&& bp.x - 1 >= 0 && arr[bp.x - 1][bp.y] == 1) {
			bfsQueue.push(BfsPoint(bp.count + 1, D_DOWN, bp.x - 1, bp.y));
			arr[bp.x - 1][bp.y] = 0;
		}
		if (bp.from != D_LEFT	&& bp.y - 1 >= 0 && arr[bp.x][bp.y - 1] == 1) {
			bfsQueue.push(BfsPoint(bp.count + 1, D_RIGHT, bp.x, bp.y - 1));
			arr[bp.x][bp.y - 1] = 0;
		}
	}
}