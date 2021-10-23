//10773: Á¦·Î
#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> num_stk;
    int n ,num;
    cin >> n;

    while(n--> 0){
        cin>> num;
        if(!num && !num_stk.empty()){
            num_stk.pop();
            continue;
        }
        num_stk.push(num);
    }

    int sum =0;
    while(!num_stk.empty()){
        sum+= num_stk.top();
        num_stk.pop();
    }
    cout<< sum << endl;
}