#include <iostream>
#include <string>
#include <vector>
using namespace std;

int GroupWord(vector<int>* container, string input) {
	for (int i = 0; i < input.length(); i++) {
		if (container->at(input[i] - 97) == -1) { container->at(input[i] - 97) = i; }
		else {
			if (container->at(input[i] - 97) == i - 1) {
				container->at(input[i] - 97) = i;
			}
			else { return -1; }
		}
	}
	return 1;
}

int main() {
	//a: 97, z: 122
	vector<int> container(26, -1);
	int n, cnt = 0;
	string input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		vector<int> container(26, -1);
		if (GroupWord(&container, input) == 1) { cnt++; }
	}
	cout << cnt << endl;;
	return 0;
}