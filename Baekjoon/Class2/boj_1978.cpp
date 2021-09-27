// ����
// �־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

// �Է�
// ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.

// ���
// �־��� ���� �� �Ҽ��� ������ ����Ѵ�.
#include<iostream>

using namespace std;

int main(){
    int prime[1001] = {0, };
    prime[0]=-1;
    prime[1]=-1;

    for(int num = 2; num< 1001 ; num++){
        if(prime[num]!= 0 ) continue;
        prime[num] = 1;
        for(int i = 2; i< num ; i++){
            if(num%i ==0 ){
                prime[num] =-1;
                break;
            }
        }
        if(prime[num]==1){
            for(int i =num*2; i*num < 1001 ; i +=num){
                prime[i] =-1;
            }
        }
    }

    // for(int i=0 ; i < 1001; i++){
    //     cout<< i<< " = " << (prime[i]>0? "Y": "_")<<'\n'; 
    // }
    int n;
    cin>> n;
    int input;
    int cnt=0;
    for(int i =0 ; i<n ;i++){
        cin>> input;
        cnt = prime[input]>0 ? cnt+1: cnt;
    }
    
    cout<< cnt<<'\n';
}