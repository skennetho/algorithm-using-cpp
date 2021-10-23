#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    queue<int> que;
    queue<int> answer;
    for(int i =0 ;i< n ; i++){
        que.push(i+1);
    }
    
    while(!que.empty()){
        for(int i =1; i< k ; i++){
            que.push(que.front());
            que.pop();
        }
        answer.push(que.front());
        que.pop();
    }
    
    printf("<");
    cout<< answer.front();
    answer.pop();
    while(!answer.empty()){
        cout<<", "<<answer.front() ;
        answer.pop();
    }
    cout<< ">\n";
    
}