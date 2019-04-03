#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cmath>
using namespace std;

void main() {
	string formula;
	cin >> formula;
	int a = formula.length();
	string check;
	int left = 0;
	int right = 0;
	for (int i = 0; i <= (a - 1); i++){
		if (formula[i] == '(') {
			check += '(';
			left += 1;
		}
		else if (formula[i] == ')') {
			check += ')';
			right += 1;
		}
}
	int k = check.length();
	for (int j = 0; j <= k - 2; j++) {
		if ((check[j] == ')') && (check[j + 1] == '(')) {
			right -= 1;
			left -= 1;
		}
	}
	if (right == left) {
		cout << right<<endl;
	}
	else {
		cout << -1<<endl;
	}
}
