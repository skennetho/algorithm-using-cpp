#include<iostream>
 
using namespace std;

int main(){
    int T, k, n;
    cin >> T;
    
    for(; T>0; T--){
        cin >> k>> n;
        int arr[14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
        int count;
        for(int j =0 ; j <k ; j++){
            count =0;
            for (int room =0 ; room < n; room++){
                count += arr[room];
                arr[room]= count;
            }
        }
        cout<< arr[n-1]<< endl;
    }
}