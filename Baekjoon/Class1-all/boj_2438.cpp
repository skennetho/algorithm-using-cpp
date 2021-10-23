#include <iostream>

int main(){
    int n ;
    scanf("%d", &n);
    for(int i =0 ; i< n;i++){
        for(int x =0 ; x<= i; x++){
            printf("*");
        }
        printf("\n");
    }
}