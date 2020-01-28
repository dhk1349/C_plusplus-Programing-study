#include <iostream>
#include <string>
using namespace std;

void VPS(string input) {
	int check = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') { check++; }
		else { check--; }
		if (check < 0) { cout << "NO" << endl; return; }
	}
	if (check > 0) { cout << "NO" << endl; return; }
	cout << "YES" << endl; return;
}

int main() {
	int n;
	cin >> n;
	string in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		VPS(in);
	}
	return 0;
}