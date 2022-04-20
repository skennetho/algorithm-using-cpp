#include <iostream>

using namespace std;

void main() {
	int dice[7] = { 0 };

	for (int i = 0; i < 3; i++) {
		int d;
		cin >> d;
		dice[d]++;
	}

	int max = 1;
	for (int i = 2; i < 7; i++) {
		if (dice[max] <= dice[i]) {
			max = i;
		}
	}

	if (dice[max] == 3) {
		cout << 10000 + max * 1000 << endl;
	}
	else if (dice[max] == 2) {
		cout << 1000 + max * 100 << endl;
	}
	else {
		cout << max * 100 << endl;
	}

	return;
}