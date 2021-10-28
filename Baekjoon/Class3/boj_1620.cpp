#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
/*
- �����ʹ� int�� string�� ��¦ �� ��¦�̾����.
- map�� �ϳ��� ����ϸ� string����  int�� ���� �������� �� �ݴ�� ����.
    - �׷��ٸ� map�� �ΰ� ����ϸ�?
    - �ΰ� ����ϴ°ͺ��� �ϳ��� map�� insert�Ҷ� [�̸�,��ȣ], [��ȣ,�̸�] �Ѵ� �ϸ� �ǳ�?
        - ������ �־��� ��� 100���� �Է��� �־����ٵ� �׷� 200������ insert������ �ؾ��ϴٴ�
- int�� ���� string�� �������� ���� string �迭�� �������!
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