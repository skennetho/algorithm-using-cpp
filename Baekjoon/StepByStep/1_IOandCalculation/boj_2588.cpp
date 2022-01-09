//https://www.acmicpc.net/problem/2588
//°ö¼À
#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    for (double i = 0.0; i < 3.0; i+=1.0) {
        printf("%d\n", (a * (b / (int)pow(10.0, i) % 10)));
    }
    printf("%d", (a * b));
}