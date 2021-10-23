
#include<iostream>

using namespace std;

void solution(int hour, int min){
    if(min>=45){
        min -= 45;
    }else{
        min += 15;
        hour = hour>0 ? hour-1 : 23;
    }
    cout<<hour<<" "<< min<< endl;
}

int main(){
    int hour, min;
    cin>> hour;
    cin>> min;
    solution(hour, min);
}

