//https://www.acmicpc.net/problem/16928
#include <iostream>
#include <queue>

using namespace std;

int shortcuts[101] = { 0 };

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int from, to;
    for (int i = 0; i < N + M; ++i) {
        scanf("%d %d", &from, &to);
        shortcuts[from] = to;
    }

    bool visited[101] = { false };
    queue<pair<int, int>> bfsQ;

    bfsQ.push({ 1,0 });
    visited[1] = true;

    while (!bfsQ.empty()) {
        int current = bfsQ.front().first;
        int dice = bfsQ.front().second;
        bfsQ.pop();

        if (current + 6 >= 100) {
            cout << dice + 1 << endl;
            break;
        }

        for (int i = current + 1; i <= current + 6 && i <= 100; i++) {
            if (!visited[i]) {
                bfsQ.push({ shortcuts[i] > 0 ? shortcuts[i] : i, dice + 1 });
                visited[i] = true;
            }
        }
    }
    return 0;
}
