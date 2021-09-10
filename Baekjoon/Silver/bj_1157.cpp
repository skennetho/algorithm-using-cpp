
#include <iostream>
#include <string>
#include <map>

using namespace std;

void solution(string str){
    map<char, int> count;
    for(char &c : str) c= toupper(c);
    
    for(char &ch : str){
        if(count.find(ch) != count.end()){
            count[ch]+=1;
        }else{
            count.insert({ch, 0});
        }
    }
    int big =-1;
    char ch = ' ';

    for (const auto &iter :  count )  {
        if(big < iter.second) {
            ch = iter.first;
            big = iter.second;
        }
        else if (big == iter.second) {
            ch ='?';
        }
    }
    cout<< ch<<endl;
}

int main(){
    string str;
    cin>> str;
    solution(str);

    str = "Mississipi";
    solution(str);
    str = "zZa";
    solution(str);
    str = "a";
    solution(str);
}

