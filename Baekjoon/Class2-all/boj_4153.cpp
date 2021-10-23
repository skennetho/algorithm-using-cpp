#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<string> arr;

    while(true){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if( a == 0  && b == 0 && c ==0)
            break;

        if(a*a + b*b ==c*c || a*a + c*c == b*b || b*b+ c*c == a*a){
            arr.push_back("right");
        }else{W
            arr.push_back("wrong");
        }
    }

    for(string &s : arr){
        cout<< s <<'\n';
    }
}