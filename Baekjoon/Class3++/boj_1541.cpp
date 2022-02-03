//https://www.acmicpc.net/problem/1541
// 잃어버린 괄호
#include <iostream>

using namespace std;

int main() {

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
*/