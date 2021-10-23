//4949: ±ÕÇüÀâÈù ¼¼»ó
#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    stack<char> stk;
    bool answer;

    getline(cin, str);
    while(str[0] != '.'){
        answer= true;
        stk = {};
        for( char &ch : str){
            if(ch == '(' || ch == '['){
                stk.push(ch);
            }else if( ch == ']'){
                if(stk.empty() || stk.top() != '['){
                    answer =false;
                    break;
                }else{
                    stk.pop();
                }
            }else if( ch == ')'){
                if(stk.empty() || stk.top() != '('){
                    answer =false;
                    break;
                }else{
                    stk.pop();
                }
            }
        }
        cout<< (answer && stk.empty()? "yes" : "no") <<endl;
        getline(cin, str);
    }
}