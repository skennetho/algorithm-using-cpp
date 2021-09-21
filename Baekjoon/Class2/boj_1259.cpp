#include<iostream>
#include<vector>

using namespace std;

int main(){
    string str;
    vector<string> arr;

    while(str[0] != '0'){
        cin>> str;
        if(str[0] == '0'){
            break;
        }

        int start = 0 , end = str.length()-1;
        if(str.length() == 1){
            arr.push_back("yes");
            continue;
        }
        
        while(start<end){
            if(str[start] != str[end]){
                break;
            }
            start++;
            end--;
        }
        if(str[start] != str[end]){
            arr.push_back("no");
        }else{
            arr.push_back("yes");
        }
    }

    for(string &str: arr){
        cout<< str<<'\n';
    }
    
}