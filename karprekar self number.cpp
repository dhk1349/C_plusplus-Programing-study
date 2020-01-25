#include <iostream>
#include<vector>
#include<string>
using namespace std;

int k(int number) {
	int result = number;
	while (number != 0) {
		result += (number % 10);
		number /= 10;
	}
	return result;
}

int main() {
	//cout << k(15);

	int cnt = 0;
	int tmp;
	vector<bool> a(10000, false);
	while (cnt < 9999) {
		cnt += 1;
		if (a[cnt - 1] == true) { continue; }
		tmp = k(cnt);
		//cout << tmp << endl;
		while (tmp < 9998) {
			if (a[tmp - 1] == true) { break; }
			a[tmp - 1] = true;
			tmp = k(tmp);
			//cout << tmp << endl
		}
	}


	for (int i = 0; i < 9993; i++) {
		if (a[i] == false) {
			cout << i + 1 << endl;
		}
	}

	return 0;
}
