//https://www.acmicpc.net/problem/11403
// 11403 경로 찾기

#include <iostream>

using namespace std;

int arr[100][100];
int n;

int main() {
	scanf("%d", &n);

	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
			
				if (arr[i][k] == 1 && arr[k][j] == 1) {
					arr[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}