//https://www.acmicpc.net/problem/1992
// 쿼드트리
#include <iostream>

using namespace std;

const int MAX = 64;
char image[MAX][MAX];

char checkCompressable(int x, int y, int blockSize) {   //x 가로, y 세로,  좌상단에서 우하단으로 증가.
    char base = image[x][y];
    for (int i = x; i < x + blockSize; i++) {
        for (int j = y; j < y + blockSize; j++) {
            if (base != image[i][j]) {
                return 'X';
            }
        }
    }
    return base;
}

void doCompressQuad(int x, int y, int blockSize) {
    if (checkCompressable(x, y, blockSize) == 'X'){
        printf("(");

        int halfBlockSize = blockSize / 2;
        for (int i = x; i < x + blockSize; i += halfBlockSize) {
            for (int j = y ; j < y + blockSize; j += halfBlockSize) {
                doCompressQuad(i, j, halfBlockSize);
            }
        }
        printf(")");
    } else {
        printf("%c", image[x][y]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", &image[i]);
    }

    doCompressQuad(0, 0, n);
    printf("\n");
}