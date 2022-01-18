//https://www.acmicpc.net/problem/1697
// ���ٲ���
#include <iostream>

using namespace std;

void dfs(int now, const int target, int count, int& best) {
    if(now == target) {
        if (best > count) {
            best = count;
        } 
        return;
    } 
    if (target < now) {
        count += now - target;
        if (best > count) {
            best = count;
        } 
        return;
    }
    if ((now * 2) - target > target - now) {
        return;
    }
    if (count > best) {               
        return;
    }
    count++;
    dfs(now * 2, target, count, best);
    dfs(now - 1, target, count, best);
    dfs(now + 1, target, count, best);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int best = k - n; //worst case;
    dfs(n, k, 0, best);

    printf("%d", best);
}

/*
���:
x2
+1
-1
��3���� �����Ͽ� Ư�������� �����Ѵ�.

1�� ��� : dfs������ Ȱ���Ѵ�.
1. 3���� ����� ���� Ȱ���Ѵ�. (x2, +1, -1)
2. ���� �����*2-��ǥ���� ��ǥ��-��������� �Ѵ´ٸ� �ش� ��θ� ����Ѵ�. 
    ex) n=5, k=7, => if ([n*2-k = 10-7] > [k-n = 7-5] 
3. ��� - ���� ������� ��ǥ���� ���̰� ��������� �۴ٸ� +1�ƴϸ� -1�� �Ѵ�. or counter �� ���̸�ŭ �ø���.


*/