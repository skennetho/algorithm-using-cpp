#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int number = 6;
int INF = 99;

bool v[6]; // 방문한 노드입니다. 
int d[6]; // 거리입니다. 

vector<pair<int, int> > vec[7];



/////////////////// using pair	O(N*logN)
void dijkstra_2(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;	//node, cost
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int cur_node = pq.top().first;
		int cur_node_dist = -pq.top().second;
		printf("pop :: %d, %d\n", cur_node, cur_node_dist);
		pq.pop();

		if (cur_node_dist > d[cur_node]) continue;

		for (int i = 0; i < vec[cur_node].size(); i++) {
			int next_node =  vec[cur_node][i].first;
			int next_node_distance = cur_node_dist + vec[cur_node][i].second;

			if (next_node_distance < d[next_node]) {
				d[next_node] = next_node_distance;
				pq.push({ next_node, -next_node_distance });
				printf("\tpush :: %d, %d\n", next_node, next_node_distance);
			}
		}
	}
}



void main_2() {
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}

	{
		vec[1].push_back(make_pair(2, 2));
		vec[1].push_back(make_pair(3, 5));
		vec[1].push_back(make_pair(4, 1));

		vec[2].push_back(make_pair(1, 2));
		vec[2].push_back(make_pair(3, 3));
		vec[2].push_back(make_pair(4, 2));

		vec[3].push_back(make_pair(1, 5));
		vec[3].push_back(make_pair(2, 3));
		vec[3].push_back(make_pair(4, 3));
		vec[3].push_back(make_pair(5, 1));
		vec[3].push_back(make_pair(6, 5));

		vec[4].push_back(make_pair(1, 1));
		vec[4].push_back(make_pair(2, 2));
		vec[4].push_back(make_pair(3, 3));
		vec[4].push_back(make_pair(5, 1));

		vec[5].push_back(make_pair(3, 1));
		vec[5].push_back(make_pair(4, 1));
		vec[5].push_back(make_pair(6, 2));

		vec[6].push_back(make_pair(3, 5));
		vec[6].push_back(make_pair(5, 2));
	}

	dijkstra_2(1);
	// 결과를 출력합니다. 
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}

/////////////////// using array O(N^2)
int arr[6][6] = {
	0,	2,	5,	1,	INF,INF,
	2,	0,	3,	2,	INF,INF,
	5,	3,	0,	3,	1,	5,
	1,	2,	3,	0,	1,	INF,
	INF,INF,1,	1,	0,	2,
	INF,INF,5,	INF,2,	0
};
int getMinAndNotVisitedIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}
void dijkstra(int start) {
	// init d[]
	for (int i = 0; i < number; i++) {
		d[i] = arr[start][i];
	}
	v[start] = true;
	cout << start << ":: ";
	for (const int& num : d) {
		printf("%2d", num);
	}
	cout << "<-" << endl<< "____";
	for (const bool& b : v) {
		cout << (b? " ^": "  " );
	}
	cout << "<-" << endl;

	// loop unvisited indexes of d[]
	int count = number -1;
	while (count-- > 0) {
		// visit unvisited min index
		int cur_node = getMinAndNotVisitedIndex();
		v[cur_node] = true;

		// compare between d[] and through min node
		cout << "    ";
		for (int i = 0; i < number; i++) {
			printf("%2d", arr[cur_node][i]);

			if (!v[i] && d[i] > d[cur_node] + arr[cur_node][i]) {
				d[i] = d[cur_node] + arr[cur_node][i];
			}
		}
		cout << endl;
		
		cout << cur_node << ":: ";
		for (const int& num : d) {
			printf("%2d", num);
		}
		cout << "<-" << endl << "____";
		for (const bool& b : v) {
			cout << (b ? " ^" : "  ");
		}
		cout << "<-" << endl << endl;
	}
}


int main() {
	main_2();
}
