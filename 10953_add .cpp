#include <iostream>
#include <string>
using namespace std;

//10953
int main() {
	int n, a, b;
	string input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cout<<atoi(input.substr(0, input.find(',')).c_str())+ atoi(input.substr(input.find(',') + 1, input.size() - input.find(',') + 1).c_str())<<endl;
	}
	return 0;
}
