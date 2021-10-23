#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;;

int main(){
    int n;
    scanf("%d", &n);    
    vector<int> arr;

    //input is <1,000,000
    for(int i = 0 ; i< n ; i++){
        int num;
        scanf("%d", &num );
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());

    for(int &num: arr){
        printf("%d\n", num);
    }
}

// int main(){
//     int n;
//     scanf("%d", &n);

//     bool arr[1000000] = {false};

//     //input is <1,000,000
//     for(int i = 0 ; i< n ; i++){
//         int num;
//         scanf("%d", &num );
//         arr[num] = true;
//     }

//     for(int i =0 ; i < 1000000 ; i++){
//         if(arr[i]) printf("%d\n", i);
//     }
// }