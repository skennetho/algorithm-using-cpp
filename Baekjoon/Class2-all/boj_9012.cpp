//9012:°ýÈ£

#include<iostream>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    char ch[n];
    int count; // this must be upper than 0 ALWAYS
    for(int i = 0 ; i< n ; i++){
        string str;
        cin>> str;
        count =0;
        for( int j=0; j < str.length(); j++){
            if (str[j] == '('){
                ++count;
            } else if( str[j] == ')'){
                --count;
            }

            if(count <0){
                break;
            }
        }

        if(count == 0 ){
            cout<< "YES\n";
        }else{
            cout<< "NO\n";
        }
    }
}