//https://www.acmicpc.net/problem/1966
#include<iostream>
#include<queue>

using namespace std;

int main(){
    int test_case ;
    scanf("%d", &test_case);
    priority_queue<int> priority;
    queue<pair<int,int>> doclist; 
    
    while(test_case-- > 0){
        priority =  priority_queue<int>();
        doclist = queue<pair<int,int>>();

        int n, m, num, cnt =0;
        scanf("%d %d", &n, &m);
        for(int i =0 ; i< n; i++){
            scanf("%d", &num);
            priority.push(num);
            doclist.push({num, i});
        }

        while(!doclist.empty()){
            int val = doclist.front().first;
            int idx = doclist.front().second;
            if( val< priority .top()){
                doclist.push({val,idx});
                doclist.pop();
            }else{
                doclist.pop();
                priority.pop();
                cnt++;
                if(idx ==m){
                    cout<< cnt <<'\n';
                    break;
                }
            }
        }
    }
}
