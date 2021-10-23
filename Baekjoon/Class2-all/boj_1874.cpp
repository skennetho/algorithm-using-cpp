//1874: 스택 수열
#include<iostream>
#include<queue>
#include<stack>
#include<vector>

using namespace std;
/*
1~n의 수가 들어간 큐 arr을 준비한다. (pop하며 사용)
그리고 목표수열을 target에 담는다.

target를 루프한다. x++
    x번째 target의 수가 n이다.

    만약 스택바로 맨위가 n이 아니고 
         arr안에 n이 없다면 불가능
        있다면 n위치까지 arr의 앞수부터 차례로 스택에 푸시한다.
    스택의 바로위가 n이라면 패쓰 
*/

int main(){
   
    int x =0;
    stack<int> stk;
    queue<int> que;
    int n;
    scanf("%d",&n);

    int target[n];
    vector<bool> answer;    //T: push , F:pop
    for(int i = 0 ; i < n ; i++){
        que.push(i+1);
        scanf("%d", &target[i]);
    }


    while(x!=n){
        int num = target[x];
        
        while(!que.empty() && que.front()<=num){
            answer.push_back(true);
            stk.push(que.front());
            que.pop();
        }
        
        if(!stk.empty()&&stk.top() == num){
            answer.push_back(false);
            stk.pop();
        }else{
            break;
        }
        x++;
    }
    

    if( x == n){
        for(bool b : answer){
            cout<< (b? "+\n" : "-\n" );
        }
    }else{
        cout<< "NO\n";
    }

}