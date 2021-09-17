#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a, string b){
    if(a.length() != b.length())
        return a.length()<b.length();
    return a<b;
}

int main(){
    int n;
    cin>> n;
    int flag;

    vector<string> arr;
    for(int i =0 ; i <n ; i++){
        string str;
        cin>>str;
        // flag = false;
        // for(int j = 0; j<arr.size() ; j++){
        //     if(arr[j] == str){
        //         flag = true;
        //         break;
        //     }
        // }
        // if(flag) continue;

        if(find(arr.begin(), arr.end(), str) == arr.end())
            arr.push_back(str);
    }

    sort(arr.begin(), arr.end(),compare);

    // for(string &str: arr){
    //     cout<< str<<endl;
    // }
    for(int i =0 ; i< arr.size() ; i++){
        cout<< arr[i]<<'\n';
    }
}
