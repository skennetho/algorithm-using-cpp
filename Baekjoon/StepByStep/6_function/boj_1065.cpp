//https://www.acmicpc.net/problem/1065
// ÇÑ¼ö
#include <iostream>
#include <vector>
using namespace std;

vector<int> makeItArray(int number) {
    vector<int> numberList;
    while(number != 0) {
        numberList.emplace_back(number % 10);
        number /= 10;
    }
    return numberList;
}

bool IsEqualOrder(const int& number) {
    vector<int> numberList = makeItArray(number);
    if (numberList.size() == 1 && numberList.size() == 2) {
        return true;
    }

    int diff = numberList[0] - numberList[1];
    for (int i = 2; i< numberList.size(); i++) {
        if (diff != numberList[i - 1] - numberList[i]) {
            return false;
        }
    }

    return true;
}   

int main() {
    int n; 
    scanf("%d", &n);

    int count = 0;
    for (int i = 1; i <= n ; i++) {
        if (IsEqualOrder(i)) {
            count++;
        }
    }
    printf("%d\n", count);
}