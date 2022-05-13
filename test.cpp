#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;
#include <string>
#include <vector>

using namespace std;


void dfs(vector<int>& numbers, int next, int cur, const int& target, int& answer) {
    if ( next == numbers.size()) {
        if (cur == target) answer++;
        return;
    } 

    dfs(numbers, next + 1, cur + numbers[next], target, answer);
    dfs(numbers, next + 1, cur - numbers[next], target, answer);

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, 0, target, answer);

    return answer;
}

int main() {
    vector<int> data = { 4, 1, 2, 1 };
    int target = 4;
    cout << solution(data, target) << endl;

  
}