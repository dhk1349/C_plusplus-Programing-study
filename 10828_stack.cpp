#include <iostream>
#include<stack>
#include <string>
using namespace std;

//10828
int stackcontrol(stack<int>* s, string command, int num) {
	int tmp;
	if (command == "push") { s->push(num); return 1; }
	else if (command == "pop") {
		if (s->size() > 0) { cout << s->top() << endl;  s->pop(); }
		else { cout << -1 << endl; }
	}
	else if (command == "top") { if (s->size() > 0) { cout << s->top() << endl; } else { cout << -1 << endl; } }
	else if (command == "empty") { cout << s->empty() << endl; }
	else if (command == "size") { cout << s->size() << endl; }
	return 1;
}

int main() {
	stack<int> container;
	int Cnum, num;
	string cmd;
	cin >> Cnum;
	for (int i = 0; i < Cnum; i++) {
		num = 0;
		cin >> cmd;
		if (cmd == "push") { cin >> num; }
		stackcontrol(&container, cmd, num);
	}

	return 0;
}
