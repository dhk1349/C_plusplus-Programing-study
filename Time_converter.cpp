#include<iostream>
using namespace std;
void convert_time(int num);

void main() {
	int num;
	cout << "�ʸ� �Է��� �ּ���. �ð��� ��ȯ�� �ٰԿ�:   ";
	cin >> num;
	convert_time(num);
}

void convert_time(int num) {
	int hr, min, sec;
	sec = num;

	min = num / 60;
	sec %= 60;

	hr = min / 60;
	min %= 60;
	cout << "Converted time:  " << hr << "hours " << min << "minutes " << sec << "seconds" << endl;
}