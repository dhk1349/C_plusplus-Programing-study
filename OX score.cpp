#include <iostream>
#include<vector>
#include<string>
using namespace std;

int score(string str) {
	int result = 0;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'O') { cnt++; }
		else { cnt = 0; }
		result += cnt;
	}
	return result;
}

int main() {

	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		cout << score(str) << endl;
	}

	//cout << score("OOXXOXXOOO") << endl;
	return 0;
}
