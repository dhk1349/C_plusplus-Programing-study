#include<iostream>
#include<cmath>
using namespace std;
void primefind(int a);
int divisorfind(int a, int& count);
//입력 값 A가 두 소수의 곱으로 나타내질 수 있으면 출력, 불가능하면 IMPOSSIBLE출력.
void main() {
	int a;
	cout << "Type -9 to exit!\n";
	while (true) {
		cin >> a;
		if (a == -9) {
			break;
		}
		primefind(a);
	}
}

void primefind(int a) {
	int count = 0;
	int div=divisorfind(a, count);
	if (count==1) {
		cout << div << " " << (a / div) << endl;
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
}
int divisorfind(int a, int& count) {//sqrt(a)까지만 돌려서 하나만 나오면 가능, 0개이거나 하나 이상이면 불가능이다.
	int div = -999;
	for (int i = 2;(i<sqrt(a));i++) {
		if (a%i==0) {//나누어 떨어짐
			count += 1;
			div = i;
		}
	}
	return div;
}