#include<iostream>
using namespace std;

int main() {
	int a, b, tmp;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> tmp;
		if (tmp < b) {
			cout << tmp << " ";
		}

	}
	return 0;
}
