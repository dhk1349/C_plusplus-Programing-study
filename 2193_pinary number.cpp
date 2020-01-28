#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1 || n == 2) { cout << 1 << endl; }
	else if (n > 2) {
		unsigned long int zero = 1, one = 1, tmp;
		for (int i = 0; i < n - 3; i++) {
			tmp = zero;
			zero = zero + one;
			one = tmp;
		}
		cout << zero + one << endl;
	}
	return 0;
}