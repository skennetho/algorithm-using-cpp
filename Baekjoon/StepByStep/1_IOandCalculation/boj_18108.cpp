//https://www.acmicpc.net/problem/18108
// 1998년생인 내가 태국에서는 2541년생?!
#include <iostream>

using namespace std;

int main() {
    int thai_year;
    scanf("%d", &thai_year);

    int diff = 2541- 1998;
    printf("%d\n", (thai_year-diff));
}