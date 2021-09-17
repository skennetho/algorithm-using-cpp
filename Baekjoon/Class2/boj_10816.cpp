#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int lower_bound(vector<int> & arr, int start, int end, int target){
    int mid = (start +end)/2;

    if(start>= end)
        return mid;

    if(arr[mid]< target){
        start = mid+1;
    }else{
        end =mid;
    }

    return lower_bound(arr, start, end, target);
}
int upper_bound(vector<int> & arr, int start, int end, int target){
    int mid = (start +end)/2;

    if(start>= end)
        return mid;

    if(arr[mid]<= target){
        start = mid+1;
    }else{
        end =mid;
    }

    return upper_bound(arr, start, end, target);
}
/*
6
1 1 2 2 3 3
3
1 2 3
*/
int main(){
    int n=0;
    cin>> n;
    vector<int> arr(n);
    for(int i =0 ; i< n ; ++i){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    int m;
    cin>>m;
    vector<int>  answer(m,0);
    for(int i =0; i<m ; ++i){
        int num;
        cin>> num;
        answer[i]= num;
    }

    for(int i = 0 ; i < m; i++){
        int lower = lower_bound(arr,0,n-1, answer[i]);
        int upper = upper_bound(arr,0,n-1, answer[i]);
        if( upper == n - 1 && arr[n-1]== answer[i])
            upper++;;
        answer[i]= upper - lower;
        // cout<< lower << ", " << upper<< " => "<<answer[i] <<'\n';
        cout<< answer[i] <<' ';
    }
    cout<<'\n';
}
