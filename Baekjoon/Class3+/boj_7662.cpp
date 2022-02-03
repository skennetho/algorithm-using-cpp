//https://www.acmicpc.net/problem/7662
// 이중 우선순위 큐
#include <iostream>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while (t-- > 0) {
        multiset<int> mSet;
        int n, number;
        char select;
        scanf("%d", &n);

        while (n-- > 0) {
            scanf(" %c %d", &select, &number);
            if(select == 'I') {
                mSet.insert(number);
            } else {
                if(mSet.empty()) {
                    continue;
                }
                if (number == 1) {
                    multiset<int>::iterator iter = mSet.end();
                    iter--;
                    mSet.erase(iter);
                } else if (number == -1) {
                    mSet.erase(mSet.begin());
                }
            }
        }

        if (mSet.empty()) {
            printf("EMPTY\n");
            continue;
        }
        multiset<int>::iterator iter = mSet.end();
        iter--;
        printf("%d %d\n", *iter, *mSet.begin());

    }
}
//multiset사용

//// 이중우선순위큐 사용

// priority_queue<long long, vector<long long>, less<long long>> maxHeap;
// priority_queue<long long, vector<long long>, greater<long long>> minHeap;
// unordered_map<long long, long long> memory;

// const char SEL_D = 'D';
// const char SEL_I = 'I';

// void clearQue() {
//     maxHeap = priority_queue<long long, vector<long long>, less<long long>>();
//     minHeap = priority_queue<long long, vector<long long>, greater<long long>>();
//     memory.clear();

// }

// void push(long long num) {
//     maxHeap.emplace(num);
//     minHeap.emplace(num);
//     memory[num]++;
// }

// void popMin() {
//     while (!minHeap.empty() && memory[minHeap.top()] == 0) {
//         minHeap.pop();
//     }
//     if(!minHeap.empty()) {
//         memory[minHeap.top()]--;
//         minHeap.pop();
//     }
// }

// void popMax() {
//     while (!maxHeap.empty() && memory[maxHeap.top()] == 0 ) {
//         maxHeap.pop();
//     }
//     if(!maxHeap.empty()) {
//         memory[maxHeap.top()]--;
//         maxHeap.pop();
//     }
// }

// void printTop() {
//     while (!minHeap.empty() && memory[minHeap.top()] == 0) {
//         minHeap.pop();
//     }
//     while (!maxHeap.empty() && memory[maxHeap.top()] == 0 ) {
//         maxHeap.pop();
//     }
    
//     if (minHeap.empty()) {
//         printf("EMPTY\n");
//         return;
//     } 
//     printf("%d %d\n", maxHeap.top(), minHeap.top());
// }

// void run() {
//     int n, number;
//     char select;
//     scanf("%d", &n);
    
//     clearQue();
//     while (n-- > 0) {
//         cin >> select >> number;
//         if (select == SEL_I) {
//             push(number);
//         } else {
//             if (number == 1){
//                 popMax();
//             } else if (number == -1) {
//                 popMin();
//             }
//         }
//     }

//     printTop();
// }

// int main() {
//     int testCase;
//     scanf("%d", &testCase);

//     while (testCase-- > 0) {
//         run();
//     }
// }


