//https://www.acmicpc.net/step/5
// 정수 N개의 합
#include <vector>

long long sum(std::vector<int> &a) {
    long long total = 0;
    for (int& num : a) {
        total += num;
    }
    return total;
}

long long sum2(std::vector<int> &a) {
	long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += a[i];
    }
	return ans;
}

//sum, sum2의 절반 속도. 빠르다.
long long sum3(std::vector<int> &a) {
	long long ans = 0;
    for (const int n: a) {
        ans += n;
    }
	return ans;
}