#include<iostream>

using namespace std;

int abs(int num){
    if(num<0){
        num *=-1;
    }
    return num;
}

int main(){
    int x, y, w, h;
    cin>> x>> y>> w>> h;

    int x_short = abs(w-x)>x? x: abs(w-x);
    int y_short = abs(h-y)>y? y: abs(h-y);

    if(x_short>y_short)
        cout<< y_short<<'\n';
    else
        cout<< x_short<<'\n';

    return 0;
}
