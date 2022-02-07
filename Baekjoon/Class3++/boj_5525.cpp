//https://www.acmicpc.net/problem/5525
// IOIOI
#include <iostream>
#include <string>

using namespace std;

#define INIT_COUNT 0;

void countIOIandUpdateResult(const string& s, const int& n, int& result) {
    bool begin;
    int count = INIT_COUNT;
    for (int i = 0; i < s.size() - 1; i++){
        if (s[i] == 'I') {
            if (s[i + 1] == 'I') {
                count = INIT_COUNT;
                continue;
            }
            while (s[i + 1] == 'O' && s[i + 2] == 'I') {
                i += 2;
                count++;
            } 
            if (count >= n) {
                result += count - n + 1;
            }
            count = INIT_COUNT;
        }
    }
}

int main() {
    int n, sLength; 
    string s;

    cin >> n >> sLength;
    cin >> s;

    int result = 0;
    countIOIandUpdateResult(s, n, result);

    cout << result << '\n';
}

/**
 * 풀이
 * P1은 P2에 2개 들어있다.
 * 같은 이치로 Pn은 Px에 x-n+1개 들어있다. 
 * 
 * IOI판별법-1
 * 그럼 문자열을 받을때 "IO"가 연속으로 나올때 몇(x)번 나오는지 세고
 *  "II" 나오면 Px, "O"가 나오면 Px-1로 판단한다.
 * 
 * IOI판별법-2
 * 문자열에서 I가 시작하는 위치를 찾는다.
 * I가 시작하는 위치에서 다음과 다다음이 O,I라면 count++를 한다.
 * 만약 위치가 길이-2보다 크다면 count를 그만한다.
 * 
 * 기본 0으로 시작하는 result변수에
 * Px (x>0)이 나온다면 x-n+1을 더한다.
 * Px (x==0)이 나온다면 넘어간다.
 * 
 * 마지막에 result를 출력한다.
 * 
 * 
 * 
 * I > IO, II > IOI, IOO, III, IIO
 *               ^
 * O > OI, OO > OII, OIO, OOI, OOO > OIII, OIIO, OIOI, OIOO, OOII, OOIO, OOOI, OOOO
 *                                                ^
 * 
 * I가 나오는 위치를 찾고 OI가 반복되는 수를 카운트 하는게 좋은 방법?
 * 그럼 로직은 아래와 같나?
 * 하나를 꺼내어 확인한다.
 * - I라면 시작
 *   - 그다음과 다다음이 OI라면 count++, 
 *      - 루프의 위치를 OI가 지난후로 이동
 *   - I라면 위치를 다음으로
 *   - 위둘다 아니라면 result 업데이트,
 * - O라면 패쓰
 * 
 * 2
25
OOIOIIOIOIOIOIOIOIOIOOIOI
     ^ ^ ^ ^ ^ ^ 
=> 6
 */