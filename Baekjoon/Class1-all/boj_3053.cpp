#include <iostream>

using namespace std;

int main(){
    int num, count =0; 

    bool arr[42] ={ false, };
    
    for(int i =0; i< 10; i++){
        cin>> num;
        num =num%42;
        if(!arr[num]){
            arr[num]=true;
            count++;
        }
    }
    cout<< count<<endl;

    return 0;
}