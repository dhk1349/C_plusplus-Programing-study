#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long unsigned int  shell = 0, n = 1;
	long long int num;
	cin >> num;
	num -= n;
	n += 5;
	shell++;
	if (num == 0) {
		cout << shell << endl;
		return 0;
	}
	while (num > 0) {
		num -= n;
		n += 6;
		shell++;
	}
	cout << shell << endl;
	return 0;
}