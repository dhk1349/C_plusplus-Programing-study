#include <iostream>
#include <stack>
#include <set>
#include <vector>
using namespace std;

int DFS(vector<vector<int>>* container, vector<int>* record, set<int>* history, int point, int node, int* cnt) {
	//point: starting point
	if (!history->insert(point).second) {
		//cout << "skip " << point + 1 << endl;
		return *cnt;
	}
	record->push_back(point);
	for (int i = 0; i < node; i++) {
		if (i == point) { continue; }
		else if (container->at(point)[i] == 1) {
			bool check = false;
			for (int j = 0; j < record->size(); j++) {
				if (record->at(j) == i) { check = true; }
			}
			if (check == false) {
				//cout << point + 1 << " to " << i + 1 << endl;
				container->at(point)[i] = -1;
				container->at(i)[point] = -1;
				DFS(container, record, history, i, node, cnt);
			}
		}
	}
	if (record->empty()) {
		//cout << "EMPTY" << endl; 
		return *cnt;
	}
	else {
		//cout << "pop " << record->at(record->size() - 1)+1<<endl;
		record->pop_back();
		*cnt = *cnt + 1;
		return *cnt;
	}
}

int main() {
	int node, edge, x, y;
	cin >> node >> edge;
	vector<int> record;
	set<int> history;
	vector<vector<int>> container(node, vector<int>(node, 0));
	for (int i = 0; i < edge; i++) {
		cin >> x >> y;
		container[x - 1][y - 1] = 1;
		container[y - 1][x - 1] = 1;
	}
	//DFS
	int point = 0, cnt = 0;
	cout << DFS(&container, &record, &history, point, node, &cnt) - 1 << endl;
	return 0;
}