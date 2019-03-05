#include<iostream>
using namespace std;

int less_than_one(int num);
int rest(int num);
/*
Add all numbers from 1 to input number
 */
void main() {
	int num;
	cout << "Type an integer:    ";
	cin >> num;
	if (num < 1) {
		cout <<"Sum is:   "<< less_than_one(num)<<endl;
	}
	else if(num >= 1) {
		cout <<"Sum is:   "<< rest(num) << endl;
	}
	else {
		cout <<"Error: Unexpecter case!!" << endl;
	}
}

int less_than_one(int num) {
	int sum = 0;
	for (int i=num;i<=1;i++) {
		sum += i;
	}
	return sum;
}

int rest(int num) {
	int sum = 0;
	for (int i=1;i<=num;i++) {
		sum += i;
	}
	return sum;
}
