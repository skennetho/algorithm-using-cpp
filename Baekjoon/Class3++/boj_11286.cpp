//https://www.acmicpc.net/problem/11286
// 11286 Àý´ñ°ª Èü

#include <iostream>
#include <queue>

using namespace std;
int area[100000];
int end_index = 1; //insertable index

int absolute(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

struct compare {
	bool operator()(int a, int b) {
		if (absolute(a) == absolute(b)) {
			return a > b;
		}
		return absolute(a) > absolute(b);
	}
};

int main() {
	int n, x;
	scanf("%d", &n);

	priority_queue<int, vector<int>, compare> pq;

	while (n-- > 0) {
		scanf("%d", &x);
		if (x == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
			
			//printf("%d\n", heap_pop());
		}
		else {
			pq.push(x);
			//heap_push(x);
		}
	}
}



bool isABeforeB(int a, int b) {
	if (absolute(a) == absolute(b)) {
		return a < b;
	}
	return absolute(a) < absolute(b);
}

void heap_push(int x) {
	int index = end_index++;
	area[index] = x;

	while (index != 1 && isABeforeB(area[index], area[index / 2])) {
		swap(area[index], area[index / 2]);
		index /= 2;
	}
}

int heap_pop() {
	if (end_index == 1) {	//empty
		return 0;
	}
	int top = area[1];
	int parent = 1;
	int child = parent * 2;

	area[1] = area[--end_index];	//if end == 5, arr = [x, 1, 2, 3, 4, 0, 0, 0, ]
								//                                   ¤¤>end
	while (child < end_index) {
		// get the appropriate child
		if (child + 1 < end_index && !isABeforeB(area[child], area[child + 1])) {
			child++;
		}
		if (isABeforeB(area[child], area[parent])) {
			swap(area[child], area[parent]);
			parent = child;
			child = parent * 2;
		}
		else {
			break;
		}
	}
	return top;
}