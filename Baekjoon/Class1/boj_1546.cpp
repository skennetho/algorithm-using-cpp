#include <iostream>

using namespace std;

int main(){
    int n;
    cin>> n;
    double max= 0.0, number, sum =0;
    
    for( int i =0 ; i<n ; i++){
        cin>> number;
        max = max<number? number: max;
        sum+= number;
    }

    sum = sum/max*100.0;
    cout<< sum/(double)n<<endl;
   
}
