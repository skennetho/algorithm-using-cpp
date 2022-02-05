//https://www.acmicpc.net/problem/1541
// 잃어버린 괄호
#include <iostream>
#include<string>

using namespace std;

int main() {    
    string expression = "";
    cin >> expression;

    int sum = 0;
    bool IsMinusAppeared = false;
    string number = "";

    for (int i = 0 ; i <= expression.size(); i++) {
        if (expression[i] == '-' || expression[i] == '+' || i == expression.size()) {
            if (IsMinusAppeared) {
                sum -= stoi(number);
            } else {
                sum += stoi(number);
            }
            if (expression[i] == '-'){ 
                IsMinusAppeared = true;
            }
            number.clear();
        } else {
            number += expression[i];
        }
    }

    cout <<sum << '\n';
}

/***
 * 
 * 입력 
 * - 하나의 수
 * - 둘이상의 수와 그사이사이에 +,-가 있는 경우
 * 
 * 출력
 * - 괄호를 적절히 사용하여 최소의 결과값. ex) 50-55+30은 50-(55+30)이 최소 값이다.
 * 
 * 풀이:
 * 괄호는 랜덤하게 생성가능하다.
 * 그리고 dfs로 풀면 좋을것같다. 왜냐하면 괄호를 어디서든 넣어야하니까.
 * 괄호를 넣기위해서는 다음을 고려해야한다.
 * - 괄호를 넣을수 있는 곳은 문자열의 시작, 끝, 그리고 +나-의 옆 뿐이다.
 * 
 * 
 * 근데 괄호를 꼭 생각해야하나? 괄호는 계산의 순서를 정해줄 뿐이다.
 * 그럼 그냥 두개의 연산을 빼오기만 하면된다.
 * 예를들어 a-b+c에서 처음 고를 수 있는 계산은 a-b 이거나 b+c처럼 페어이다. 
 * 이런식으로 dfs를 써서 가장 최소의 값을 찾아보자. 
 * 
 * 결국 모든 경우를 들리는 수밖에 없을까?
 * 숫자의 수가 n이라 했을때 n-1크기의 bool배열을 준비한다. bool배열의 이름은 visited이고 visited의 인덱스 i는 i번째수와 i+1번째수의 짝을 의미한다.
 * 
 * ===========================================
 * 위방법보다 효율적인 방법을 찾았다. 최소의 수를 만들기위해선 어떤 조건이 필요하다.
 * 1. -를 기준으로 split했는데 결과가 하나인경우 == +만 있는 경우
 * 2. -를 기준으로 나누고 -기준 왼쪽은 최소 오른쪽은 최대가 되게 한다.
 * 3. 이 방법을 반복한다.
 * 
*/