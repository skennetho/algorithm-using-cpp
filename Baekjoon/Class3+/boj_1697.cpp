//https://www.acmicpc.net/problem/1697
// ¼û¹Ù²ÀÁú
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAX_TIME 100001
bool visited[MAX_TIME];

int bfs(int n, int target) {
    queue<pair<int,int>> tree;
    tree.push(make_pair(n, 0));
   visited[n] = true;

    while (!tree.empty()) {
        int node = tree.front().first;
        int time = tree.front().second;
        tree.pop();

        if (node == target) {
            return time;
        }

        if (node + 1 < MAX_TIME && !visited[node + 1]) {
            tree.push(make_pair(node + 1, time + 1));
            visited[node + 1] = true;
        }
        if (node - 1 >= 0 && !visited[node - 1]) {
            tree.push(make_pair(node - 1, time + 1));
            visited[node - 1] = true;
        }
        if (node * 2 < MAX_TIME && !visited[node * 2]) {
            tree.push(make_pair(node * 2, time + 1));
            visited[node * 2] = true;
        }        
    }
} 

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d", bfs(n, k));
}
