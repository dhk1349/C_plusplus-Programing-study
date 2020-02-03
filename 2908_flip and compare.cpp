#include <iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

int flip(int input) {
	int result = 0;
	result += (input % 10) * 100;
	input /= 10;

	result += (input % 10) * 10;
	input /= 10;

	result += (input % 10);
	return result;
}

int main() {
	int a, b;
	cin >> a >> b;
	a = flip(a);
	b = flip(b);
	if (a > b) { cout << a << endl; }
	else { cout << b << endl;; }
	return 0;
}