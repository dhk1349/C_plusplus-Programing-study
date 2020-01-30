#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, money, tmp, cnt = 0;
	vector<int> container;
	cin >> n >> money;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		container.push_back(tmp);
	}
	for (int i = container.size() - 1; i >= 0; i--) {
		if (money >= container[i]) {
			tmp = money / container[i];
			cnt += tmp;
			money -= tmp * container[i];
		}
	}
	cout << cnt << endl;
	return 0;
}