//1874: ���� ����
#include<iostream>
#include<queue>
#include<stack>
#include<vector>

using namespace std;
/*
1~n�� ���� �� ť arr�� �غ��Ѵ�. (pop�ϸ� ���)
�׸��� ��ǥ������ target�� ��´�.

target�� �����Ѵ�. x++
    x��° target�� ���� n�̴�.

    ���� ���ùٷ� ������ n�� �ƴϰ� 
         arr�ȿ� n�� ���ٸ� �Ұ���
        �ִٸ� n��ġ���� arr�� �ռ����� ���ʷ� ���ÿ� Ǫ���Ѵ�.
    ������ �ٷ����� n�̶�� �о� 
*/

int main(){
   
    int x =0;
    stack<int> stk;
    queue<int> que;
    int n;
    scanf("%d",&n);

    int target[n];
    vector<bool> answer;    //T: push , F:pop
    for(int i = 0 ; i < n ; i++){
        que.push(i+1);
        scanf("%d", &target[i]);
    }


    while(x!=n){
        int num = target[x];
        
        while(!que.empty() && que.front()<=num){
            answer.push_back(true);
            stk.push(que.front());
            que.pop();
        }
        
        if(!stk.empty()&&stk.top() == num){
            answer.push_back(false);
            stk.pop();
        }else{
            break;
        }
        x++;
    }
    

    if( x == n){
        for(bool b : answer){
            cout<< (b? "+\n" : "-\n" );
        }
    }else{
        cout<< "NO\n";
    }

}