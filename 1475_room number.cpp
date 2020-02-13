#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	int n, tmp;
	vector<float > container(9, 0);
	cin >> n;
	if (n == 0) { cout << 1 << endl; return 0; }
	while (n != 0) {
		tmp = n % 10;
		if (tmp == 9 || tmp == 6) {
			container[6] += 0.5;
		}
		else {
			container[tmp] += 1;
		}
		n /= 10;
	}

	tmp = -1;
	for (int i = 0; i < container.size(); i++) {
		if (tmp < container[i]) { tmp = ceil(container[i]); }
	}
	cout << tmp;
	return 0;
}
