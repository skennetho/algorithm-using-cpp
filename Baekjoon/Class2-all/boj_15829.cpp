//15829: hashing
#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    char arr[n];
    scanf("%s", &arr);
    
    long long M = 1234567891;
    long long r_n = 1;

    long long H=0;
    for(int i =0 ; i< n ; i++){
        H +=((arr[i] - 'a' +1) * r_n)%M;
        r_n = (r_n * 31)%M;
    }

    cout<< H << endl;
}