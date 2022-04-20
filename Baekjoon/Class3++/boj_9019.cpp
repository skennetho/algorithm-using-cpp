//https://www.acmicpc.net/problem/9019
//https://glimmer-fireplace-3ae.notion.site/9019-DSLR-107337f13ff8441fa39d204c4efc4d18
// 9019 : DSLR
#include <iostream>
#include <queue>
#include <algorithm>
#include<memory.h>

using namespace std;


int insD(int num) {
	return (num * 2) % 10000;
}
int insS(int num) {
	return (num == 0) ? 9999 : num - 1;
}
int insL(int num) {
	return (num * 10 + num / 1000) % 10000;
}
int insR(int num) {
	return num / 10 + (num % 10) * 1000;
}


void solve() {
	int number, target;
	cin >> number >> target;

	queue<int> bfsQueue;
	bfsQueue.push(number);

	char trace[10000];
	int visit[10000];
	memset(visit, -1, sizeof(visit));
	visit[number] = 1;

	while (!bfsQueue.empty()) {
		int current = bfsQueue.front();
		bfsQueue.pop();

		int _d = insD(current);
		int _s = insS(current);
		int _l = insL(current);
		int _r = insR(current);

		if (visit[_d] == -1) {
			visit[_d] = current;
			trace[_d] = 'D';
			bfsQueue.push(_d);
		}
		if (visit[_s] == -1) {
			visit[_s] = current;
			trace[_s] = 'S';
			bfsQueue.push(_s);
		}
		if (visit[_l] == -1) {
			visit[_l] = current;
			trace[_l] = 'L';
			bfsQueue.push(_l);
		}
		if (visit[_r] == -1) {
			visit[_r] = current;
			trace[_r] = 'R';
			bfsQueue.push(_r);
		}

		if (_d == target || _s == target || _l == target || _r == target) {
			break;
		}
	}
		
	string result = "";
	while (target != number) {
		result += trace[target];
		target = visit[target];
	}
	reverse(result.begin(), result.end());
	cout << result << '\n';
}

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while (t-- > 0) {
		solve();
	}
}