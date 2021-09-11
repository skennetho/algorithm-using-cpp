#include <iostream>

using namespace std;

int main(){
    int n;
    cin>> n;
    string strs[n];
    int cnt;
    string str;

    for(int i =0 ; i<n ; i++){
        cin>> cnt;
        cin>> str;
        strs[i] = "";
        for(char &c : str){
            for(int j =0 ; j < cnt; j++){
                strs[i]+=c;
            }
        }
    }

    for(string s: strs){
        cout<<s<<endl;
    }
}