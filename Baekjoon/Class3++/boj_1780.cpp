//https://www.acmicpc.net/problem/1780
// 종이의 개수
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pieceData {
    int x, y, size;
    pieceData(int _x, int _y, int _size) : x(_x), y(_y), size(_size) {}
};

vector<vector<int>> paper;
queue<pieceData> paperQ;
int counter[3]; 


void cutInto9Pieces(pieceData data) {
    if (data.size == 1) {
        return;
    }
    int cutSize = data.size/3;

    for (int i = data.y; i < data.y + data.size; i += cutSize) {
        for (int j = data.x; j < data.x + data.size; j += cutSize) {
            paperQ.emplace(pieceData(j, i, cutSize));
        }
    }
}

bool CountIfAllSame(pieceData data) {
    for (int i = data.y; i < data.y + data.size; i++) {
        for (int j = data.x; j < data.x + data.size; j++) {
            if (paper[data.y][data.x] != compare) return false;
        }
    }
    counter[paper[data.y][data.x] + 1]++;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    paper.assign(n, vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &paper[i][j]);
        }
    }
    paperQ.emplace(pieceData(0,0,n));
    
    while (!paperQ.empty()) {
        if (CountIfAllSame(paperQ.front())) {
            paperQ.pop();
            continue;
        }
        cutInto9Pieces(paperQ.front());
        paperQ.pop();
    }

    printf("%d %d %d\n", counter[0], counter[1], counter[2]);
}
/**
 * 풀이:
 * 정말 9개로 자른뒤에 하나씩 찾으면서 다 똑같은 수만 있는지 찾아야하나?
 * 맞다. 하나의 수로만 이루어진 종이인지 확인하려면 하나씩 전부 뒤져야한다.
 * 
 * 차라리 어떤 자료구조를 사용할지가 더 관건이겠다. 
 * 2차원 벡터를 사용하고 스택에 현재 잘려진 종이의 데이터(x시작점, y시작점, 사이즈)를 푸시하는것으로 해보자.
 * 
 */