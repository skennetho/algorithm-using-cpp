#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t ;
    scanf("%d", &t);
    vector<int> arr;
    for(int i = 0 ; i < t; i++){
        int h,w,n;
        scanf("%d %d %d", &h, &w, &n);
        int floor, roomNum;
        floor = (n%h == 0)? h: n%h;
        roomNum = ((n%h==0)? n/h: n/h+1) + floor*100;
        arr.push_back(roomNum);
    }

    for(int &roomNum : arr){
        cout<< roomNum<< '\n';
    }

}

// %3
// 1 2 0 1 2 0
// floor 
// 1 2 3 1 2 3 

// h =4
// room_num % 4
// 1 2 3 4 5 6 7 8
// 1 1 1 1 2 2 2 2

