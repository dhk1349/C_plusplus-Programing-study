#include<iostream>
#include<iomanip>
using namespace std;

int converter(int a, int b) {
	int result = b;
	a--;
	while (a != 0) {
		if ((a == 1) | (a == 3) | (a == 5) | (a == 7) | (a == 8) | (a == 10) | (a == 12)) {
			result += 31;
		}
		else if ((a == 4) | (a == 6) | (a == 9) | (a == 11)) {
			result += 30;
		}
		else if (a == 2) {
			result += 28;
		}
		a--;
	}
	return result;
}
void day(int a) {
	if (a % 7 == 1) {
		cout << "MON";
	}
	else if (a % 7 == 2) { cout << "TUE"; }
	else if (a % 7 == 3) { cout << "WED"; }
	else if (a % 7 == 4) { cout << "THU"; }
	else if (a % 7 == 5) { cout << "FRI"; }
	else if (a % 7 == 6) { cout << "SAT"; }
	else if (a % 7 == 0) { cout << "SUN"; }
}
int main() {
	int a, b;
	cin >> a >> b;
	a = converter(a, b);
	day(a);
	return 0;
}