//https://www.acmicpc.net/problem/1074
// Z
#include <iostream>
#include <cmath>

using namespace std;

int dp1_arr[2][2] = {{0, 1}, {2, 3}};

int getMultiplicand(int r, int c, int box_size){
    if ((box_size / 2) <= r) {
        if ((box_size / 2) <= c) {  //4분면
            return 3;
        } else {                    //3분면
            return 2;
        }
    } else {
        if ((box_size / 2) <= c) {  //1분면
            return 1;
        } else {                    //2분면
            return 0;
        }
    }
}

int downgradeCoordinate(int rc, int box_size) {
    if ((box_size / 2) <= rc) {
        rc -= (box_size / 2);
    } 
    return rc;
}

int dp(int r, int c, int n) {
    if (n == 1) {
        return dp1_arr[r][c];
    }
    
    int box_size = (int)pow(2.0, (double)n);
    int add = getMultiplicand(r, c, box_size) * (box_size/2) * (box_size/2) ;
    r = downgradeCoordinate(r, box_size);
    c = downgradeCoordinate(c, box_size);
    return dp(r, c, n - 1) + add;
}

int main() {
    int n;
    scanf("%d", &n);

    int r, c;
    scanf("%d %d", &r, &c);
    
    int result = dp(r, c, n);
    printf("%d", result);
}

/*
1. 주어진 n의 경우에 맞춰 테이블(1차원배열)을 미리 생성한다. 테이블에서는 순서값이 들어가있다.
    ex) n = 1  : [0, 1, 2, 3], n=2: [0,1,4,5,2,3,6,7,8,9,12,13,10,11,14,15]    
    1-1. 점화식을 만든다. "0 <= r,c <= (2^n -1)" 일때 r과 c를 "0 <= r', c' <= (((2^n)/2)-1)" 로 좌표를 수정해주고
    1-2. 2^(n-1)*2^(n-1)에다가 중앙에 x,y교차선을 그었다는 가정하에 2분면은 0, 1분면은 1, 3분면은 2, 4분면 3을 곱해준다. 
    1-3. 1-2값을 r',c'의 값에 더해준다. 
    1-4. d(n)[r,c] = d(n-1)[r',c'] + {0~3} * 2^(n-1) * 2^(n-1)
2. r,c를 1차원 배열에서의 index로 변환한다.
3. 해당 index에 있는 수를 출력한다.
*/