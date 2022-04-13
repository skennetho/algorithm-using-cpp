//https://www.acmicpc.net/problem/7569
// 7569 ≈‰∏∂≈‰
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TomatoStat {
	int t, r, c;
	int day;
	TomatoStat(int t, int r, int c, int _day) : t(t), r(r), c(c), day(_day) {};

	TomatoStat operator+(TomatoStat ts) {
		ts.t += t;
		ts.r += r;
		ts.c += c;
		ts.day += day;
		return ts;
	};
};

int maxRow, maxCol, maxTray;
int notRipedCount;

vector<vector<vector<int>>> tomatoes;
queue<TomatoStat> bfsQueue;

TomatoStat adjacent[6] = { {-1,0,0,1},{1,0,0,1},
						{0,-1,0,1},{0,1,0,1},
						{0, 0,-1,1},{0,0,1,1} };

void pushTomatoes(TomatoStat ts) {
	for (int i = 0; i < 6; i++) {
		TomatoStat tomato = ts + adjacent[i];
		if (tomato.t >= 0 && tomato.r >= 0 && tomato.c >= 0 &&
			tomato.t < maxTray && tomato.r < maxRow && tomato.c < maxCol &&
			tomatoes[tomato.t][tomato.r][tomato.c] == 0) {
			tomatoes[tomato.t][tomato.r][tomato.c]++;
			bfsQueue.push(tomato);
			notRipedCount--;
		}
	}
}

int main() {
	scanf("%d %d %d", &maxCol, &maxRow, &maxTray);
	notRipedCount = 0;

	tomatoes.assign(maxTray, vector<vector<int>>(maxRow, vector<int>(maxCol)));

	for (int t = 0; t < maxTray; t++) {
		for (int r = 0; r < maxRow; r++) {
			for (int c = 0; c < maxCol; c++) {
				scanf("%d", &tomatoes[t][r][c]);

				if (tomatoes[t][r][c] == 0) {
					notRipedCount++;
				}
				else if (tomatoes[t][r][c] == 1) {
					bfsQueue.push(TomatoStat(t, r, c, 0));
				}
			}
		}
	}

	TomatoStat ts(0, 0, 0, 0);
	while (!bfsQueue.empty()) {
		ts = bfsQueue.front();
		pushTomatoes(ts);
		bfsQueue.pop();
	}

	if (notRipedCount > 0) {
		printf("-1 \n");
	}
	else {
		printf("%d \n", ts.day);
	}
	return 0;
}