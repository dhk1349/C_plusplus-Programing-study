#include <iostream>
#include<vector>
#include <string>
using namespace std;

int main() {
	int fib, n;
	cin >> n;
	if (n == 0) { cout << 0 << endl; }
	else if (n == 1) { cout << 1 << endl; }
	else {
		int zero = 0; int one = 1;

		for (int i = 0; i < n - 1; i++) {
			fib = zero + one;
			zero = one;
			one = fib;
		}
		cout << fib << endl;
	}
	return 0;
}