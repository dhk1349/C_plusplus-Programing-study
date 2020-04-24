#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	vector<vector<int>> storage;
	vector<int > row = { 1,2,3 };
	storage.push_back(row);
	int n, iter = 0;
	vector<int>::iterator it;
	cin >> n;
	if (n == 1 || n == 2 || n == 3) {
		cout << 1; return 0;
	}
	while (true) {
		row.clear();
		for (int i = 0; i < storage[iter].size(); i++) {
			it = find(storage[iter].begin(), storage[iter].end(), storage[iter][i] * 2);
			if (it == storage[iter].end()) {
				row.push_back(storage[iter][i] * 2);
			}

			it = find(storage[iter].begin(), storage[iter].end(), storage[iter][i] * 3);
			if (it == storage[iter].end()) {
				row.push_back(storage[iter][i] * 3);
			}

			it = find(storage[iter].begin(), storage[iter].end(), storage[iter][i] + 1);
			if (it == storage[iter].end()) {
				row.push_back(storage[iter][i] + 1);
			}
		}
		sort(row.begin(), row.end());
		row.erase(unique(row.begin(), row.end()), row.end());
		for (int i = 0; i < row.size(); i++) { cout << row[i] << " "; }
		cout << endl;
		it = find(row.begin(), row.end(), n);
		if (it != row.end()) {
			//found
			cout << iter + 2;
			break;
		}
		storage.push_back(row);
		iter++;
	}
	return 0;
}