#include<iostream>
using namespace std;
int fact(int num);

void main() {
	int a;
	cin >> a;
	cout<<fact(a)<<endl;
}

int fact(int num) {
	for (int i = num-1;i>=1;i--) {
		num *= i;
	}
	return num;
}