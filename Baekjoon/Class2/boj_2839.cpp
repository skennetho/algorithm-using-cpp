#include<iostream>
#include<vector>

using namespace std;
const int MAX = 5000;

int memo[MAX+1];

int count( int kilo){

    if(memo[kilo]!= -1){
        return memo[kilo];
    }

    memo[kilo] = 1+ min(count(kilo-3) , count (kilo -5)) ;
    return memo[kilo];
}

int main(){
    fill_n(memo, MAX+1, -1);
    memo[0]= MAX;
    memo[1]= MAX;
    memo[2]= MAX;
    memo[3]= 1;
    memo[4]= MAX;
    memo[5]= 1;
    memo[6]= 2;
    memo[7]= 1;

    int kilo;
    cin>> kilo;
    
    int cnt_min = count(kilo);
    cnt_min = cnt_min>=MAX ? -1 : cnt_min;
    cout<< cnt_min<<'\n';
}