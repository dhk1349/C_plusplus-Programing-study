#include <iostream>
#include<queue>
#include <string>
using namespace std;

int QueueController(string cmd, int num, queue<int>* box) {
	if (cmd == "push") { box->push(num); }
	else if (cmd == "size") { cout << box->size() << endl; }
	else if (cmd == "pop") {
		if (box->size() == 0) {
			cout << -1 << endl;
		}
		else {
			cout << box->front() << endl;
			box->pop();
		}
	}
	else if (cmd == "empty") {
		cout << box->empty() << endl;
	}
	else if (cmd == "front") {
		if (box->size() == 0) {
			cout << -1 << endl;
		}
		else {
			cout << box->front() << endl;
		}
	}
	else if (cmd == "back") {
		if (box->size() == 0) {
			cout << -1 << endl;
		}
		else {
			cout << box->back() << endl;
		}
	}
	return 1;
}

int main() {
	queue<int> box;
	int n, num = 0;
	string cmd;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
		}
		QueueController(cmd, num, &box);
	}

	return 0;
}
