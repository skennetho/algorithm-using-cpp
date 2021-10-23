#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
    int n ; 
    cin >> n;

    vector<pair<int, string>> vmap;
    
    for(int i =0 ; i< n; i++){
        int age;
        string name;
        cin>> age >> name;
        
        vmap.push_back(make_pair(age, name));
    }

    stable_sort(vmap.begin(), vmap.end(), 
                     [] (const auto &x, const auto &y) {return x.first < y.first;} ) ;   

    for(auto iter : vmap){
        cout<< iter.first << " "<<iter.second <<'\n';
    }
}