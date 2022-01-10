//https://www.acmicpc.net/problem/11279
//ÃÖ´ë Èü
#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> priorQ;
    int n, input;
    scanf("%d", &n);

    while(n-- > 0) {
        scanf("%d", &input);
        if (input == 0) {
            if (priorQ.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", priorQ.top());
                priorQ.pop();
            }
        } 
        if (input != 0) {
            priorQ.push(input);
        }
    }
}