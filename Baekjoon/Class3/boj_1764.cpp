//https://www.acmicpc.net/problem/1764
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int my_binary_search(vector<string> &vec, string &str){
    int start =0, end =vec.size(), mid;

    while(start<= end){
        mid = (start +end)/2;
        if(vec[mid] == str){
            return mid;
        }else if(vec[mid]> str){
            end = mid-1;
        }else if(vec[mid] < str){
            start = mid +1;
        }
    }
    if(vec[mid] != str){
        return -1;
    }
    return mid;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<string> unknown_names(n);
    vector<string> anonymouse_names;
    
    char str[20];
    for(int i =0; i< n; i++){
        scanf("%s", &str);
        string _str(str);
        unknown_names[i] = _str;
    }

    sort(unknown_names.begin(), unknown_names.end());

    for(int i =0; i< m; i++){
        scanf("%s", &str);
        string _str(str);
        if( binary_search(unknown_names.begin(), unknown_names.end(), _str)){
            anonymouse_names.push_back(_str);
        }
        // if(my_binary_search(unknown_names, _str ) >=0 ){
        //     anonymouse_names.push_back(_str);
        // }
    }

    sort(anonymouse_names.begin(), anonymouse_names.end());


    printf("%d\n", anonymouse_names.size());
    for(int i =0 ; i< anonymouse_names.size() ; i++){
        printf("%s\n", anonymouse_names[i].c_str());
    }

}
/*

*/