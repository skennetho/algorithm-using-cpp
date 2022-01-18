//https://www.acmicpc.net/problem/1697
// 숨바꼭질
#include <iostream>

using namespace std;

void dfs(int now, const int target, int count, int& best) {
    if(now == target) {
        if (best > count) {
            best = count;
        } 
        return;
    } 
    if (target < now) {
        count += now - target;
        if (best > count) {
            best = count;
        } 
        return;
    }
    if ((now * 2) - target > target - now) {
        return;
    }
    if (count > best) {               
        return;
    }
    count++;
    dfs(now * 2, target, count, best);
    dfs(now - 1, target, count, best);
    dfs(now + 1, target, count, best);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int best = k - n; //worst case;
    dfs(n, k, 0, best);

    printf("%d", best);
}

/*
경우:
x2
+1
-1
위3개를 조합하여 특정수까지 도달한다.

1차 방법 : dfs구조를 활용한다.
1. 3개의 경우의 수를 활용한다. (x2, +1, -1)
2. 만약 현재수*2-목표수가 목표수-현재수보다 넘는다면 해당 경로를 취소한다. 
    ex) n=5, k=7, => if ([n*2-k = 10-7] > [k-n = 7-5] 
3. 취소 - 만약 현재수와 목표수의 차이가 현재수보다 작다면 +1아니면 -1만 한다. or counter 만 차이만큼 올린다.


*/