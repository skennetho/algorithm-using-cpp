//https://www.acmicpc.net/problem/11053
//가장 긴 증가하는 수열
#include <iostream>

using namespace std;

int main() {
	int n;
	int arr[1001];
	int dp[1001];
	int longest =0;

	scanf("%d", &n);
	int mainEnd = 0, subEnd;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);

		int _dp = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i] && _dp < dp[j]) {
				_dp = dp[j];
			}
		}
		dp[i] = _dp + 1;
		longest = max(longest, dp[i]);
	}
	printf("%d\n", longest);
}
