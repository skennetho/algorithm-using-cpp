//10866: 덱
#include<iostream>
#include<deque>
#include "string.h"

using namespace std;
/*
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int main(){
    int n;
    cin>> n;
    scanf("%d", &n);
    // string input;
    char input[20];
    int num;
    deque<int> deq;
    for(int i =0 ;i < n ; i++){
        scanf("%s", &input);        
        if(!strcmp(input, "push_front")){
            scanf("%d", &num);
            deq.push_front(num);
        }else if(!strcmp(input, "push_back")){
            scanf("%d", &num);
            deq.push_back(num);
        }else if(!strcmp(input, "pop_front")){
            if(!deq.empty()){
                cout<<deq.front() <<'\n';
                deq.pop_front();
            }else{
                cout<< "-1\n";
            }
        }else if(!strcmp(input, "pop_back")){
            if(!deq.empty()){
                cout<<deq.back() <<'\n';
                deq.pop_back();
            }else{
                cout<< "-1\n";
            }
        }else if(!strcmp(input, "size")){
            cout<<deq.size()<< '\n';
        }else if(!strcmp(input, "empty")){
            cout<<(deq.empty() ? 1 : 0)<< '\n';
        }else if(!strcmp(input, "front")){
            cout<<(deq.empty() ? -1 : deq.front())<< '\n';
        }else if(!strcmp(input, "back")){
            cout<<(deq.empty() ? -1 : deq.back())<< '\n';
        }
    }
}