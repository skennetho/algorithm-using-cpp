//https://www.acmicpc.net/problem/1676
#include<iostream>
#include<string>

using namespace std;
/*
먼저 곱셈의 특징을 알아보자
팩토리얼을 수행할때 1의자리 수가 변한다 0~9사이.
그리고 0에는 무엇을 곱해도 0이다.
그럼만약 1의자리가 0이된다면? 그다음엔 뭘 곱해도 그자리는 0이 있을 확률이 높다.

그러므로 0을 세는 기준은 뒷자리가 0이 될때마다이고 
그때마다 숫자를 조정하면된다. 가령 어치파 0이 있는 자리와 처음0이 아닌수가 나오는자리만 갖고 있어도 된다.

숫자가 기하급수적으로 늘어나는 문제는 언제나 팩토리얼곱후 0이 생성될때 영향을 주는 1~9가 처음나오는자리만 유지해주면된다.
즉 처음 1~9가 나온수를 제외하고는 전부 없애버려도됨
음~~ 시간이 엄청걸리는 문제였다~ 그래서 이렇게 팩토리얼의 결과를 구해서 답을 알아내려는 방식은 부적합.
때문에 0이 생기는 조건을 알아내는게 좋다. 
0이 생길려면 10을 곱하거나 2*5곱하기가 존재해야한다.
*/

int main(){
    int n ;
    scanf("%d", &n);
    long long factorial =n;

    int zeroes =0;

    while(--n >0 ){
        factorial *= n;
        while( factorial %10 == 0){
            zeroes++;
            factorial/=10;
        }
        factorial %= 10;
    }

    printf("%d\n", zeroes);
}