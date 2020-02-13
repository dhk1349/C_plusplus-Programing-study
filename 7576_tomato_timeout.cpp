#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//7576
//timeout
void printfarm(vector<vector<int>>* farm) {

	for (int i = 0; i < farm->size(); i++) {
		for (int j = 0; j < farm->at(0).size(); j++) {
			cout << farm->at(i)[j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int farming(vector<vector<int>>* farm) {
	int iter = 0;
	bool check, breakcheck = true;
	while (true) {
		check = false;
		breakcheck = true;

		//check if farm is done
		for (int i = 0; i < farm->size(); i++) {
			for (int j = 0; j < farm->at(0).size(); j++) {
				if (farm->at(i)[j] == 0) { breakcheck = false; }
				if (farm->at(i)[j] == 2) { farm->at(i)[j] = 1; }
			}
		}
		if (breakcheck == true) { break; }
		iter++;


		//iterate through farm
		for (int i = 0; i < farm->size(); i++) {
			for (int j = 0; j < farm->at(0).size(); j++) {
				//if there is ripe tomato
				if (farm->at(i)[j] == 1) {
					//upper block
					if (i - 1 >= 0) {//check if block if legitimate
						if (farm->at(i - 1)[j] == 0) {
							check = true;
							farm->at(i - 1)[j] = 2;
						}
					}
					//block bellow
					if (i + 1 < farm->size()) {//check if block if legitimate
						if (farm->at(i + 1)[j] == 0) {
							check = true;
							farm->at(i + 1)[j] = 2;
						}
					}
					//left block
					if (j - 1 >= 0) {//check if block if legitimate
						if (farm->at(i)[j - 1] == 0) {
							check = true;
							farm->at(i)[j - 1] = 2;
						}
					}
					//right block
					if (j + 1 < farm->at(0).size()) {//check if block if legitimate
						if (farm->at(i)[j + 1] == 0) {
							check = true;
							farm->at(i)[j + 1] = 2;
						}
					}
				}
			}
		}
		if (check == false) {
			return -1;
		}

		//printfarm(farm);
	}
	return iter;
}


int main(void) {
	int x, y, tmp;
	cin >> x >> y;
	vector<vector<int>>farm;
	vector<int> row;
	for (int j = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			cin >> tmp;
			row.push_back(tmp);
		}
		farm.push_back(row);
		row.clear();
	}
	cout << farming(&farm);
	return 0;
}
