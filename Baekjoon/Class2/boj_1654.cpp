//1654: 랜선자르기
#include<iostream>

using namespace std;

int main(){
    int k, n;

    scanf("%d %d", &k ,&n);
    int cables[k];

    int big = 0;
    for(int i = 0; i < k; i++){
        scanf("%d", &cables[i]);
        big=  big>= cables[i] ? big: cables[i] ;
    }
    
    unsigned int start = 1, end =big, mid, temp =1;
    while(start<=end){
        mid = (start + end )/2;     //여기가 int의 범위를 넘어설 수 있다...

        int count =0;
        for(int i =0 ; i < k; i++){
            count+= cables[i]/mid;
        }

        if(count >= n){
            temp = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    cout<< temp <<endl;
    

    

   
}


/*
11 46
2147483635
2147483595
2147483585
2147483641
2147483552
2147483637
2147483570
2147483563
2147483621
2147483618
2147483553

10  11
100
100
100
100
100
100
100
100
100
100

1 1
2147483647
*/