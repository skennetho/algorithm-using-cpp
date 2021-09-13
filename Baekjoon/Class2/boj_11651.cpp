#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main(){
    int n, x,y;
    vector<pair<int, int>> list;
    cin>> n;

    for(int i =0; i < n ; i++){
        cin>> x >> y;
        list.push_back(make_pair(y,x));
    }

    sort(list.begin(), list.end());
    for(int i =0 ; i< n; i++){
        cout<< list[i].second<<" "<< list[i].first<<endl;
    }
}