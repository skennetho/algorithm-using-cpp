//https://www.acmicpc.net/problem/1074
// Z
#include <iostream>
#include <cmath>

using namespace std;

int dp1_arr[2][2] = {{0, 1}, {2, 3}};

int getMultiplicand(int r, int c, int box_size){
    if ((box_size / 2) <= r) {
        if ((box_size / 2) <= c) {  //4�и�
            return 3;
        } else {                    //3�и�
            return 2;
        }
    } else {
        if ((box_size / 2) <= c) {  //1�и�
            return 1;
        } else {                    //2�и�
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
1. �־��� n�� ��쿡 ���� ���̺�(1�����迭)�� �̸� �����Ѵ�. ���̺����� �������� ���ִ�.
    ex) n = 1  : [0, 1, 2, 3], n=2: [0,1,4,5,2,3,6,7,8,9,12,13,10,11,14,15]    
    1-1. ��ȭ���� �����. "0 <= r,c <= (2^n -1)" �϶� r�� c�� "0 <= r', c' <= (((2^n)/2)-1)" �� ��ǥ�� �������ְ�
    1-2. 2^(n-1)*2^(n-1)���ٰ� �߾ӿ� x,y�������� �׾��ٴ� �����Ͽ� 2�и��� 0, 1�и��� 1, 3�и��� 2, 4�и� 3�� �����ش�. 
    1-3. 1-2���� r',c'�� ���� �����ش�. 
    1-4. d(n)[r,c] = d(n-1)[r',c'] + {0~3} * 2^(n-1) * 2^(n-1)
2. r,c�� 1���� �迭������ index�� ��ȯ�Ѵ�.
3. �ش� index�� �ִ� ���� ����Ѵ�.
*/