//https://www.acmicpc.net/problem/1389
// 케빈 베이컨의 6단계 법칙
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 101;
int steps[101][101];


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        fill(steps[i]+1 ,steps[i]+1+n, MAX);
        steps[i][i] = 0;
    }

    while(m-- > 0) {    
        int a, b;
        scanf("%d %d", &a, &b);
        steps[a][b] = 1;
        steps[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int from = 1; from <= n; from++) {
            for (int to = 1; to <= n; to++) {
                if (steps[from][to] > steps[from][k] + steps[k][to]) {
                    steps[from][to] = steps[from][k] + steps[k][to];
                }
            }
        }
    }

    int sum = 0;
    int shortest = MAX;
    int result;
    for (int i = 1; i <= n; i++) {
        sum = 0; 
        for (int j = 1; j <= n; j++) {
            sum += steps[i][j];
        }

        if (shortest > sum) {
            shortest = sum;
            result = i;
        }
    }

    printf("%d\n", result);
}


////old version using bfs
// bool isConnected(vector<vector<bool>> arr, int from, int to) {
//     return arr[from][to];
// }

// int getShortestStep(vector<vector<bool>> arr, int from, int to) {
//     if (from == to) {
//         return 0;
//     }
//     queue<pair<int, int>> Q;
//     Q.emplace(make_pair(from, 0));
//     bool visited[arr.size()] = {false};visited[from] = true;

//     while(!Q.empty()) {
//         pair<int, int> node = Q.front();
//         if (node.first == to) { 
//             return node.second; //모든 관계는 연결되어있다.
//         }
//         if (isConnected(arr, node.first, to)) {
//             return node.second + 1;
//         }

//         Q.pop();
//         for (int i = 1; i < arr.size(); i++) {
//             if (visited[i] || !isConnected(arr, node.first, i)) continue;
//             visited[i] = true;
//             Q.emplace(i, node.second + 1);
//         }
//     }
//     return 0; //unreachable
// }

// int main() {
//     int n, m;
//     scanf("%d %d", &n, &m);

//     vector<vector<bool>> arr(n + 1, vector<bool>(n + 1, false));
//     vector<vector<int>> shortestSteps(n + 1, vector<int>(n + 1, 0));

//     int a, b;
//     for (int i = 0; i < m; i++) {
//         scanf("%d %d", &a, &b);
//         arr[a][b] = true;
//         arr[b][a] = true;
//         shortestSteps[a][b] = 1;
//         shortestSteps[b][a] = 1;
//     }

//     int sums[n + 1];
//     sums[0] = INT32_MAX;
//     int kevinBacon = 0;
//     for (int i = 1; i <= n; i++) {
//         sums[i] = 0;
//         for (int j = 1; j <= n; j++) {
//             if (i == j) continue;
//             if (shortestSteps[i][j] == 0) {
//                 int shortStep = getShortestStep(arr, i, j);
//                 shortestSteps[i][j] = shortStep; 
//                 shortestSteps[j][i] = shortStep;
//             }
            
//             sums[i] += shortestSteps[i][j];
//         }

//         if (sums[kevinBacon] > sums[i]) {
//             kevinBacon = i;
//         } 
//     }

//     printf("%d\n", kevinBacon);
// }
