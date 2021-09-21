#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

int main(){
    int n , x, y; 
    vector<pair<int, int>> list;
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        cin>> x>> y;
        list.push_back(make_pair(x, y));
    }

    sort(list.begin(), list.end());

    for(pair<int, int> &p : list){
        printf("%d %d\n", p.first, p.second);
    }
}