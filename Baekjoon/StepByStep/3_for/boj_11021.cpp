//https://www.acmicpc.net/problem/11021
// A+B-7
#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d", (i + 1), (a + b));
    }
}