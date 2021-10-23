// 문제
// 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

// 입력
// 첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

// 출력
// 주어진 수들 중 소수의 개수를 출력한다.
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