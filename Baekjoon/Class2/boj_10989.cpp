#include<iostream>

using namespace std;

int main(){
    int n ; 
    cin >> n ;

    int arr[10001]= {0};

    for(int i =0 ;i< n ; i++){
        int num;
        cin >> num;
        ++arr[num];
    }

    for(int num =0 ; num < 10001 ; num++){
        for(int j = 0 ; j < arr[num]; j++){
            cout<< num << '\n';
        }
    }
}

// int main(){
//     int n ; 
//     cin >> n ;

//     vector<int> arr(n);
//     priority_queue<int> priorQue;
//     for(int i =0 ;i< n ; i++){
//         int num;
//         cin>> num;
//         priorQue.push(num);
//     }
    
//     while(!priorQue.empty()){
//         arr[--n] =priorQue.top();
//         priorQue.pop();
//     }

//     for(int &num : arr){
//         cout<< num<< '\n';
//     }
// }
/*


*/