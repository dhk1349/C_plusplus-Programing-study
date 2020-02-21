#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	node(char input) {
		left = '.';
		right = '.';
		body = input;
	}
	~node() {}
	int SetLeft(char prev) { left = prev; return 0; }
	int SetRight(char prev) { right = prev; return 0; }
	char GetLeft() { return left; }
	char GetRight() { return right; }
	char GetBody() { return body; }
private:
	char left;
	char right;
	char body;
};
//A=65
class Tree {
public:
	Tree() {}
	~Tree() {}
	int pushItem(node input) {
		container.push_back(input);
		return 0;
	}
	node GetNode(char a) {
		for (int i = 0; i < container.size(); i++) {
			if (container[i].GetBody() == a) {
				return container[i];
			}
		}
	}
	int GetLen() {
		return container.size();
	}
	void PostOrder(node input) {
		if (input.GetLeft() != '.') {
			PostOrder(GetNode(input.GetLeft()));
		}
		if (input.GetRight() != '.') {
			PostOrder(GetNode(input.GetRight()));
		}
		cout << input.GetBody();
	}
	void PreOrder(node input) {
		cout << input.GetBody();
		if (input.GetLeft() != '.') {
			PreOrder(GetNode(input.GetLeft()));
		}
		if (input.GetRight() != '.') {
			PreOrder(GetNode(input.GetRight()));
		}
	}
	void InOrder(node input) {
		if (input.GetLeft() != '.') {
			InOrder(GetNode(input.GetLeft()));
		}
		cout << input.GetBody();
		if (input.GetRight() != '.') {
			InOrder(GetNode(input.GetRight()));
		}
	}
private:
	vector<node>container;
};
int main() {
	int in;
	char a, b, c;
	Tree printer;
	cin >> in;
	for (int i = 0; i < in; i++) {
		cin >> a >> b >> c;
		node temp(a);
		temp.SetLeft(b);
		temp.SetRight(c);
		printer.pushItem(temp);
	}
	printer.PreOrder(printer.GetNode('A'));
	cout << endl;
	printer.InOrder(printer.GetNode('A'));
	cout << endl;
	printer.PostOrder(printer.GetNode('A'));
	cout << endl;
	return 0;
}