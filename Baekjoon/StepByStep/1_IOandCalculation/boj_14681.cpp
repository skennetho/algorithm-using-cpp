//https://www.acmicpc.net/problem/14681
//사분면 고르기
#include <iostream>

using namespace std;

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    if (x > 0) {
        if (y > 0) {
            printf("1\n");
        } else {
            printf("4\n");
        }
    } 
    if (x < 0) { 
        if (y > 0) {
            printf("2\n");
        } else {
            printf("3\n");
        }
    }
}