//https://www.acmicpc.net/problem/2667
// 2667

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[25][25];
int n;
vector<int> residentSizes;

void countResidents(int i, int j, int& cnt) {
	// 가로세로방향으로 나아감.
	if (arr[i][j] == 0) {
		return;
	}
	arr[i][j] = 0;
	cnt += 1;

	if (i - 1 >= 0 && arr[i-1][j] == 1) {
		countResidents(i - 1, j, cnt);
	}
	if (i + 1 < n && arr[i + 1][j] == 1) {
		countResidents(i + 1, j, cnt);
	}
	if (j - 1 >= 0 && arr[i][j - 1] == 1) {
		countResidents(i, j - 1, cnt);
	}
	if (j + 1 < n && arr[i][j + 1] == 1) {
		countResidents(i, j + 1, cnt);
	}
}

//int _countResidents(int i, int j) {
//	if (arr[i][j] == 0) {
//		return 0 ;
//	}
//	arr[i][j] = 0;
//	int cnt = 1;
//
//	if (i - 1 >= 0 && arr[i - 1][j] == 1) {
//		cnt += _countResidents(i - 1, j);
//	}
//	if (i + 1 < n && arr[i + 1][j] == 1) {
//		cnt += _countResidents(i + 1, j);
//	}
//	if (j - 1 >= 0 && arr[i][j - 1] == 1) {
//		cnt += _countResidents(i, j - 1);
//	}
//	if (j + 1 < n && arr[i][j + 1] == 1) {
//		cnt += _countResidents(i, j + 1);
//	}
//	return cnt;
//}


int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char c[25];
		scanf("%s", &c);
		for (int j = 0; j < n; j++) {
			arr[i][j] = c[j] - '0';
		}
	}

	residentSizes.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				int cnt = 0;
				countResidents(i, j, cnt);
				residentSizes.emplace_back(cnt);
			}
		}
	}
	sort(residentSizes.begin(), residentSizes.end());
	printf("%zd\n", residentSizes.size());
	for (const int& size : residentSizes) {
		printf("%d\n", size);
	}

	return 0;
}