//https://www.acmicpc.net/problem/10026
// 10026 적록색약
#include <iostream>
#include <queue>
#include <map>
#include <memory.h>
using namespace std;

int n;
int directions[4][2] = { {0,1} ,{0,-1} ,{1,0},{-1,0} };
char rgb[100][100];
bool visit[100][100];
map<char, int> m = { {'R', 0}, {'G', 0}, {'B', 0}, {'X', 0} };	//x: rg 

void bfs(int i, int j) {
	if (visit[i][j]) {
		return;
	}
	visit[i][j] = true;

	queue<pair<int, int>> Q;
	Q.push({ i,j });
	char color = rgb[i][j];

	m[color]++;

	while (!Q.empty()) {
		int cur_i = Q.front().first;
		int cur_j = Q.front().second;
		if (color == 'R' || color == 'G') rgb[cur_i][cur_j] = 'X';

		Q.pop();
		for (int d = 0; d < 4; d++) {
			int next_i = cur_i + directions[d][0];
			int next_j = cur_j + directions[d][1];
			if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < n && rgb[next_i][next_j] == color && !visit[next_i][next_j]) {
				visit[next_i][next_j] = true;
				Q.push({ next_i, next_j });
			}
		}
	}
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < n; j++) {
			rgb[i][j] = str.at(j);
		}
	}

	for (int x = 0; x < n; x++)
		memset(visit[x], false, sizeof(visit[x]));

	// r,g,b
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bfs(i, j);
		}
	}

	for (int x = 0; x < n; x++)
		memset(visit[x], false, sizeof(visit[x]));

	// rg, b
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (rgb[i][j] == 'B') continue;
			bfs(i, j);
		}
	}

	cout << m['R'] + m['G'] + m['B'] << " " <<m['X'] + m['B'] <<endl;
}
