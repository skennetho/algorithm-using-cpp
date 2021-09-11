#include<iostream>

using namespace std;


void solution(int *arr){

}
int main(){
    int num;
    int big = 0 ;
    int location =0;

    for(int i =0 ; i< 9 ; i++){
        cin>> num; 
        if(num > big) {
            big = num;
            location= i+1;
        }
    }
    cout<<big << endl << location << endl;

    return 0;
}

/*test case
input :
3
29
38
12
57
74
40
85
61
output:
85 
3
*/