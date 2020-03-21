#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void DFS(vector<vector<int>>graph, vector<bool> &visited, int start){
	/*
	Input example:
	vector<vector<int>> graph = {
		{1,3},{0,2,4},{1,4},{1,2},{0}
	};
	vector<bool> visited(5, false);
	int start = 0;
	*/
	if (visited[start]) { return; }
	cout << "visit " << start+1 << endl;
	visited[start] = true;
	for (auto u : graph[start]) {
			cout << start+1 << ": "  <<u+1<< endl;
			DFS(graph, visited, u);
	}
}

void BFS(vector<vector<int>>graph, vector<bool>&visited, int start, queue<int>&q, vector<int>& dist){
	visited[start] = true;
	dist[start] = 0;
	q.push(start);
	while (!q.empty()){
		int n = q.front(); q.pop();
		for (auto u : graph[n]) {
			if (visited[u]) { continue; }
			q.push(u);
			cout<<"visited " << u+1 << endl;
			visited[u] = true;
			dist[u] = dist[n];
		}
	}
}

int main() {
	vector<vector<int>> graph = {
		{1,3},{0,2,4},{1,4},{0},{1,2},
	};
	vector<bool> visited(5, false);
	vector<int> dist(5, 0);
	queue<int>q;
	int start = 0;
	BFS(graph, visited, start, q, dist);
	//DFS(graph, visited, start);
	return 0;
}

/*
#include<iostream>
#include<vector>
using namespace std;

void boxchecker(vector<int>& box, int num, int threshold) {
	int tmp = num;
	while (true) {
		tmp += num;
		if (tmp > threshold) { break; }
		box[tmp] = -1;
	}
}

int main() {
	int from, to;
	cin >> from >> to;
	vector<int> box(10001, 0);
	box[1] = -1;
	for (int i = from; i <= to; i++) {
		if (box[i] == -1) { continue; }
		for (int j = 2; j * j <= i; j++) {//check if each number is prime number.
			if (i % j == 0) {
				box[i] = -1;
				break;
			}
		}
		if (box[i] == 0) {
			boxchecker(box, i, to);
		}

	}
	int sum = 0;
	int min = -1;
	for (int i = to; i >= from; i--) {
		if (box[i] == 0) { sum += i; min = i; }
	}
	if (min != -1) {
		cout << sum << "\n";
	}
	cout << min << "\n";
	return 0;
}
*/