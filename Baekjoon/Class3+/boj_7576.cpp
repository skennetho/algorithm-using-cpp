//https://www.acmicpc.net/problem/7576
// �丶��
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int width, height;
int tomato_left = 0;
int tomato_riped_today = 0;
int area[1000][1000];
queue<pair<int, int>> ripe_tomato_que;    //(col, row)

int ripenTomato(int col, int row) {
    if(area[col][row] != 0) {
        return 0;
    }
    area[col][row] = 1;
    ripe_tomato_que.emplace(make_pair(col,row));
    return 1;
}

int ripenTomatoSurrounded(int col, int row){
    int will_ripe_count = 0;
    if (col - 1 >= 0) {
        will_ripe_count += ripenTomato(col-1, row);
    }
    if (col + 1 < height) {
        will_ripe_count += ripenTomato(col+1, row);
    }
    if (row - 1 >= 0) {
        will_ripe_count += ripenTomato(col, row-1);
    }
    if (row + 1 < width) {
        will_ripe_count += ripenTomato(col, row+1);
    }
    return will_ripe_count;
}

void updateTomatoToday() {
    int will_ripe_tomorrow = 0;
    
    while(!ripe_tomato_que.empty() &&  tomato_riped_today-- > 0) {
        auto tomato = ripe_tomato_que.front();
        int surrounded = ripenTomatoSurrounded(tomato.first, tomato.second);
        will_ripe_tomorrow += surrounded;
        tomato_left -= surrounded;
        ripe_tomato_que.pop();
    }
    tomato_riped_today = will_ripe_tomorrow;
}

void startUpdatingTomatoQue(){
    int days = -1;
    while(ripe_tomato_que.size()) {
        updateTomatoToday();
        days++;
    }

    if (tomato_left > 0){
        printf("-1\n");
        return;
    }
    printf("%d\n", days);
}

int main() {
    scanf("%d %d", &width, &height);
    tomato_left = width * height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &area[i][j]);
            if (area[i][j] == 1) {
                ripe_tomato_que.emplace(make_pair(i,j));
                tomato_riped_today++;
                tomato_left--;
            } else if (area[i][j] == -1) {
                tomato_left--;
            }
        }
    }
    startUpdatingTomatoQue();
}

/*
��ġ ���� ���� ������ ������ ������ ������ �������� ���δ�.
1. ���� �丶�� �ֺ����� ����������
    - ���� �丶����� ����Ʈ ����
    - ����Ʈ ������Ʈ
        - �ϳ��� �丶�並 ���� �ֺ��丶����� ����Ʈ�� �߰��ϰ� �����丶��� ����Ʈ��������
    - �ѹ� ������Ʈ �Ҷ�����, �Ϸ�����.
    - ����Ʈ�� ����µ���, ������ ���� �丶�䰡 �����Ѵٸ� -1 ���.
    - �׷��� �迭�� ��� ���Ҹ� ������Ѵ�.
    - ��� ���Ҹ� �鸮�� �ʾƵ� �Ǵ� ����� ����?

���:
- 0 : �̹� �� ���� ���
- -1 : ���� ���� �� ���� �丶�䰡 �����ϴ°��.
- ������ : ��ü�� �ͱ������ �Ⱓ.
*/


/*
�ϵ����� ������ �α׶���Ʈ������ ������ �����ε�, ���丮�� ������ ������ �����ߴ�. �׾�߸� ���丮������ ��. 
*/