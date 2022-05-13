//https://www.acmicpc.net/problem/7576
// 토마토
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
마치 물에 돌을 여러개 던지고 물결이 퍼지는 형식으로 보인다.
1. 익은 토마토 주변으로 퍼져나가기
    - 익은 토마토들의 리스트 생성
    - 리스트 업데이트
        - 하나의 토마토를 꺼내 주변토마토들을 리스트에 추가하고 꺼낸토마토는 리스트에서제거
    - 한번 업데이트 할때마다, 하루지남.
    - 리스트가 비었는데도, 여전히 남은 토마토가 존재한다면 -1 출력.
    - 그러나 배열의 모든 원소를 들려야한다.
    - 모든 원소를 들리지 않아도 되는 방법은 없나?

출력:
- 0 : 이미 다 익은 경우
- -1 : 절대 익을 수 없는 토마토가 존재하는경우.
- 나머지 : 전체가 익기까지의 기간.
*/


/*
하데스의 장점은 로그라이트에서의 죽음이 리셋인데, 스토리로 리셋의 단점을 보완했다. 죽어야만 스토리진행이 됨. 
*/