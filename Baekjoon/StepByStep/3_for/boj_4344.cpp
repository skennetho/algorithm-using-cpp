//https://www.acmicpc.net/problem/4344
// 평균은 넘겠지
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testCase;
    scanf("%d", &testCase);

    while (testCase-- > 0) {
        int n;
        scanf("%d", &n);
        double scores[n];
        double average = 0.0;
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%f", &scores[i]);
            scores[i] = (double)num;
            average += scores[i];
        }

        average /= (double)n;
        sort(scores, scores + n);
        int countUnderAverage = lower_bound(scores, scores + n, average + 0.001) - scores;
        printf("%.3f%\n", ((n - (double)countUnderAverage) / n) * 100.0);
    }
}