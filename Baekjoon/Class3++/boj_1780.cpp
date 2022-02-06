//https://www.acmicpc.net/problem/1780
// ������ ����
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
 * Ǯ��:
 * ���� 9���� �ڸ��ڿ� �ϳ��� ã���鼭 �� �Ȱ��� ���� �ִ��� ã�ƾ��ϳ�?
 * �´�. �ϳ��� ���θ� �̷���� �������� Ȯ���Ϸ��� �ϳ��� ���� �������Ѵ�.
 * 
 * ���� � �ڷᱸ���� ��������� �� �����̰ڴ�. 
 * 2���� ���͸� ����ϰ� ���ÿ� ���� �߷��� ������ ������(x������, y������, ������)�� Ǫ���ϴ°����� �غ���.
 * 
 */