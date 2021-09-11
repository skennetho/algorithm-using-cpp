#include <iostream>

using namespace std;

int main(){
    int state= 0;
    int n;
    cin>> n;
    int pre = n;
    for(int i =1 ; i< 8;i++){
        cin>> n;
        if(pre < n){
            if(state ==1){
                state =0;
                break;
            }
            state = 2;
        }else if(pre > n){
            if(state ==2){
                state =0;
                break;
            }
            state =1;
        }
        pre =n;
    }

    if(state ==0){
        cout<<"mixed"<<endl;
    }else if(state ==1){
        cout<< "descending"<<endl;
    }else{
        cout<<"ascending"<<endl;
    }
}