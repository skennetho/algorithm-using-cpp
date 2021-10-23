#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binSearch( vector<int> &arr, int num){
    int start =0, mid, end= arr.size()-1;

    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid] == num){
            return 1;
        }else if(arr[mid] < num){
            start =mid+1;
        }else if(arr[mid] > num){
            end = mid -1;
        }
    }
    return 0;
}

int main(){
    int n,m; 
    scanf("%d", &n);
    vector<int> nlist(n);
    for(int i =0 ; i< n ; ++i){
        scanf("%d", &nlist[i]);
    }
    
    scanf("%d", &m);
    vector<int> mlist(m);
    for(int i =0 ; i< m ; ++i){
        scanf("%d", &mlist[i]);
    }

    sort(nlist.begin(), nlist.end());

    for(int &mNum : mlist){
        cout << binSearch(nlist, mNum) << '\n';
    }
}

// int main(){
//     int n,m; 
//     scanf("%d", &n);
//     vector<int> nlist(n);
//     for(int i =0 ; i< n ; ++i){
//         scanf("%d", &nlist[i]);
//     }
    
//     scanf("%d", &m);
//     vector<int> mlist(m);
//     for(int i =0 ; i< m ; ++i){
//         scanf("%d", &mlist[i]);
//     }

//     sort(nlist.begin(), nlist.end());

//     for(int &mNum : mlist){

//         vector<int>::iterator _lower= lower_bound(nlist.begin(), nlist.end(), mNum );
//         if(_lower == nlist.end()){
//             cout << "0\n";
//             continue;
//         }
//         int low = _lower - nlist.begin() ;

//         vector<int>::iterator _upper = upper_bound(nlist.begin(),nlist.end(), mNum );
//         int upp =  _upper - nlist.begin();
//         cout<< upp - low << '\n';
//     }
// }