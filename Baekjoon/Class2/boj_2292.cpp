#include<iostream>

using namespace std;

int main(){
    int n ;
    cin >> n;
    if( n ==1 ){
        cout<< 1<< endl;
        return 0;
    }
    int bound_max=1, bound_count=1;
    while(bound_max< n){
        bound_max = bound_max + bound_count*6;
        bound_count++;
    }
    cout<<bound_count<<endl;
}

// void solve(int n){
//     if( n ==1 ){
//         cout<< 1<< endl;
//         return;
//     }
//     int bound_max=1, bound_count=0;
//     while(bound_max< n){
//         bound_count++;
//         bound_max = bound_max + bound_count*6;
//     }
//     cout<<bound_count+1<<endl;

// }
// int main(){
//     int n ;
//     cin >> n;
//     // for (int i =1 ; i < 40; i ++){
//     //     solve(i);
//     // }
// }


