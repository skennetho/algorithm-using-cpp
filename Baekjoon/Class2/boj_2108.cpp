//2108: ≈Î∞Ë«–
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int> arr(n);
    int counter[8001] = {0};
    double sum = 0;
    for(int i =0 ; i< n ; i++){
        cin>> arr[i];
        sum+= arr[i];
        counter[arr[i] + 4000]++;
    }
    //arithmetic mean
    cout<< floor(sum/(double)n + 0.5) << endl; 

    //center number
    sort(arr.begin(), arr.end());                
    cout<< arr[n/2] << endl;   //n is always odd number.
    
    //frequent number
    int big1 =0, big2=0; ;
    bool is_big1_alone = true;
    for(int i = 8000; i>=0; i-- ){
        if(counter[big1]< counter[i]){
            big2= big1;
            big1 =i;
            is_big1_alone = true;
        }
        if(counter[big1]==counter[i]){
            big2= big1;
            big1 =i;
            is_big1_alone = false;
        }

    }
    cout<< (is_big1_alone ? big1-4000 : big2-4000) << endl;

    //range
    cout<< arr.back() - arr.front() <<endl;
    // -2 -1 0 1 2 size (2*2 +1)
}