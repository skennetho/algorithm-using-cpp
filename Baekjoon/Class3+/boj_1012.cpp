//https://www.acmicpc.net/problem/1012
//¿Ø±‚≥Û πË√ﬂ
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define SOIL 0
#define CABAGE 1
#define LandMap vector<vector<int>>
int col, row, cabage;
void turnAdjecentCabagesIntoSoil(LandMap& landMap,int x, int y);


void dfsUpDownLeftRight(LandMap& landMap, int x, int y) {    
    if (x - 1 >= 0) {   //left
        turnAdjecentCabagesIntoSoil(landMap, x-1, y);
    }
    if (x + 1 < col) {  //right
        turnAdjecentCabagesIntoSoil(landMap, x+1, y);
    }
    if (y - 1 >= 0) {   //up
        turnAdjecentCabagesIntoSoil(landMap, x, y-1);
    }
    if (y + 1 < row) {  //down
        turnAdjecentCabagesIntoSoil(landMap, x, y+1);
    }
}

void turnAdjecentCabagesIntoSoil(LandMap& landMap,int x, int y) {
    if (landMap[y][x] != 1) return;
    landMap[y][x] = SOIL;
    dfsUpDownLeftRight(landMap, x, y);
}

void checkThisBlock(LandMap& landMap,int x, int y,int& bugCount) {
    if (landMap[y][x] == SOIL) return;
    bugCount++;
    turnAdjecentCabagesIntoSoil(landMap, x, y);
}

void calculateMinimumBug() {
    scanf("%d %d %d", &col, &row, &cabage);

    LandMap landMap(row, vector<int>(col, 0));
    int x, y, bugCount = 0;
    for (int i = 0; i < cabage; i++) {
        scanf("%d %d", &x, &y);
        landMap[y][x] = CABAGE;
    }
    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            checkThisBlock(landMap, x, y, bugCount);
        }
    }
    printf("%d\n", bugCount);
}

int main() {
    int testcases;
    scanf("%d", &testcases);

    while (testcases-- > 0) {
        calculateMinimumBug();
    }
}