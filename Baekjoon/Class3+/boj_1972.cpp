//https://www.acmicpc.net/problem/1927
// ÃÖ¼Ò Èü
#include <queue>
#include <iostream>
using namespace std;

int minHeap[100001];
int heapSize = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeap_push(int number) {
    int current = ++heapSize; 
    minHeap[current] = number;

    while (true) {
        if (heapSize == 1) {
            break;
        }
        int parent = current / 2;
        if (minHeap[parent] < minHeap[current]) {
            break;
        } 
        swap(minHeap[parent], minHeap[current]);
        current = parent;
    }

    for (int i = 0; i<= heapSize; i++) {
        printf("%d ", minHeap[i]);
    }
    printf("\n");
}

void minHeap_pop() {
    if (heapSize == 0) {
        printf("0\n");
        return;
    }
    printf("%d\n", minHeap[1]);     
    minHeap[1] = minHeap[heapSize--];
    int current = 1;
    int child;

    while (true) {
        child = current * 2;
        if (child > heapSize) {
            break;
        }  
        if (child + 1 <= heapSize && minHeap[child] > minHeap[child +1]) {
            child +=1;
        }
        if (minHeap[current] < minHeap[child]) {
            break;
        }
        swap(minHeap[current], minHeap[child]);
        current = child;
    }
    for (int i = 0; i<= heapSize; i++) {
        printf("%d ", minHeap[i]);
    }
    printf("\n");
}

int main() { 
    int n, input;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> priorQ;

    while (n-- > 0) { 
        scanf("%d", &input);
        if (input == 0) {
            minHeap_pop();
        } else {
            minHeap_push(input);
        }

        // if (input == 0) {
        //     if (priorQ.empty()) {
        //         printf("0\n");
        //     } else {
        //         printf("%d\n", priorQ.top());
        //         priorQ.pop();
        //     }
        // } else {
        //     priorQ.push(input);
        // }
    }
}
