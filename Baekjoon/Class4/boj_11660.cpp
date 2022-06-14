//https://www.acmicpc.net/problem/11660
// 구간 합 구하기 5
#include <iostream>

using namespace std;

int n, m;
int arr[1025][1025];
int prefix[1025][1025]; // prefix[i][j] == i번줄의 누적합. arr의 가로 누적합
int prefix_2[1025][1025]; // prefix2[i][j] == prefix[][j]들의 i까지 누적합. prefix의 세로 누적합.


void printSum(int x1, int y1, int x2, int y2) {
	int total = prefix_2[x2][y2] - prefix_2[x1 - 1][y2]; // x1,1 ~ x2,y2 
	int useless = prefix_2[x2][y1 - 1] - prefix_2[x1 - 1][y1 - 1]; // x1,1 ~  x2,y1-1

	printf("%d\n", (total - useless));
}


int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &arr[i][j]);
			prefix[i][j] = arr[i][j] + prefix[i][j - 1];
		}
	}

	for (int j = 1; j <=n; ++j) {
		for (int i = 1; i <= n; ++i) {
			prefix_2[i][j] = prefix_2[i - 1][j] + prefix[i][j];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printSum(x1, y1, x2, y2);
	}
}