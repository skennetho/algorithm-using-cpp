//https://www.acmicpc.net/problem/2805
#include<iostream>
#include<algorithm>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main(){
    // input
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[n+1] = {0};
    for(int i =0; i < n ; i++){
        scanf("%d", &arr[i]);
    }

    // 정렬
    sort(arr, arr+n, desc);

    // 나무별 차이를 구한다. diff의 i번째는 나무 i와 i+1간의 차이
    int diff[n];
    for(int i =0 ; i< n ; i++){
        diff[i] = arr[i] - arr[i+1];
    }

    // 가장 큰나무부터 작은나무순으로 수행한다.
    int height = arr[0];
    for(int i =0 ; i< n ; i++){
        // 이미 챙기만큼 챙겼으면 끝내기
        if( m<=0 ){         
            break;
        }
        //i나무와 i+1나무의 길이가 같다면
        if(diff[i] == 0){   
            continue;
        }
        //다음나무와 크기가 같지 않다면
        else{              
            // i+1은 현재위치에서 자르면 잘리는 나무의 개수
            // 이수를 이용하여 m개에 딱맞거나 조금넘어가는 정도로 자르려면 몇미터를 잘라야하는지 구한다.
            int cnt = m%(i+1)? (m/(i+1))+1: (m/(i+1));     
            cnt = cnt<= diff[i] ? cnt : diff[i];
            // 구하면 그 수만큼 자르기
            height -= cnt; 
            m -= cnt * (i+1);
        }
    }

    cout << height<< endl;
}