#include<iostream>
using namespace std;

int main() {
	int num;
	long int a = 0, b = 1;
	cin >> num;
	if (num == 0) { cout << 0; }
	else if (num == 1) { cout << 1; }
	else {
		for (int i = 0; i < num - 1; i++) {
			if (a <= b) { a += b; }
			else { b += a; }
		}
		if (a >= b) { cout << a; }
		else { cout << b; }
	}
	return 0;
}
