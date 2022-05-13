//https://www.acmicpc.net/problem/16236
#include <iostream>
#include <cstdlib>
#include <queue>
#include <utility>

using namespace std;

struct BabyShark {
	int i = 0;
	int j = 0;
	int size = 2;	//초기 크기
	int eaten = 0;
};

BabyShark baby;
int dir[4][2] = { {-1,0},{0,-1} ,{0,1}, {1,0} };
int area[20][20];
int fishCount[7];
int seconds = 0;

int n;

bool checkReachable(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n)
		return false;
	if (area[i][j] > baby.size)
		return false;
	else
		return true;
}

int findFish(int& iFish, int& jFish) {
	queue<pair<pair<int, int>, int>> bfsQ;
	int distance = 0;
	bool visited[20][20] = { false };

	bfsQ.push({ { baby.i, baby.j },distance });
	visited[baby.i][baby.j] = true;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fishQ;
	int nearestDist = INT32_MAX;

	while (!bfsQ.empty()) {
		pair<int, int> current = bfsQ.front().first;
		distance = bfsQ.front().second;
		bfsQ.pop();


		for (int i = 0; i < 4; ++i) {
			int nextI = current.first + dir[i][0];
			int nextJ = current.second + dir[i][1];

			if (checkReachable(nextI, nextJ) && !visited[nextI][nextJ]) {
				if (area[nextI][nextJ] > 0 && area[nextI][nextJ] < baby.size &&
					nearestDist >= distance + 1) {
					fishQ.push({ nextI, nextJ });
					nearestDist = distance + 1;
				}
				if (distance + 1 > nearestDist) {
					continue;
				}
				bfsQ.push({ {nextI,nextJ}, distance + 1 });
				visited[nextI][nextJ] = true;
			}
		}
	}

	if (fishQ.empty()) {	//no available fish
		return -1;
	}
	iFish = fishQ.top().first;
	jFish = fishQ.top().second;
	return nearestDist;
}

void eatFish(int iFish, int jFish, int distance) {
	int fishSize = area[iFish][jFish];
	seconds += distance;
	--fishCount[fishSize];

	++baby.eaten;
	if (baby.eaten >= baby.size && baby.size <= 7) {
		baby.size++;
		baby.eaten = 0;
	}

	baby.i = iFish;
	baby.j = jFish;
	area[iFish][jFish] = 0;
}


int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &area[i][j]);
			if (area[i][j] == 9) {
				baby.i = i;
				baby.j = j;
				area[i][j] = 0;
			}
			else {
				fishCount[area[i][j]]++;
			}
		}
	}

	while (true) {
		//if theres no fish to eat break
		int availableFish = 0;
		for (int i = 1; i < baby.size; ++i) {
			availableFish += fishCount[i];
		}
		if (availableFish == 0)
			break;

		//find nearest fish's location and distance
		int iFish, jFish;
		int distance = findFish(iFish, jFish);

		//eat fish
		if (distance > 0) {
			eatFish(iFish, jFish, distance);
		}
		if (distance <= 0) {
			break;
		}
	}

	cout << seconds << '\n';
	return 0;
}