#include<iostream>
#include<string>
using namespace std;
string check_num(int num1, int num2);
/*
Check numbers
*/
void main() {
	int num1, num2;
	cout << "num1: ";
	cin >> num1;
	cout << "num2:  ";
	cin >> num2;
	cout << check_num(num1, num2)<<"\n\n\n";

}
string check_num(int num1, int num2) {
	string result="Error";
	if(num1>num2){
		result = "false";
	}
	else if (num1<num2) {
		result = "true";
	}
	else if (num1==num2) {
		result = "-1";
	}
	else {
		cout << "unexpected case";
	}

	return result;
}
