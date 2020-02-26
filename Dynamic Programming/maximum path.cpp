#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>> MaximumPath(vector<vector<int>> map) {
	vector<vector<int>> sum = map;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (i == 0 && j == 0) { sum[i][j] = map[i][j]; }
			else if (i == 0) {
				sum[i][j] = sum[i][j - 1] + map[i][j];
			}
			else if (j == 0) { sum[i][j] = sum[i - 1][j] + map[i][j]; }
			else { sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + map[i][j]; }
		}
	}
	return sum;
}

int main() {
	//Dynamic Programming
	//Maximum path
	vector<vector<int>> map;
	vector<int> row1 = { 3, 7, 9, 2, 7 };
	vector<int> row2 = { 9, 8, 3, 5, 5 };
	vector<int> row3 = { 1, 7, 9, 8, 5 };
	vector<int> row4 = { 3, 8, 6, 4, 10 };
	vector<int> row5 = { 6, 3, 9, 7, 8 };
	map.push_back(row1);
	map.push_back(row2);
	map.push_back(row3);
	map.push_back(row4);
	map.push_back(row5);
	vector<vector<int>> sum;
	sum = MaximumPath(map);

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			cout << sum[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
