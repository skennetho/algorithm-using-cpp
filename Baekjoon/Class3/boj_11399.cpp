//https://www.acmicpc.net/problem/11399
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int addWithinCount(vector<int> vec, int count) {
    int sum = 0;
    count = min(count, (int)vec.size());
    for(int i = 0; i < count; i++) {
        sum += vec[i];
    }
    return sum;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    int result = 0;
    for(int i = 1; i <= n; i++) {
        result += addWithinCount(vec, i);
    }
    cout << result;
}