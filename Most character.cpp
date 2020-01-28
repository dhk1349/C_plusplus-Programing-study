#include <iostream>
#include<vector>
#include <string>
using namespace std;

int main() {
	string str;
	vector<int> box(26, 0);
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (65 <= str[i] && str[i] <= 90) {
			box[str[i] - 65] += 1;
		}
		else if (97 <= str[i] && str[i] <= 122) {
			box[str[i] - 97] += 1;
		}
	}
	int max1, max2;
	int maxnum1, maxnum2;
	max1 = 0;
	maxnum1 = box[0];
	maxnum2 = -1;
	for (int i = 1; i < box.size(); i++) {
		if (maxnum1 <= box[i]) { max2 = max1; maxnum2 = maxnum1; max1 = i; maxnum1 = box[i]; }
	}
	if (maxnum1 == maxnum2) {
		cout << "?";
	}
	else { cout << char(max1 + 65); }
	return 0;
}