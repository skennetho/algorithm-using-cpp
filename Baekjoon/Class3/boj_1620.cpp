#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
/*
- 데이터는 int와 string이 한짝 꼭 한짝이어야함.
- map을 하나만 사용하면 string으로  int는 쉽게 가져오나 그 반대는 힘듬.
    - 그렇다면 map을 두개 사용하면?
    - 두개 사용하는것보다 하나의 map에 insert할때 [이름,번호], [번호,이름] 둘다 하면 되네?
        - 하지만 최악의 경우 100만번 입력이 주어질텐데 그럼 200만번의 insert과정을 해야하다니
- int를 통해 string을 가져오는 경우는 string 배열을 사용하자!
*/
int main(){
    int n , m ;
    scanf("%d %d", &n, &m);
    unordered_map<string, string> pokemon_doc;
    // string pokemon_names

    char pokemon_name[20];
    for(int i =0 ; i < n ; i++){
        scanf("%s", &pokemon_name);
        string name(pokemon_name);
        string number = to_string(i+1);
        pokemon_doc.insert({name, number});
        pokemon_doc.insert({number, name});
    }

    for(int i =0 ;i < m ; i++){
        scanf("%s", &pokemon_name);
        string name(pokemon_name);
        printf("%s\n",pokemon_doc.at(name).c_str() );
    }
}