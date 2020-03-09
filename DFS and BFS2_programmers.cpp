#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int DFS(vector<bool>& visited, int loc, vector<vector<int>> computers) {
	for (int i = 0; i < computers[loc].size(); i++) {
		if (visited[i] == true) { continue; }
		if (computers[loc][i] == 1) {
			visited[i] = true;
			DFS(visited, i, computers);
		}
	}
	return 0;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 1;
	vector<bool> visited(n, false);
	visited[0] = true;
	int loc = 0;
	bool exit = false;
	while (!exit) {
		DFS(visited, loc, computers);
		exit = true;
		for (int i = 0; i < visited.size(); i++) {
			if (visited[i] == false) {
				exit = false;
				visited[i] = true;
				loc = i;
				answer++;
				break;
			}
		}

	}

	return answer;
}

int main(void) {
	int n = 4;
	vector<vector<int>> computers = { {1, 0, 0, 1},{0, 1, 1, 1},{0, 1, 1, 0 }, { 1, 1, 0, 1 } };
	int n2 = 4;
	vector<vector<int>> computers2 = { {1, 0, 0, 0},{0, 1, 0, 0},{0, 0, 1, 0 }, { 0, 0, 0, 1 } };
	int n3 = 4;
	vector<vector<int>> computers3 = { {1, 1, 1, 1},{1, 1, 1, 1},{1, 1, 1, 1 }, { 1, 1, 1, 1 } };
	int n4 = 4;
	vector<vector<int>> computers4 = { {1, 0, 0, 0},{0, 1, 1, 1},{0, 1, 1, 1 }, { 0, 1, 1, 1 } };
	cout << solution(n4, computers4) << endl;
	return 0;
}
