#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//2667
int adj_block_handler(vector<vector<int>>* map, int x, int y, int* cnt, int blocknum = 0) {
	//returns number of block
	map->at(x)[y] = *cnt;
	blocknum++;
	if (x - 1 >= 0) {
		//left
		if (map->at(x - 1)[y] == 1) {
			blocknum = adj_block_handler(map, x - 1, y, cnt, blocknum);
		}
	}
	if (x + 1 < map->size()) {
		if (map->at(x + 1)[y] == 1) {
			blocknum = adj_block_handler(map, x + 1, y, cnt, blocknum);
		}
	}
	if (y - 1 >= 0) {
		if (map->at(x)[y - 1] == 1) {
			blocknum = adj_block_handler(map, x, y - 1, cnt, blocknum);
		}
	}
	if (y + 1 < map->size()) {
		if (map->at(x)[y + 1] == 1) {
			blocknum = adj_block_handler(map, x, y + 1, cnt, blocknum);
		}
	}
	return blocknum;
}

int main() {
	int n, blocknum, cnt = 2;
	string rowinput;
	cin >> n;
	vector<vector<int>> container;
	vector<int> history;
	for (int i = 0; i < n; i++) {
		vector<int> row;
		cin >> rowinput;
		for (int j = 0; j < rowinput.length(); j++) {
			if (rowinput[j] == '0') { row.push_back(0); }
			else if (rowinput[j] == '1') { row.push_back(1); }
		}
		container.push_back(row);
		row.clear();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (container[i][j] == 1) {
				blocknum = adj_block_handler(&container, i, j, &cnt);
				history.push_back(blocknum);
				cnt++;
			}
		}
	}
	sort(history.begin(), history.end());
	cout << history.size() << endl;
	for (int i = 0; i < history.size(); i++) {
		cout << history[i] << endl;
	}
	return 0;
}