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
             cout<< dice +1 <<endl;
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

/*
    ladders는 올라간다.
    snakes는 내려간다.

    뱀과 주사위를 그저 지름길로 퉁쳐도 된다. 모든 경우를 뒤져야알수 있기 때문. 그럼 BFS?
    bfs에서 next노드는 다음과 같다.
    - 주사위 한번으로 도달할수 있는 지름길"들"(뒤 또는 앞)
        노드의 경우 visited체크를 해준다.
    - 주사위 6.

    */