//https://www.acmicpc.net/problem/18108
// 1998����� ���� �±������� 2541���?!
#include <iostream>

using namespace std;

int main() {
    int thai_year;
    scanf("%d", &thai_year);

    int diff = 2541- 1998;
    printf("%d\n", (thai_year-diff));
}