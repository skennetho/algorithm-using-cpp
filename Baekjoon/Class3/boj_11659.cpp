//https://www.acmicpc.net/problem/11659
//구간 합 구하기 4
#include<iostream>

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int numbers[n + 1];
    int prefix_sum[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &numbers[i]);
        prefix_sum[i]= prefix_sum[i - 1] + numbers[i];
    }

    int begin, end;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &begin, &end);
        printf("%d\n", prefix_sum[end] - prefix_sum[begin-1]);
    }
}