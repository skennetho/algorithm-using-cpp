#include <iostream>

using namespace std;

void solution(int a, int b){
    cout<< a+b<<endl;
    cout<< a-b<< endl;
    cout<< a*b<< endl;
    cout<< a/b<<endl;
    cout<< a%b<<endl;
}

int main(){
    int a, b;
    cin>>a >>b;
    solution(a,b);

    return 0;
}