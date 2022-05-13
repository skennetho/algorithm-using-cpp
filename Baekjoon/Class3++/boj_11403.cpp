//https://www.acmicpc.net/problem/11403
// 11403 경로 찾기

#include <iostream>

using namespace std;

int area[100][100];
int n;

int main() {
	scanf("%d", &n);

	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &area[i][j]);
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (area[i][k] == 1 && area[k][j] == 1) {
					area[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", area[i][j]);
		}
		printf("\n");
	}
}