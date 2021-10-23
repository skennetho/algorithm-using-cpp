//10866: ��
#include<iostream>
#include<deque>
#include "string.h"

using namespace std;
/*
push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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