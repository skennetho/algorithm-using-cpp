//https://www.acmicpc.net/problem/9465
// ½ºÆ¼Ä¿
#include <iostream>
#include <cstdlib>

using namespace std;

int arr[2][100000];
int dp[2][100000];

void solution() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) 
		scanf("%d", &arr[0][i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[1][i]);

	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	
	if (n > 1) {
		dp[0][1] = arr[0][1] + arr[1][0];
		dp[1][1] = arr[1][1] + arr[0][0];
	}

	for (int i = 2; i < n; ++i) {
		dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}

	int result = max(dp[0][n - 1], dp[1][n - 1]);
	printf("%d\n", result);
}


int main() {
	int test;
	scanf("%d", &test);

	for (int i = 0; i < test; ++i) {
		solution();
	}
}