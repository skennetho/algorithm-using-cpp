#include <iostream>

using namespace std;

int main(){
    string str ;
    cin>>str;

    int arr[26];
    fill_n(arr,26, -1 );
    char ch;
    for(int i =0 ; i < str.length(); i++){
        ch = str[i];
        if(arr[ch-'a'] != -1){
            continue;
        }else{
            arr[ch-'a'] =i;
        }
    }
    
    for(int &num : arr){
        cout << num<<" ";
    }
    cout<< endl;
}

#include<stdio.h>
char c,a[101];
int i=0,b[26]={};
int main(){
    scanf("%s",a);
    while(c=a[i]){
        i++;
        if(!b[c-97])b[c-97]=i;
    }
    for(i=0;i<26;i++)
        printf("%d ",b[i]-1);
}