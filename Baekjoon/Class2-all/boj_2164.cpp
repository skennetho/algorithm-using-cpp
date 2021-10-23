#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n ; 
    scanf("%d", &n);
    queue<int> que;
    int arr[n];

    for(int i =1 ;i <=n ;  i++){
        que.push(i);
    }

    while(que.size() != 1){
        que.pop();
        int card = que.front();
        que.pop();
        que.push(card);
    }

    cout<< que.front() << '\n';
}