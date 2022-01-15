//https://www.acmicpc.net/problem/18870
// 좌표 압축
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> coordinates(n);
    int result[n];

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        coordinates[i] = make_pair(num,i);
    }

    sort(coordinates.begin(), coordinates.end());

    int count = -1;
    int prev = INT32_MIN;
    for (pair<int, int>& pair : coordinates) {
        if (prev != pair.first) {
            count++;
        }
        prev = pair.first;
        result[pair.second] = count;
        
    }

    for(const int& num : result) {
        printf("%d ", num);
    }
}

//// 이전 내 코드
// int _main() {
//     int n;
//     scanf("%d", &n);
//     int input_order_arr[n];
//     set<int> input_set;

//     for (int i = 0; i < n; i++) {
//         scanf("%d", &input_order_arr[i]);
//         input_set.insert(input_order_arr[i]);
//     }
    
//     map<int, int> result_map;
//     int count = 0;
//     for (int num : input_set) {
//         result_map.insert({num, count++});
//     }

//     for (int i = 0; i < n; i++) {
//         printf("%d ", result_map.find(input_order_arr[i])->second);
//     }
// }