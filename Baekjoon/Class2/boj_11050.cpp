//11050 ���װ��
#include<iostream>

using namespace std;

int main(){
    int N , K ;
    cin >> N >> K;
    K = N-K <K? N-K: K;
    int nn= N-1 , kk = K-1;

    for( ; kk>0;){
        N*= nn--;
        K*= kk--;
    }
    if(K==0)
        cout<< 1<< '\n';
    else{
        cout<< N/K << '\n';
    }
}