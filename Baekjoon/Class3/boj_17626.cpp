//https://www.acmicpc.net/problem/17626
#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int n;
    scanf("%d", &n);

    int dp[50001];
    dp[1] = 1;

    for(int i =1 ; i<=n; i++){
        dp[i] = dp[1] + dp[i-1];
        for (int j= 2 ; j*j <= i ; j++){
            dp[i] = min(dp[i-j*j]+ 1, dp[i]);
        }   
    }
    printf("%d", dp[n]);
}
