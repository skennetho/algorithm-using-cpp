//https://www.acmicpc.net/problem/15552
// ���� A+B
#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
}