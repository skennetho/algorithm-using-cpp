#include<iostream>
using namespace std;


int main(){
    int a,b;        //both under 10,000
    cin>> a>> b;

    int lcm; //least common multiple
    int gcf=1; //greatest common factor
    int _a=a, _b =b, mul=2;

    while(true ){
        //check if dividable35
        if(_a % mul== 0 && _b % mul== 0  ){
            _a = _a/mul;
            _b = _b/mul;
            gcf*=mul;
        }else{            
            if(mul <= (_a<_b? _a:_b)){  
                ++mul;
            }else{
                cout<< gcf << '\n';
                lcm = gcf * _a*_b;
                cout<< lcm << '\n';
                break;
            }
        }
    }
}