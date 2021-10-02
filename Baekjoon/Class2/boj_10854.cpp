#include<iostream>
#include<queue>
#include <string>


using namespace std;

int main(){
    int n;
    cin>> n;
    string input;
    int num;
    queue<int> que;
    for(int i =0 ;i < n ; i++){
        cin>>input;
        
        if(input == "pop"){
            if(!que.empty()){
                cout << que.front() <<'\n';
                que.pop();
            }else{
                cout << -1 <<'\n';
            }
        }else if(input == "size"){
            printf("%d\n", que.size() );
        }else if(input ==  "empty"){
            printf("%d\n", (que.empty()? 1 : 0));
        }else if(input ==  "front"){
            printf("%d\n", (que.empty()? -1 : que.front() ));
        }else if(input ==  "back"){
            printf("%d\n", (que.empty()? -1 : que.back() ));
        }else{
            cin>> num;
            que.push(num);
        }
    }
}