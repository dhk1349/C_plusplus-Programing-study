#include <iostream>
#include<vector>
#include <string>
using namespace std;

int main() {
	int n, tmp, max, min;
	cin >> n;
	cin >> max;
	min = max;
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		if (tmp > max) { max = tmp; }
		else { if (tmp < min) { min = tmp; } }
	}
	cout << min << " " << max << endl;
	return 0;
}