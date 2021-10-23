//https://www.acmicpc.net/problem/1929
#include<iostream> 
#include<cmath> 

using namespace std;
const int MAX = 1000001;

void myCode(int n, int m){
 for(int i =n ; i<= m; i++){
        if( i == 1) continue;
        else{
            bool flag = true;
            for(int j =2 ; j<= sqrt(i) ; j++){
                if( i% j == 0){
                    flag = false;
                    break;
                }
            }
            if(flag)printf("%d\n", i);
        }
    }
}


int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    bool not_primes[MAX] = { false};
    not_primes[0] =true;
    not_primes[1] =true;
     

    // 에라토스테네스의 채 
    for(int i = 2; i <MAX ; i++){
        if(not_primes[i] == false){
            for(int j = 2 ; i*j< MAX ; j++){
                not_primes[i * j] =true;
            }
        }
        // for(int j =2 ; j<MAX ; j++){
        //     if(i*j>=MAX) break;
        //     else if( not_primes[i] == false) {
        //         not_primes[i*j] == true;
        //     }else{
        //         continue;
        //     }
        // }
    }

    for(int i =n ; i <= m ; i++){
        if(!not_primes[i])printf("%d\n", i);
    }
}