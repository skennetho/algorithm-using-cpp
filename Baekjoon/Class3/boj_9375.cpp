//https://www.acmicpc.net/problem/9375
#include<iostream>
#include<map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcase, n;
    cin>> testcase;
    while(testcase--){
        cin >> n;
        map<string, int> cloths;
        string name, type;
        for(int i =0 ; i < n ; i++){
            cin>> name >> type;
            if(cloths.find(type) == cloths.end()){
                cloths.insert({type, 1});
            }else{
                cloths[type]++;
            }
        }

        int prob = 1 ;
        for(auto &cloth : cloths){
            prob *= (cloth.second+1);
        }
        cout<< (prob-1)<<"\n";
    }
}
