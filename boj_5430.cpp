//https://www.acmicpc.net/problem/5430
// 5430 AC
#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

deque<int> StringToDeque(const string input) {
	deque<int> arr;
	int temp = 0;
	for (const char& ch : input) {
		if (ch == '[') {
			continue;
		}
		else if (isdigit(ch)) {
			temp *= 10;
			temp += (ch - '0');
		}
		else if (temp != 0) {
			arr.push_back(temp);
			temp = 0;
		}
	}
	return arr;
}

string DequeToString(deque<int> deq) {

	return "";
}

void flip(bool& b) {
	if (b) {
		b = false;
	}
	else {
		b = true;
	}
}

void solve() {
	string commands;
	cin >> commands;

	int size;
	cin >> size;

	string array;
	cin >> array;
	deque<int> deq = StringToDeque(array);

	bool isReversed = false;

	for (const char& command : commands) {
		if (command == 'R') {
			flip(isReversed);
			continue;
		}
		else if (command == 'D') {
			if (deq.empty()) {
				cout << "error" << endl;
				return;
			}
			if (!isReversed) {
				deq.pop_front();
			}
			else {
				deq.pop_back();
			}
		}
		else {
			throw "wrong command";
		}
	}

	int from = 0, until = deq.size(), inc = 1;
	if (isReversed) {
		from = until - 1;
		until = -1;
		inc = -1;
	}

	cout << '[';
	if (from != until) {
		cout << deq[from];

		for (from += inc; from != until; from += inc) {
			cout << ',' << deq[from];
		}
	}
	cout << "] \n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t-- > 0) {
		solve();
	}
}