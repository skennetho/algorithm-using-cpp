//https://www.acmicpc.net/problem/11723
#include<iostream>
#include<cstring>

using namespace std;

void old_code(int n){
    bool S[21];
    char str[10];
    int num;
    while(n-->0){
        scanf("%s", &str);

        switch(str[1]){
            case 'd':
                scanf("%d", &num);
                S[num]= true;
                break;
            case 'e':
                scanf("%d", &num);
                S[num]= false;
                break;
            case 'h':
                scanf("%d", &num);
                printf("%d\n", (S[num]? 1 : 0));
                break;
            case 'o':
                scanf("%d", &num);
                S[num] = !S[num];
                break;
            case 'l':
                for(int i=0; i< 21 ; i++)
                    S[i] = true;
                break;
            case 'm':
                for(int i=0; i< 21 ; i++)
                    S[i] = false;
                break;
            default:
                cout<< "error\n";
                break;
        }
    }

}

int main(){
    char str[10];
    int n, num;
    scanf("%d", &n);
    

    int set =0;
    while(n-->0){
        scanf("%s", &str);

        switch(str[1]){
            case 'd':
                scanf("%d", &num);
                set |= 1 << (num-1);    //1:1, 2:10, 3:100, 4:1000...
                break;
            case 'e':
                scanf("%d", &num);
                set &= ~(1 << (num-1)); //1:0, 2:01, 3:011, 4:0111...
                break;
            case 'h':
                scanf("%d", &num);
                printf("%d\n", (set & (1<< (num-1))) >> (num-1));
                break;
            case 'o':
                scanf("%d", &num);
                set ^= (1 << (num-1));
                break;
            case 'l':
                set = (1<<20) -1;
                break;
            case 'm':
                set = 0;
                break;
            default:
                cout<< "error\n";
                break;
        }
    }

}


//  cout << ('a' + 'd')<< endl;
//     cout << ('r' + 'e')<< endl;
//     cout << ('c' + 'h')<< endl;
//     cout << ('t' + 'o')<< endl;
//     cout << ('a' + 'l')<< endl;
//     cout << ('e' + 'm')<< endl;

// 197
// 215
// 203
// 227
// 205
// 210