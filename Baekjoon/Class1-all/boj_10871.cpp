#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n ,x, temp;
    cin>> n>> x;
    vector<int> answer;
    for(int i =0; i<n;i++){
        cin>> temp;
        if(temp <x)answer.push_back(temp);
    }
    
    for(int &i : answer){
        cout<< i<< " ";
    }
    cout<<endl;
}