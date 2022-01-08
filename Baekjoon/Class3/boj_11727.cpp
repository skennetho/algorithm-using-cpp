//https://www.acmicpc.net/problem/11727
//2xn ≈∏¿œ∏µ 2
#include<iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int dp[n+1];
    dp[1] = 1;
    dp[2] = 3;   // "||", "=", "§±"
    dp[3] = 5;    // "|||", "=|", "§±|", "|=", "|§±"

    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i-1] + (dp[i-2] * 2)) % 10007;
    }
    printf("%d\n", dp[n]);
}