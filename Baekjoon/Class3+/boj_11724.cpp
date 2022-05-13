// //https://www.acmicpc.net/problem/11724
// //연결 요소의 개수
// #include <iostream>
// #include <vector>

// using namespace std;

// void dfsMakeConnectedNodeIntoFalse(vector<vector<bool>>& arr, int x) {
//     for (int i = 0; i < arr[x].size(); i++) {
//         if (arr[x][i] == true) {
//             arr[x][i] = false;
//             dfsMakeConnectedNodeIntoFalse(arr, i);
//         }
//     }
// }

// int main() {
//     int n; //정점의 개수
//     int m; //간선의 개수
//     scanf("%d %d", &n, &m);

//     vector<vector<bool>> arr(n,vector<bool>(n, false));
//     for (int i = 0; i < n; i++) {
//         arr[i][i] = true;
//     }

//     int u, v;
//     for (int i = 0; i < m; i++) {
//         scanf("%d %d", &u, &v);
//         arr[v - 1][u - 1] = true;
//         arr[u - 1][v - 1] = true;
//     }

//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i][i]) {
//             dfsMakeConnectedNodeIntoFalse(arr, i);
//             count++;
//         } 
//     }
//     printf("%d\n", count);
// }


#include <bits/stdc++.h>
using namespace std;
int area[1010];
int ranker[1010];

int find(int n){
    if(area[n]!=n) {
        return area[n] = find(area[n]);
    }
    else {
        return n;
    }
}
void uni(int a,int b){
    a = find(a);
    b = find(b);

    if(a==b) return;

    if(ranker[a]<ranker[b]){
        area[b]=a;
    }
    else {
        area[a]=b;
        if(ranker[a]==ranker[b]) ranker[a]++;
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);    

    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        area[i]=i;
        ranker[i]=0;
    }
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        uni(u,v);
    }
    int count = 0;
    for(int i=1;i<=n;i++) if(area[i]==i) count++;
    cout << count;
    return 0;
}
