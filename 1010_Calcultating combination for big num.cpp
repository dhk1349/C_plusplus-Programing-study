#include <iostream>
using namespace std;

unsigned long combination(int a, int b) {
	unsigned long A = 1, B = 1;
	for (int i = 1; i <= b; i++) {
		A *= a;
		a -= 1;
		if (A % i == 0) {
			A /= i;
		}
		else {
			B *= i;
		}
	}
	return A / B;
}

int main() {
	int a, b, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a < b) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		cout << combination(a, b) << endl;
	}
	return 0;
}