//https://www.acmicpc.net/problem/18111
#include<iostream>
#include<vector>

using namespace std;

int n=0, m=0, b=0; //����,����, �κ��丮

int countTime(vector<vector<int>> &arr, int height){
    int push =0 , pop=0;
     for(int i =0; i < n ; i++){
        for(int j =0; j <m ; j++){
            if ( arr[i][j] >height){
                pop+= arr[i][j]-height;
            }else if(arr[i][j] < height){
                push+= height -arr[i][j];
            }
        }
    }
    if( push <= b+pop){
        return pop*2 + push;
    }
    return -1;
}

//output: �ɸ��� �ð��� ���� ���̸� ���, ���� �ð��� �ִٸ� ���̰� ����������.
int main(){
    scanf("%d %d %d", &n ,&m, &b);
    vector<vector<int>> blocks(n, vector<int>(m));

    int num, max= 0, min= 256;
    for(int i =0; i < n ; i++){33333333333 
            blocks[i][j] =num;
            max = max >= num ? max : num;
            min = min <= num ? min : num;
        }
    }
    //�������̺��� �ְ� ���̱���, �ð��� �þ�� break; 
    //=> min���� max�� ���±濣 min�� ������ �ƴ��̻� ��� �پ��ų� ����پ��ٰ� �����Ǵ� �����ۿ� ����.
    int min_time= countTime(blocks, min),temp_time, height= min;
    for(int i = min+1 ; i<= max ; i++){
        temp_time = countTime(blocks, i);
        if(temp_time ==-1) continue;

        if( min_time> temp_time ){
            min_time = temp_time;
            height = i;
        }else if( min_time == temp_time){
            height = i;
        }else if( min_time < temp_time){
            break;
        }
    }

    printf("%d %d", min_time, height);
}

/*test case 

3 4 99             
0 0 0 0
0 0 0 0
0 0 0 1
// 2 0

3 4 1               
64 64 64 64
64 64 64 64
64 64 64 63
//1 64

3 4 0               
64 64 64 64
64 64 64 64
64 64 64 63 
//22 63


1 2 2
4 0
// 6 2

*/