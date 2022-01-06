//https://www.acmicpc.net/problem/2606
#include<iostream>
using namespace std;

bool relation[101][101] = {false};
bool visited[101] = {false};
int n;
int count = 0;
void dfs(int curr){
    visited[curr] = true;
    count++;
    // printf("current : %d, count: %d \n",curr, count );

    for(int i = 1; i<=n ; i++){
        if(( relation[curr][i] || relation[i][curr] ) && !visited[i]){
            dfs(i);
        }
    }
}

int main(){
    scanf("%d", &n);
    int connection;
    scanf("%d", &connection);

    int a, b;
    for(int i =0 ; i < connection ;i++){
        scanf("%d %d", &a, &b);
        if( a > b ) swap( a, b );
        relation[a][b] = true;
    }

    dfs(1);

    printf("%d", count-1);
}