#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n ; 
    cin >> n ;

    int arr[10001]= {0};

    for(int i =0 ;i< n ; i++){
        int num;
        cin >> num;
        ++arr[num];
    }

    for(int num =0 ; num < 10001 ; num++){
        for(int j = 0 ; j < arr[num]; j++){
            cout<< num << '\n';
        }
    }
}
