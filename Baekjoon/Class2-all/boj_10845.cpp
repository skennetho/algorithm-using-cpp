#include<iostream>
#include<queue>
#include<cstring>
#include<cstdlib>

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

int main_2(){
    int n;
    scanf("%d", &n);
    char* input;
    int num;
    queue<int> que;

    while( n-- >0 ){
        scanf("%s", &input );
        if( strcmp(input, "pop")){
            printf("%d\n", que.back());
            que.pop();
        }else if( strcmp(input, "size")){
            printf("%d\n", que.size() );
        }else if( strcmp(input, "empty")){
            printf("%d\n", (que.empty()? 1 : 0));
        }else if( strcmp(input, "front")){
            printf("%d\n", (que.empty()? -1 : que.front() ));
        }else if( strcmp(input, "back")){
            printf("%d\n", (que.empty()? -1 : que.back() ));
        }else{
            char *ch = strtok(input, " ");
            ch = strtok(NULL, " ");
            que.push( atoi(ch));
        }
    }
}