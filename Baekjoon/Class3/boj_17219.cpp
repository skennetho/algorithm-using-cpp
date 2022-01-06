//https://www.acmicpc.net/problem/17219

#include<iostream>
#include<map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin>> n >> m;

    map<string, string> password_map;
    for(int i =0 ; i< n ; i++){
        string website, password;
        cin >> website >> password;
        password_map.insert({website, password});
    }

    map<string, string>::iterator pw_iter;
    for(int i = 0 ; i< m ; i++){
        string website;
        cin>> website;
        pw_iter =password_map.find(website);
        string password = pw_iter->second;
        cout<<password<< '\n';
    }
}
