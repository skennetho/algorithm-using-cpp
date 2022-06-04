#include <iostream>
using namespace std;


int n;
int pick[128][128];
int cnt[2];

void check(int n, int fromi, int fromj) {
	int base = pick[fromi][fromj];
	if (n == 1) {
		++cnt[base];
		return;
	}

	for (int i = fromi; i < fromi + n; i++) {
		for (int j = fromj; j < fromj + n; j++) {
			if (base != pick[i][j]) {
				base = -1; 
				break;
			}
		}
	}

	if (base == -1) {
		int nextN = n / 2;
		check(nextN, fromi, fromj);
		check(nextN, fromi + nextN, fromj);
		check(nextN, fromi, fromj + nextN);
		check(nextN, fromi + nextN, fromj + nextN);
		return;
	}
	else {
		++cnt[base];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &pick[i][j]);
		}
	}


	check(n, 0, 0);

	cout << cnt[0] << " " << cnt[1] << endl;
}