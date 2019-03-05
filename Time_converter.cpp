#include<iostream>
using namespace std;
void convert_time(int num);

void main() {
	int num;
	cout << "초를 입력해 주세요. 시간을 변환해 줄게요:   ";
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