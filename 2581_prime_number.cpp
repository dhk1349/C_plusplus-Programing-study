#include<iostream>
#include<vector>
using namespace std;

void boxchecker(vector<int>& box, int num, int threshold) {
	int tmp = num;
	while (true) {
		tmp += num;
		if (tmp > threshold) { break; }
		box[tmp] = -1;
	}
}

int main() {
	int from, to;
	cin >> from >> to;
	vector<int> box(10001, 0);
	box[1] = -1;
	for (int i = from; i <= to; i++) {
		if (box[i] == -1) { continue; }
		for (int j = 2; j * j <= i; j++) {//check if each number is prime number.
			if (i % j == 0) {
				box[i] = -1;
				break;
			}
		}
		if (box[i] == 0) {
			boxchecker(box, i, to);
		}

	}
	int sum = 0;
	int min = -1;
	for (int i = to; i >= from; i--) {
		if (box[i] == 0) { sum += i; min = i; }
	}
	if (min != -1) {
		cout << sum << "\n";
	}
	cout << min << "\n";
	return 0;
}